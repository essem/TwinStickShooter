// Fill out your copyright notice in the Description page of Project Settings.

#include "TwinStickMode.h"
#include "HeroCharacter.h"
#include "EnemyCharacter.h"
#include "EngineUtils.h"
#include "EnemySpawner.h"

ATwinStickMode::ATwinStickMode()
{
}

void ATwinStickMode::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<AEnemySpawner> It(GetWorld(), AEnemySpawner::StaticClass()); It; ++It)
	{
		AEnemySpawner* Spawner = *It;

		if (IsValid(Spawner))
		{
			FTimerHandle SpawnEnemyTimerHandle;
			float Rate = 1 / EnemiesPerSecond;
			bool bLoop = true;
			GetWorld()->GetTimerManager().SetTimer(SpawnEnemyTimerHandle, Spawner, &AEnemySpawner::SpawnEnemy, Rate, bLoop);
		}
	}
}

void ATwinStickMode::RespawnPlayer()
{
	for (TActorIterator<AEnemyCharacter> It(GetWorld(), AEnemyCharacter::StaticClass()); It; ++It)
	{
		AEnemyCharacter* EnemyCharacter = *It;

		if (IsValid(EnemyCharacter))
		{
			EnemyCharacter->Destroy();
		}
	}

	AHeroCharacter* HeroCharacter = GetWorld()->SpawnActor<AHeroCharacter>(DefaultPawnClass, PlayerSpawnTransform);

	if (!ensure(HeroCharacter))
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (!ensure(PlayerController))
	{
		return;
	}

	PlayerController->Possess(HeroCharacter);
}

void ATwinStickMode::IncrementScore(int32 DeltaScore)
{
	Score += DeltaScore;
}
