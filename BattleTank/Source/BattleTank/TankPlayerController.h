// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //  Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

	//////////////////////////////////////////////////////////////////////////
	// UE LIVE CIRCLE
	//////////////////////////////////////////////////////////////////////////

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//////////////////////////////////////////////////////////////////////////
	// CONTROLLER MANAGEMENT
	//////////////////////////////////////////////////////////////////////////

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

	void AimTowardsCrossAir();

	// Get world location of linetrace through crosshair, true if hits landscape
	bool GetSightRayHitLocation(FVector & HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;
	bool GetLookVectorHitLocation(const FVector& LookDirection, FVector& HitLocation) const;

	//////////////////////////////////////////////////////////////////////////
	// EXTERNAL ACCESS 
	//////////////////////////////////////////////////////////////////////////

	ATank * GetControlledTank() const;
	
};
