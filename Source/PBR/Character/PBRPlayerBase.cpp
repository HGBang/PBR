// Fill out your copyright notice in the Description page of Project Settings.


#include "PBRPlayerBase.h"

APBRPlayerBase::APBRPlayerBase()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	mSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	mSpringArm->SetupAttachment(GetMesh());
	mSpringArm->TargetArmLength = 1200.f;
	mSpringArm->SetRelativeLocation(FVector(0.0, 0.0, 150.0));
	mSpringArm->SetRelativeRotation(FRotator(-40.0, 45.0, 0.0));
	mSpringArm->bDoCollisionTest = false;
	mSpringArm->SetUsingAbsoluteRotation(true);

	mCamera->SetupAttachment(mSpringArm);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0, 640.0, 0.0);

	mCamera->bUsePawnControlRotation = false;

}
