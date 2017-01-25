// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

private:
	// Sets default values for this pawn's properties
	ATank();

	//////////////////////////////////////////////////////////////////////////
	// UE LIVE CIRCLE
	//////////////////////////////////////////////////////////////////////////

	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

};
