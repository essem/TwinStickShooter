// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damageable.generated.h"

UINTERFACE(meta = (CannotImplementInterfaceInBlueprint))
class UDamageable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IDamageable : public IInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void AffectHealth(float Delta) = 0;
};
