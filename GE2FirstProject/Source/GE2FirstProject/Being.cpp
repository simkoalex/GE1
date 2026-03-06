// Fill out your copyright notice in the Description page of Project Settings.


#include "Being.h"

#include <cassert>

#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


void ABeing::MyActionPressed()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyActionPressed"));
	Dancing = !Dancing;
}

void ABeing::MyActionReleased()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyActionReleased"));
}

void ABeing::MyActionRepeat()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyActionRepeat"));
}

void ABeing::MyACtionDoubleClicked()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyACtionDoubleClicked"));
}

void ABeing::MyAxis(float AxisValue)
{
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("MyAxis: %f"), AxisValue));
}

// Sets default values
ABeing::ABeing()
{
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(GetRootComponent());
	
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABeing::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABeing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABeing::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	assert (PlayerInputComponent != nullptr);
	
	 FName MyActioName(TEXT("MyAction"));
	 PlayerInputComponent->BindAction(MyActioName, EInputEvent::IE_Pressed, this, &ABeing::MyActionPressed);
	
	// PlayerInputComponent->BindAction(MyActioName, EInputEvent::IE_Released, this, &ABeign::MyActionReleased);
	// PlayerInputComponent->BindAction(MyActioName, EInputEvent::IE_Repeat, this, &ABeign::MyActionRepeat);
	// PlayerInputComponent->BindAction(MyActioName, EInputEvent::IE_DoubleClick, this, &ABeign::MyACtionDoubleClicked);
	//
	// PlayerInputComponent->BindAxis(TEXT("MyAxis"), this, &ABeign::MyAxis);
}

void ABeing::Shoot()
{
	
	FVector StartLocation = GetActorLocation();
	UGameplayStatics::PlaySoundAtLocation(this, ShootSound, StartLocation);
	
	FVector ForwardVector = GetActorForwardVector();
	FVector Offset = ForwardVector * 1000.0;
	FVector EndLocation = StartLocation + Offset;
	
	TArray<AActor*> ActorsToIgnore;
	FHitResult OutHit;
	bool hit = UKismetSystemLibrary::LineTraceSingle(this, StartLocation, EndLocation, ETraceTypeQuery::TraceTypeQuery1, false, ActorsToIgnore, EDrawDebugTrace::None, OutHit, true);
}

