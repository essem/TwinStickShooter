// Fill out your copyright notice in the Description page of Project Settings.

#include "TwinStickHUD.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "BaseCharacter.h"
#include "TwinStickMode.h"

void UTwinStickHUD::NativeConstruct()
{
	Super::NativeConstruct();

	HealthBarWidget->PercentDelegate.BindDynamic(this, &UTwinStickHUD::GetHealthBarPercent);
	HealthBarWidget->SynchronizeProperties();

	ScoreWidget->TextDelegate.BindDynamic(this, &UTwinStickHUD::GetScoreText);
	ScoreWidget->SynchronizeProperties();
}

float UTwinStickHUD::GetHealthBarPercent()
{
	ABaseCharacter* Character = Cast<ABaseCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (!ensure(Character))
	{
		return 0.0f;
	}

	return Character->GetHealth() / 100.0f;
}

FText UTwinStickHUD::GetScoreText()
{
	ATwinStickMode* GameMode = GetWorld()->GetAuthGameMode<ATwinStickMode>();

	if (!ensure(GameMode))
	{
		return FText();
	}

	return FText::AsNumber(GameMode->GetScore());
}
