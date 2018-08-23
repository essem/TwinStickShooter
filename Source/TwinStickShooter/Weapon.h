// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class TWINSTICKSHOOTER_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

	void PullTrigger();
	void ReleaseTrigger();

private:
	void Fire();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* GunMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UArrowComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere)
	class TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere)
	class USoundBase* FireSound = nullptr;

	UPROPERTY(EditAnywhere)
	float RoundsPerSecond = 5.0f;

	bool bInFiring = false;
	FTimerHandle FireTimerHandle;
};
