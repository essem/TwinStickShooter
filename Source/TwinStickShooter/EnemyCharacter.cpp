// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnemyAI.h"

AEnemyCharacter::AEnemyCharacter()
{
	AIControllerClass = AEnemyAI::StaticClass();

	GetCharacterMovement()->MaxWalkSpeed = 200.0f;
}
