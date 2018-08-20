// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawner.h"
#include "Components/BoxComponent.h"
#include "EnemyCharacter.h"
#include "EngineUtils.h"

AEnemySpawner::AEnemySpawner()
{
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	RootComponent = SpawnVolume;
}

void AEnemySpawner::SpawnEnemy()
{
	int32 NumEnemies = 0;
	for (TActorIterator<AEnemyCharacter> It(GetWorld(), AEnemyCharacter::StaticClass()); It; ++It)
	{
		AEnemyCharacter* EnemyCharacter = *It;

		if (IsValid(EnemyCharacter))
		{
			++NumEnemies;
		}
	}

	if (NumEnemies >= MaxEnemies)
	{
		return;
	}

	const FVector BoxExtent = SpawnVolume->GetScaledBoxExtent();
	const FVector Origin = SpawnVolume->GetComponentLocation();

	const FVector BoxMin = Origin - BoxExtent;
	const FVector BoxMax = Origin + BoxExtent;
	const FVector SpawnPoint = FMath::RandPointInBox(FBox(BoxMin, BoxMax));

	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	AEnemyCharacter* EnemyCharacter = GetWorld()->SpawnActor<AEnemyCharacter>(EnemyCharacterClass, SpawnPoint, FRotator::ZeroRotator, ActorSpawnParams);

	if (EnemyCharacter && !EnemyCharacter->Controller)
	{
		EnemyCharacter->SpawnDefaultController();
	}
}
