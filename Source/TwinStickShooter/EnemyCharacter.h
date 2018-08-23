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

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	virtual void AffectHealth(float Delta) override;

private:
	void DamageTheHero() const;

	UFUNCTION()
	void DestroyEnemy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* DamageVolume;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ExplosionActorClass = nullptr;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float Damage = -20.0f;

	UPROPERTY(EditAnywhere)
	float AttacksPerSecond = 2.0f;

	UPROPERTY(EditAnywhere)
	int32 Score = 500;

	TWeakObjectPtr<class AHeroCharacter> Hero;
	FTimerHandle DamageTheHeroTimerHandle;
	FTimerHandle DestroyTimerHandle;
};
