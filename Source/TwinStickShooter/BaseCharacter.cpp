// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
}

void ABaseCharacter::CalculateHealth(float Delta)
{
	Health += Delta;
	CalculateDead();
}

void ABaseCharacter::CalculateDead()
{
	if (Health <= 0.0f)
	{
		bIsDead = true;
	}
	else
	{
		bIsDead = false;
	}
}

#if WITH_EDITOR
void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	bIsDead = false;
	Health = 100;

	Super::PostEditChangeProperty(PropertyChangedEvent);

	CalculateDead();
}
#endif
