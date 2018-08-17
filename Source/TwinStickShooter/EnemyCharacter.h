// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Damageable.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class TWINSTICKSHOOTER_API AEnemyCharacter : public ABaseCharacter, public IDamageable
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	virtual void AffectHealth(float Delta) override;
};
