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

private:
	FTransform PlayerSpawnTransform;
};
