// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAI.generated.h"

UCLASS()
class TWINSTICKSHOOTER_API AEnemyAI : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void TrackPlayer();

	FTimerHandle TrackPlayerTimerHandle;
};
