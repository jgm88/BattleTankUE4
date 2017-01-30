// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingComponent::AimAt(const FVector* HitLocation, float LaunchSpeed)
{
	//FString OurTankName = GetOwner()->GetName();
	//FString BarrelLocation = Barrel->GetComponentLocation().ToString();
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s from %s"), *OurTankName, *(HitLocation->ToString()), *BarrelLocation)
	//UE_LOG(LogTemp, Warning, TEXT("LaunchSpeed is: %f"), LaunchSpeed)

	if (!Barrel) return;

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Calculate the out launch velocity
	bool IsVelocityCalculated = UGameplayStatics::SuggestProjectileVelocity(
		this,				// WorldContextObject
		OutLaunchVelocity,	// TossVelocity
		StartLocation,		// StartLocation
		*HitLocation,		// EndLocation
		LaunchSpeed,		// TossSpeed
		false,				// bHighArc
		0,					// CollisionRadius
		0,					// OverrideGravityZ
		ESuggestProjVelocityTraceOption::DoNotTrace	// TraceOption
	);

	if (IsVelocityCalculated)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		FString TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *TankName, *AimDirection.ToString())
	}
}

void UTankAimingComponent::SetBarrel(UStaticMeshComponent* Barrel)
{
	this->Barrel = Barrel;
}

