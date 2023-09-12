// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalObject.h"

APortalObject::APortalObject()
{
	Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PortalParticle"));
	Particle->SetupAttachment(DefaultBox);

	InteractionType = EInteractionType::PlayerOnly;

}

void APortalObject::BeginPlay()
{
	Super::BeginPlay();
}

void APortalObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APortalObject::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

void APortalObject::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);


	//OtherActor->AddActorWorldOffset(FVector(100.0, 100.0, 0.0));

	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("Begin OverLap Dest : %s"), *OtherActor->GetName()));
}
