// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../GameInfo.h"
#include "PBRCharacterBase.h"
#include "PBRPlayerBase.generated.h"

/**
 * 
 */
UCLASS()
class PBR_API APBRPlayerBase : public APBRCharacterBase
{
	GENERATED_BODY()

public:
	APBRPlayerBase();

private:
	UPROPERTY(Category = Component, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent>		SpringArm;

	UPROPERTY(Category = Component, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent>		Camera;

	
};
