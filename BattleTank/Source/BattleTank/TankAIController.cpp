// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

//////////////////////////////////////////////////////////////////////////
// UE LIVE CIRCLE
//////////////////////////////////////////////////////////////////////////

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PlayerTank = GetPlayerTank();

	if (!PlayerTank)
		UE_LOG(LogTemp, Warning, TEXT("AI Controller playerTank doesn't founded"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Found %s"), *(PlayerTank->GetName()))


}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards to the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if it is ready
	}
}


//////////////////////////////////////////////////////////////////////////
// INTERNAL ACCESS 
//////////////////////////////////////////////////////////////////////////

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

//////////////////////////////////////////////////////////////////////////
// EXTERNAL ACCESS 
//////////////////////////////////////////////////////////////////////////

ATank * ATankAIController::GetPlayerTank() const
{
	APawn * PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) return nullptr;

	return Cast<ATank>(PlayerPawn);
}


