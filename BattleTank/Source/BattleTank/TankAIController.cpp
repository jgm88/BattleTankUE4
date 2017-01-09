// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PlayerTank = GetPlayerTank();

	if (!PlayerTank)
		UE_LOG(LogTemp, Warning, TEXT("AI Controller playerTank doesn't founded"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Found %s"), *(PlayerTank->GetName()))


}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	APawn * PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) return nullptr;

	return Cast<ATank>(PlayerPawn);
}


