// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAI.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();

	float Rate = 1.0f;
	bool bLoop = true;
	GetWorld()->GetTimerManager().SetTimer(TrackPlayerTimerHandle, this, &AEnemyAI::TrackPlayer, Rate, bLoop);

}

void AEnemyAI::TrackPlayer()
{
	ACharacter* Goal = UGameplayStatics::GetPlayerCharacter(this, 0);
	float AcceptanceRadius = 5.0f;
	bool bStopOnOverlap = true;
	MoveToActor(Goal, AcceptanceRadius, bStopOnOverlap);
}
