// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"

//////////////////////////////////////////////////////////////////////////
// UE LIVE CIRCLE
//////////////////////////////////////////////////////////////////////////


ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::SetBarrel(UTankBarrel * Barrel)
{
	TankAimingComponent->SetBarrel(Barrel);
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(&HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
}

