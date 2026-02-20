#pragma once

#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "SpinningActor.generated.h"

UCLASS()
class ASpinningActor : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SubMeshComponent;
	
	UPROPERTY(EditAnywhere)
	URotatingMovementComponent *MovementComponent;
	
public:
	ASpinningActor();
	
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
};