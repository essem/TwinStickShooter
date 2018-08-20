// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class TWINSTICKSHOOTER_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AEnemySpawner();

	UFUNCTION()
	void SpawnEnemy();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* SpawnVolume;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AEnemyCharacter> EnemyCharacterClass;

	// The maximum number of enemies allowed by this spawner
	UPROPERTY(EditAnywhere)
	int32 MaxEnemies = 4;
};
