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
// AIM MANAGEMENT 
//////////////////////////////////////////////////////////////////////////

void ATankPlayerController::AimTowardsCrossAir()
{
	if (GetControlledTank())
	{
		FVector HitLocation;
		if (GetSightRayHitLocation(HitLocation))
		{
			GetControlledTank()->AimAt(HitLocation);
		}
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	// Find the crosshair in pixel coordinates 
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	FVector LookDirection;
	if(GetLookDirection(ScreenLocation, LookDirection))
	{
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	// Line-trace along that LookDirection, and see what we hit (up to max range)

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	// Deproject the screen position of the crosshair to a world direction
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(const FVector& LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
	bool IsLineTraceSuccessful = GetWorld()->LineTraceSingleByChannel(
		HitResult, 
		StartLocation, EndLocation,
		ECollisionChannel::ECC_Visibility
	);
	if (IsLineTraceSuccessful)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

//////////////////////////////////////////////////////////////////////////
// EXTERNAL ACCESS
//////////////////////////////////////////////////////////////////////////

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
