// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include <cassert>
#include "Kismet/KismetSystemLibrary.h"

void AMyPlayerController::MyActionPressed()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyActionPressed"));
}

void AMyPlayerController::MyActionReleased()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyActionReleased"));
}

void AMyPlayerController::MyActionRepeat()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyActionRepeat"));
}

void AMyPlayerController::MyACtionDoubleClicked()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyACtionDoubleClicked"));
}

void AMyPlayerController::MyAxis(float AxisValue)
{
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("MyAxis: %f"), AxisValue));
}


void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	assert (InputComponent != nullptr);
	
	// FName MyActioName(TEXT("MyAction"));
	//
	// InputComponent->BindAction(MyActioName, EInputEvent::IE_Pressed, this, &AMyPlayerController::MyActionPressed);
	// InputComponent->BindAction(MyActioName, EInputEvent::IE_Released, this, &AMyPlayerController::MyActionReleased);
	// InputComponent->BindAction(MyActioName, EInputEvent::IE_Repeat, this, &AMyPlayerController::MyActionRepeat);
	// InputComponent->BindAction(MyActioName, EInputEvent::IE_DoubleClick, this, &AMyPlayerController::MyACtionDoubleClicked);
	//
	// InputComponent->BindAxis(TEXT("MyAxis"), this, &AMyPlayerController::MyAxis);
}
