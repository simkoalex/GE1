// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Being.generated.h"

UCLASS()
class GE2FIRSTPROJECT_API ABeing : public ACharacter
{
	GENERATED_BODY()

	void MyActionPressed();
	void MyActionReleased();
	void MyActionRepeat();
	void MyACtionDoubleClicked();
	
	void MyAxis(float AxisValue);
	
public:
	// Sets default values for this pawn's properties
	ABeing();

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;
	
	UPROPERTY(VisibleAnywhere)
	bool Dancing;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase *ShootSound;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	void Shoot();
};
