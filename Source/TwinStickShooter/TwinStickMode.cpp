// Fill out your copyright notice in the Description page of Project Settings.

#include "TwinStickMode.h"
#include "HeroCharacter.h"

ATwinStickMode::ATwinStickMode()
{
}

void ATwinStickMode::RespawnPlayer()
{
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
