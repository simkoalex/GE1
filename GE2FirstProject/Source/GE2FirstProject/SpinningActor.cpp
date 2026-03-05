#include "SpinningActor.h"

#include "Kismet/KismetSystemLibrary.h"

ASpinningActor::ASpinningActor() :
	StaticMeshComponent(nullptr),
	SubMeshComponent(nullptr),
	NumberOfSpins(0),
	LastYaw(0),
	Threshold(0)
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(StaticMeshComponent);

	UStaticMesh *CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube"));
	StaticMeshComponent->SetStaticMesh(CubeMesh);
	
	SubMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SubMeshComponent"));
	SubMeshComponent->SetupAttachment(StaticMeshComponent);
	
	UStaticMesh *SphereMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere"));
	SubMeshComponent->SetStaticMesh(SphereMesh);
	SubMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	
	MovementComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MovementComponent"));
	
	PrimaryActorTick.bCanEverTick = true;
	LastYaw = GetActorRotation().Yaw;
}


void ASpinningActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UKismetSystemLibrary::PrintString(this, TEXT("Tick"));
	
	float CurrentYaw = GetActorRotation().Yaw;
	if (CurrentYaw < LastYaw)
	{
		++NumberOfSpins;
		OnSpin();
		if (NumberOfSpins == Threshold)
		{
			OnThresholdReached();
		}
	}
	
	LastYaw = CurrentYaw;
}

void ASpinningActor::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::PrintString(this, TEXT("BeginPlay"));
}

void ASpinningActor::ResetSpinning()
{
	NumberOfSpins = 0;
	LastYaw = GetActorRotation().Yaw;
}

FString ASpinningActor::SetDescription(FString& NewDescription)
{
	return FString();
}

void ASpinningActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
	UKismetSystemLibrary::PrintString(this,
		TEXT("TH: ") + FString::FromInt(Threshold));
}

void ASpinningActor::OnThresholdReached_Implementation()
{
	UKismetSystemLibrary::PrintString(this,
		TEXT("Threshold Reached"));
}