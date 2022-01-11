// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryGameMode.h"
#include "GameFramework/Actor.h"

ABatteryGameMode::ABatteryGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABatteryGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, 
		&ABatteryGameMode::SpawnPlayerRecharge, FMath::RandRange(2, 5), true);
}

void ABatteryGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABatteryGameMode::SpawnPlayerRecharge()
{
	float RandX = FMath::RandRange(Spawn_Min_X, Spawn_Max_X);
	float RandY = FMath::RandRange(Spawn_Min_Y, Spawn_Max_Y);

	FVector SpawnPosition = FVector(RandX, RandY, SpawnZ);
	FRotator SpawnRotation = FRotator(0.f, 0.f, 0.f);

	GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);
}
