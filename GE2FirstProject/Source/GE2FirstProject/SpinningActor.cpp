#include "SpinningActor.h"

#include "Kismet/KismetSystemLibrary.h"

ASpinningActor::ASpinningActor() :
	StaticMeshComponent(nullptr),
	SubMeshComponent(nullptr)
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
}


void ASpinningActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UKismetSystemLibrary::PrintString(this, TEXT("Tick"));
}

void ASpinningActor::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::PrintString(this, TEXT("BeginPlay"));
}
