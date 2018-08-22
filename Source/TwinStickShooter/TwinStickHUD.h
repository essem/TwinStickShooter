// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TwinStickHUD.generated.h"

UCLASS(Abstract)
class TWINSTICKSHOOTER_API UTwinStickHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	float GetHealthBarPercent();

	UFUNCTION()
	FText GetScoreText();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	class UProgressBar* HealthBarWidget = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	class UTextBlock* ScoreWidget = nullptr;
};
