// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Components/SphereComponent.h"
#include "Engine/CollisionProfile.h"
#include "GameFramework/ProjectileMovementComponent.h"

AProjectile::AProjectile()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(10.0f);

	LaserMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserMesh"));
	LaserMesh->SetupAttachment(RootComponent);
	LaserMesh->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> LaserMeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (LaserMeshAsset.Succeeded())
	{
		LaserMesh->SetStaticMesh(LaserMeshAsset.Object);
		LaserMesh->SetWorldScale3D(FVector(0.2f));
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> LaserMeshMaterialAsset(TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));
	if (LaserMeshMaterialAsset.Succeeded())
	{
		LaserMesh->SetMaterial(0, LaserMeshMaterialAsset.Object);
	}

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = RootComponent;
	ProjectileMovement->InitialSpeed = 1200.0f;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

}
