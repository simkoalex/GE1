// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLevelActor.h"

#include "SpinningActor.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

AMyLevelActor::AMyLevelActor() :
	SpinningActorClass(nullptr)
{
}

void AMyLevelActor::MyFunction()
{
	//UKismetSystemLibrary::PrintString(this, TEXT("PrintString from C++ Level Actor"));
}

void AMyLevelActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (SpinningActorClass)
	{
		FTransform Transform;
		Transform.SetTranslation(FVector(0, 0, 50));
		if (ASpinningActor *Actor = GetWorld()->SpawnActorDeferred<ASpinningActor>(
			SpinningActorClass,
			Transform
		))
		{
			Actor->Threshold = 6;
			UGameplayStatics::FinishSpawningActor(Actor, Transform);
		}
	}
}
