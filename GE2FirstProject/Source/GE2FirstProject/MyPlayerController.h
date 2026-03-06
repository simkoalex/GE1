// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

UCLASS()
class GE2FIRSTPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	void MyActionPressed();
	void MyActionReleased();
	void MyActionRepeat();
	void MyACtionDoubleClicked();
	
	void MyAxis(float AxisValue);
	
protected:
	virtual void SetupInputComponent() override;
};
