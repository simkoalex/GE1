// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "UObject/Object.h"
#include "SpinningActor.h"
#include "MyLevelActor.generated.h"

/**
 * 
 */
UCLASS()
class GE2FIRSTPROJECT_API AMyLevelActor : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ASpinningActor> SpinningActorClass;
	
	AMyLevelActor();
	
	UFUNCTION(BlueprintCallable)
	void MyFunction();
	
	virtual void BeginPlay() override;
};
