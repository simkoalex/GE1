// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"

UCLASS()
class GE1SECONDPART_API ABaseActor : public AActor
{
	GENERATED_BODY()

protected:
	virtual float InternalTakePointDamage(float Damage, struct FPointDamageEvent const& PointDamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	
public:	
	ABaseActor();
	
	
	UFUNCTION(BlueprintNativeEvent)
	float DoTakePointDamage(
		float Damage, UDamageType const * const DamageType,
		FVector const& ShotDirection, FHitResult const &HitREsult,
		AController * EventInstigator, AActor * DamageCauser
	);


};
