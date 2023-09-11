// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Serath.h"

APlayer_Serath::APlayer_Serath()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(92.f);

	GetMesh()->SetRelativeLocation(FVector(0.0, 0.f, -92.0));

	GetMesh()->SetRelativeRotation(FRotator(0.0, -90.0, 0.0));
}
