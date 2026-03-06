// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "Being.h"

bool UMyAnimInstance::CanTakeIdleToDancing() const
{
	return Dancing;
}

bool UMyAnimInstance::CanTakeDancingToIdle() const
{
	return !Dancing;
}

void UMyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	FName IdleStateName(TEXT("Idle"));
	FName DancingStateName(TEXT("Dancing"));
	
	FCanTakeTransition CanTakeIdleToDancing;
	CanTakeIdleToDancing.BindUObject(this, &UMyAnimInstance::CanTakeIdleToDancing);
	AddNativeTransitionBinding(StateMachineName, IdleStateName, DancingStateName, CanTakeIdleToDancing);
	
	FCanTakeTransition CanTakeDancingToIdle;
	CanTakeDancingToIdle.BindUObject(this, &UMyAnimInstance::CanTakeDancingToIdle);
	AddNativeTransitionBinding(StateMachineName, DancingStateName, IdleStateName, CanTakeDancingToIdle);
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	ABeing *Being = Cast<ABeing>(TryGetPawnOwner());
	if (Being == nullptr)
	{
		return;
	}
	
	Dancing = Being->Dancing;
}
