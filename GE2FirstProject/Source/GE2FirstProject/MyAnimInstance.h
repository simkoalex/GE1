// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GE2FIRSTPROJECT_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	bool CanTakeIdleToDancing() const;
	bool CanTakeDancingToIdle() const;
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName StateMachineName;//(TEXT("DefaultMachine"));	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Dancing;
protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
