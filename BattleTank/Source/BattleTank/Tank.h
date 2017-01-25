// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

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
	void SetBarrel(UStaticMeshComponent* Barrel);

protected:

	UTankAimingComponent* TankAimingComponent = nullptr;

private:

	//////////////////////////////////////////////////////////////////////////
	// UE LIVE CIRCLE
	//////////////////////////////////////////////////////////////////////////
	ATank();

	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

};
