// Fill out your copyright notice in the Description page of Project Settings.

#include "HeroCharacter.h"
#include "Components/ArrowComponent.h"
#include "Weapon.h"
#include "TwinStickMode.h"

AHeroCharacter::AHeroCharacter()
{
	GunTemp = CreateDefaultSubobject<UArrowComponent>(TEXT("GunTemp"));
	GunTemp->SetupAttachment(RootComponent);

	Tags.Add(FName("Friendly"));
}

void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Weapon Setup
	const FTransform& SpawnTransform = GunTemp->GetComponentToWorld();
	Weapon = CastChecked<AWeapon>(GetWorld()->SpawnActor(WeaponClass, &SpawnTransform));

	Weapon->AttachToComponent(GunTemp, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	// Spawn Transform up to GameMode
	GameMode = GetWorld()->GetAuthGameMode<ATwinStickMode>();
	check(GameMode);

	GameMode->SetPlayerSpawnTransform(GetActorTransform());
}

void AHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveUp"), this, &AHeroCharacter::OnInputAxisMoveUp);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &AHeroCharacter::OnInputAxisMoveRight);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AHeroCharacter::OnInputAxisLookUp);
	PlayerInputComponent->BindAxis(FName("LookRight"), this, &AHeroCharacter::OnInputAxisLookRight);
}

void AHeroCharacter::OnInputAxisMoveUp(float Value)
{
	AddMovementInput(FVector::ForwardVector, Value);
}

void AHeroCharacter::OnInputAxisMoveRight(float Value)
{
	AddMovementInput(FVector::RightVector, Value);
}

void AHeroCharacter::OnInputAxisLookUp(float Value)
{
	LookUpValue = Value;
	UpdateRotation();
}

void AHeroCharacter::OnInputAxisLookRight(float Value)
{
	LookRightValue = Value;
	UpdateRotation();
}

void AHeroCharacter::UpdateRotation()
{
	FVector Direction(LookUpValue, LookRightValue, 0.0f);
	if (Direction.Size() > 0.25f)
	{
		GetController()->SetControlRotation(Direction.Rotation());
		Weapon->PullTrigger();
	}
	else
	{
		Weapon->ReleaseTrigger();
	}
}

void AHeroCharacter::AffectHealth(float Delta)
{
	CalculateHealth(Delta);

	if (IsDead())
	{
		GameMode->RespawnPlayer();
		Destroy();
		Weapon->Destroy();
	}
}
