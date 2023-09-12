// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionObject.h"

// Sets default values
AInteractionObject::AInteractionObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;

	DefaultBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DefaultBox"));
	DefaultBox->SetBoxExtent(FVector(100.0, 100.0, 100.0));


	DefaultBox->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;

	DefaultBox->SetCollisionProfileName(TEXT("InteractionDefault"));
	DefaultBox->SetGenerateOverlapEvents(true);
	DefaultBox->OnComponentBeginOverlap.AddDynamic(this, &AInteractionObject::OnBeginOverlap);

	SetRootComponent(DefaultBox);

	DefaultBox->bHiddenInGame = false;
	DefaultBox->bVisualizeComponent = true;

	InteractionType = EInteractionType::Default;
}

void AInteractionObject::SetInteractionType(EInteractionType Type)
{
	switch (Type)
	{
	case EInteractionType::Default:
		DefaultBox->SetCollisionProfileName(TEXT("InteractionDefault"));
		break;
	case EInteractionType::PlayerOnly:
		DefaultBox->SetCollisionProfileName(TEXT("InteractionPlayer"));
		break;
	case EInteractionType::MonsterOnly:
		DefaultBox->SetCollisionProfileName(TEXT("InteractionMonster"));
		break;
	}
}

// Called when the game starts or when spawned
void AInteractionObject::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AInteractionObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractionObject::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	switch (InteractionType)
	{
	case EInteractionType::Default:
		DefaultBox->SetCollisionProfileName(TEXT("InteractionDefault"));
		break;
	case EInteractionType::PlayerOnly:
		DefaultBox->SetCollisionProfileName(TEXT("InteractionPlayer"));
		break;
	case EInteractionType::MonsterOnly:
		DefaultBox->SetCollisionProfileName(TEXT("InteractionMonster"));
		break;
	}
}

void AInteractionObject::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("Begin OverLap Dest : %s"), *OtherActor->GetName()));
}

