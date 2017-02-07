// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float RelativeSpeed);
	void Rotate(float RelativeSpeed);
	
private:


	//////////////////////////////////////////////////////////////////////////
	// ELEVATION
	//////////////////////////////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegreesPerSecond = 20.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees= 40.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 00.f;

	//////////////////////////////////////////////////////////////////////////
	// ROTATION
	//////////////////////////////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxRotationDegreesPerSecond = 20.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxRotationDegrees = 40.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinRotationDegrees = 00.f;
};
