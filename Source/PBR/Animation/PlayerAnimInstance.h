// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../GameInfo.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

UENUM(BlueprintType)
enum class EPlayerAnimType : uint8
{
	Default,
	Jump,
	Fall,
	Death,
	Attack
};

/**
 * 
 */
UCLASS()
class PBR_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPlayerAnimInstance();

protected:
	UPROPERTY(Category = "MoveSpeed", EditAnyWhere, BluePrintReadWrite)
	float mMoveSpeed;

	UPROPERTY(Category = AnimType, VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		EPlayerAnimType mAnimType;

	UPROPERTY(Category = AnimType, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TArray<TObjectPtr<UAnimMontage>> mAttackMontage;

	bool	mAttackEnable;
	int32	mAttackIndex;
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeBeginPlay() override;

public:
	void DefaultAttack();

	UFUNCTION()
		void AnimNotify_Attack();

	UFUNCTION()
		void AnimNotify_Attack2();

	UFUNCTION()
		void AnimNotify_AttackEnable();

	UFUNCTION()
		void AnimNotify_AttackEnd();
};
