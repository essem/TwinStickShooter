// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnemyAI.h"
#include "HeroCharacter.h"

AEnemyCharacter::AEnemyCharacter()
{
	DamageVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageVolume"));
	DamageVolume->SetupAttachment(RootComponent);

	AIControllerClass = AEnemyAI::StaticClass();

	GetCharacterMovement()->MaxWalkSpeed = 200.0f;
}

void AEnemyCharacter::AffectHealth(float Delta)
{
	CalculateHealth(Delta);

	if (IsDead())
	{
		Destroy();
	}
}

void AEnemyCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	AHeroCharacter* HeroCharacter = Cast<AHeroCharacter>(OtherActor);

	if (!HeroCharacter)
	{
		return;
	}

	Hero = HeroCharacter;

	bool bLoop = true;
	float Rate = 1.0f / AttacksPerSecond;

	GetWorld()->GetTimerManager().SetTimer(DamageTheHeroTimerHandle, this, &AEnemyCharacter::DamageTheHero, Rate, bLoop);
}

void AEnemyCharacter::DamageTheHero() const
{
	if (Hero.IsValid())
	{
		Hero->AffectHealth(Damage);
	}
}

void AEnemyCharacter::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	if (OtherActor == Hero)
	{
		GetWorld()->GetTimerManager().ClearTimer(DamageTheHeroTimerHandle);
	}
}
