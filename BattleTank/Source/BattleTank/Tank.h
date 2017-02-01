// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	//////////////////////////////////////////////////////////////////////////
	// AIM MANAGEMENT
	//////////////////////////////////////////////////////////////////////////

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrel(UTankBarrel* Barrel);

protected:

	UTankAimingComponent* TankAimingComponent = nullptr;

private:

	//////////////////////////////////////////////////////////////////////////
	// UE LIVE CIRCLE
	//////////////////////////////////////////////////////////////////////////
	ATank();

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.f; // TODO Find sensible default
};
