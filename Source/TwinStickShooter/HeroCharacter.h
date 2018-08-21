// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Damageable.h"
#include "HeroCharacter.generated.h"

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API AHeroCharacter : public ABaseCharacter, public IDamageable
{
	GENERATED_BODY()

public:
	AHeroCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void AffectHealth(float Delta) override;

protected:
	virtual void BeginPlay() override;

private:
	void OnInputAxisMoveUp(float Value);
	void OnInputAxisMoveRight(float Value);
	void OnInputAxisLookUp(float Value);
	void OnInputAxisLookRight(float Value);

	void UpdateRotation();

	UFUNCTION()
	void RespawnPlayer();

	UPROPERTY(EditAnywhere)
	class TSubclassOf<class AWeapon> WeaponClass;

	UPROPERTY()
	class ATwinStickMode* GameMode;

	UPROPERTY()
	class AWeapon* Weapon;

	float LookUpValue = 0.0f;
	float LookRightValue = 0.0f;
	FTimerHandle RespawnTimerHandle;
};
