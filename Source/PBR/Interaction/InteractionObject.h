// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../GameInfo.h"
#include "GameFramework/Actor.h"
#include "InteractionObject.generated.h"

UENUM(BlueprintType)
enum class EInteractionType : uint8
{
	Default,
	PlayerOnly,
	MonsterOnly
};

UCLASS()
class PBR_API AInteractionObject : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AInteractionObject();

protected:
	UPROPERTY(Category = "InteractionBox", EditAnyWhere, BlueprintReadWrite)
		TObjectPtr<UBoxComponent>		DefaultBox;

	UPROPERTY(Category = "InteractionType", EditAnyWhere, BlueprintReadWrite)
		EInteractionType	InteractionType;

public:
	void SetInteractionType(EInteractionType Type);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
