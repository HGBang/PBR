// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractionObject.h"
#include "PortalObject.generated.h"

/**
 * 
 */
UCLASS()
class PBR_API APortalObject : public AInteractionObject
{
	GENERATED_BODY()

public:
	APortalObject();	

protected:
	UPROPERTY(Category = Component, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UParticleSystemComponent>	Particle;

	UPROPERTY(Category = Component, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FName	mransitionName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;



private:
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
