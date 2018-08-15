// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "HeroCharacter.generated.h"

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API AHeroCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AHeroCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	void OnInputAxisMoveUp(float Value);
	void OnInputAxisMoveRight(float Value);
	void OnInputAxisLookUp(float Value);
	void OnInputAxisLookRight(float Value);

	void UpdateRotation();

	UPROPERTY(EditAnywhere)
	class TSubclassOf<class AWeapon> WeaponClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UArrowComponent* GunTemp;

	UPROPERTY()
	class AWeapon* Weapon;

	float LookUpValue = 0.0f;
	float LookRightValue = 0.0f;
};
