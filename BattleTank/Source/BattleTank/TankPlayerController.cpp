// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

//////////////////////////////////////////////////////////////////////////
// UE LIVE CIRCLE
//////////////////////////////////////////////////////////////////////////

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();

	if(!ControlledTank) 
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller not possesing a Tank"))


}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossAir();
}

//////////////////////////////////////////////////////////////////////////
// CONTROLLER MANAGEMENT 
//////////////////////////////////////////////////////////////////////////

void ATankPlayerController::AimTowardsCrossAir()
{
	if (GetControlledTank())
	{
		FVector HitLocation;
		if(GetSightRayHitLocation(HitLocation))
		UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *HitLocation.ToString())
		return;
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	// Find the crosshair
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	return false;
}

//////////////////////////////////////////////////////////////////////////
// EXTERNAL ACCESS
//////////////////////////////////////////////////////////////////////////

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
