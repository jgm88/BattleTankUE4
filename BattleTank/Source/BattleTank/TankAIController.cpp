// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();

	if (!ControlledTank)
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possesing a Tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AI Controller controlling %s"), *(ControlledTank->GetName()))


}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


