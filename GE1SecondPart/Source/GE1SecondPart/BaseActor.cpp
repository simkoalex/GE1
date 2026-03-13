// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseActor.h"

#include "Engine/DamageEvents.h"

float ABaseActor::InternalTakePointDamage(float Damage, struct FPointDamageEvent const& PointDamageEvent,
                                          class AController* EventInstigator, AActor* DamageCauser)
{
	UDamageType const *DamageTypeInstance = PointDamageEvent.DamageTypeClass
		? PointDamageEvent.DamageTypeClass->GetDefaultObject<UDamageType>()
		: GetDefault<UDamageType>();

	return DoTakePointDamage(Damage, DamageTypeInstance,
		PointDamageEvent.ShotDirection, PointDamageEvent.HitInfo, EventInstigator, DamageCauser);
}

// Sets default values
ABaseActor::ABaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float ABaseActor::DoTakePointDamage_Implementation(float Damage, UDamageType const* const DamageType,
	FVector const& ShotDirection, FHitResult const& HitREsult, AController* EventInstigator, AActor* DamageCauser)
{
	return Damage;
}
