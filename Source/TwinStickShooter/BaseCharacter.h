// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void SetHealth(float InHealth) { Health = InHealth; }

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	bool IsDead() const { return bIsDead; }

protected:
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	virtual void CalculateHealth(float Delta);

private:
	virtual void CalculateDead();

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	float Health = 100.0f;
	bool bIsDead = false;
};
