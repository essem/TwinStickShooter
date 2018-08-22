// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TwinStickMode.generated.h"

UCLASS()
class TWINSTICKSHOOTER_API ATwinStickMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATwinStickMode();

	void SetPlayerSpawnTransform(const FTransform& SpawnTransform) { PlayerSpawnTransform = SpawnTransform; }
	void RespawnPlayer();

	void IncrementScore(int32 DeltaScore);
	int32 GetScore() const { return Score; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	float EnemiesPerSecond = 2.0f;

	FTransform PlayerSpawnTransform;
	int32 Score = 0;
};
