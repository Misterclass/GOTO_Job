// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BatteryGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BATTERY_COLLECTOR_API ABatteryGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABatteryGameMode();

protected:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<APawn> PlayerRecharge;

	float SpawnZ = 500.f;

	UPROPERTY(EditAnywhere)
		float Spawn_Min_X;

	UPROPERTY(EditAnywhere)
		float Spawn_Max_X;

	UPROPERTY(EditAnywhere)
		float Spawn_Min_Y;

	UPROPERTY(EditAnywhere)
		float Spawn_Max_Y;

	void SpawnPlayerRecharge();
};
