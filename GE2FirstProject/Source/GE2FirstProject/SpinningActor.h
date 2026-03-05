#pragma once

#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "SpinningActor.generated.h"

UCLASS(Blueprintable)
class ASpinningActor : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SubMeshComponent;
	
	UPROPERTY(EditAnywhere)
	URotatingMovementComponent *MovementComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Spinning|A", meta=(AllowPrivateAccess="True"))
	int NumberOfSpins;
	
	float LastYaw;
	
public:
	ASpinningActor();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spinning|B", DisplayName="My Threshold", meta=(ExposeOnSpawn = true))
	int Threshold;
	
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnSpin();

	UFUNCTION(BlueprintNativeEvent)
	void OnThresholdReached();
	
	UFUNCTION(BlueprintCallable)
	void ResetSpinning();
	
	UFUNCTION(BlueprintCallable)
	FString SetDescription(UPARAM(ref) FString &NewDescription);

	virtual void OnConstruction(const FTransform& Transform) override;
};