// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Projectile.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

AWeapon::AWeapon()
{
	USceneComponent* DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	GunMesh->SetupAttachment(RootComponent);

	ProjectileSpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("ProjectileSpawnPoint"));
	ProjectileSpawnPoint->SetupAttachment(GunMesh);
}

void AWeapon::PullTrigger()
{
	if (bInFiring)
	{
		return;
	}

	bInFiring = true;

	bool bLoop = true;
	float Rate = 1.0f / RoundsPerSecond;

	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &AWeapon::Fire, Rate, bLoop);
}

void AWeapon::ReleaseTrigger()
{
	bInFiring = false;

	GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);
}

void AWeapon::Fire()
{
	if (FireSound)
	{
		UGameplayStatics::SpawnSoundAttached(FireSound, GunMesh);
	}

	const FTransform& SpawnTransform = ProjectileSpawnPoint->GetComponentToWorld();
	GetWorld()->SpawnActor(ProjectileClass, &SpawnTransform);
}
