// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATank::SetTurretChildActor(UChildActorComponent * TurretFromBP)
{
	UE_LOG(LogTemp, Warning, TEXT("SetTurretChildActor called"));

	Turret = TurretFromBP;
}

void ATank::SetBarrelChildActor(UChildActorComponent * BarrelFromBP)
{
	UE_LOG(LogTemp, Warning, TEXT("SetTurretChildActor called"));

	Barrel = BarrelFromBP;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Rotate_Turret",this, &ATank::RotateTurret);
	InputComponent->BindAxis("Elevate_Barrel", this, &ATank::ElevateBarrel);
}

void ATank::RotateTurret(float Speed)
{
	if (!Turret) { return; }
	Turret->AddRelativeRotation(FRotator(0.f,Speed,0.f));
}


void ATank::ElevateBarrel(float Speed)
{
	if (!Barrel) { return; }
	Barrel->AddRelativeRotation(FRotator(Speed, 0.f, 0.f));
}