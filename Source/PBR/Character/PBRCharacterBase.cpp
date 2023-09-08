// Fill out your copyright notice in the Description page of Project Settings.


#include "PBRCharacterBase.h"

// Sets default values
APBRCharacterBase::APBRCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APBRCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APBRCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APBRCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

