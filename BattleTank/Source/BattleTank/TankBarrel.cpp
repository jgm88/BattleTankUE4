// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"




void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	// Using negative values to fix the rotation of the imported mesh
	float ElevationChange = RelativeSpeed * MaxElevationDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Roll - ElevationChange;
	float Elevation = FMath::Clamp<float>(-RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(0, RelativeRotation.Yaw, -Elevation));
	
	UE_LOG(LogTemp, Warning, TEXT("BARREL ELEVATING %s"), *RelativeRotation.ToString())
}

void UTankBarrel::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	UE_LOG(LogTemp, Warning, TEXT("RelativeSpeed %f"), RelativeSpeed)

	// Using negative values to fix the rotation of the imported mesh
	float RotationChange = RelativeSpeed * MaxRotationDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewRotation = RelativeRotation.Yaw - RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, RelativeRotation.Roll));

	UE_LOG(LogTemp, Warning, TEXT("BARREL ROTATING %s"), *RelativeRotation.ToString())
}
