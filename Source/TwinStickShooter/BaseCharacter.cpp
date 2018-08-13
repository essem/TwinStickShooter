// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveUp"), this, &ABaseCharacter::OnInputAxisMoveUp);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ABaseCharacter::OnInputAxisMoveRight);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ABaseCharacter::OnInputAxisLookUp);
	PlayerInputComponent->BindAxis(FName("LookRight"), this, &ABaseCharacter::OnInputAxisLookRight);
}

void ABaseCharacter::OnInputAxisMoveUp(float Value)
{
	AddMovementInput(FVector::ForwardVector, Value);
}

void ABaseCharacter::OnInputAxisMoveRight(float Value)
{
	AddMovementInput(FVector::RightVector, Value);
}

void ABaseCharacter::OnInputAxisLookUp(float Value)
{
	LookUpValue = Value;
	UpdateRotation();
}

void ABaseCharacter::OnInputAxisLookRight(float Value)
{
	LookRightValue = Value;
	UpdateRotation();
}

void ABaseCharacter::UpdateRotation()
{
	FVector Direction(LookUpValue, LookRightValue, 0.0f);
	if (Direction.Size() > 0.25f)
	{
		GetController()->SetControlRotation(Direction.Rotation());
	}
}

void ABaseCharacter::CalculateHealth(float Delta)
{
	Health += Delta;
	CalculateDead();
}

void ABaseCharacter::CalculateDead()
{
	if (Health <= 0.0f)
	{
		bIsDead = true;
	}
	else
	{
		bIsDead = false;
	}
}

#if WITH_EDITOR
void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	bIsDead = false;
	Health = 100;

	Super::PostEditChangeProperty(PropertyChangedEvent);

	CalculateDead();
}
#endif
