// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	//////////////////////////////////////////////////////////////////////////
	// UE LIVE CIRCLE
	//////////////////////////////////////////////////////////////////////////

	UTankAimingComponent();

	virtual void BeginPlay() override;
	
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void AimAt(const FVector* HitLocation, float LaunchSpeed);

	void SetBarrel(UTankBarrel* Barrel);

private:

	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(const FVector * AimDirection);
};
