// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "../Character/PBRPlayerBase.h"

UPlayerAnimInstance::UPlayerAnimInstance()
{
	mMoveSpeed = 0.f;
	mAttackEnable = true;
	mAttackIndex = 0;
}

void UPlayerAnimInstance::NativeInitializeAnimation()
{
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APBRPlayerBase* Player = Cast<APBRPlayerBase>(TryGetPawnOwner());

	if (IsValid(Player))
	{
		UCharacterMovementComponent* Movement = Player->GetCharacterMovement();

		if (IsValid(Movement))
		{
			mMoveSpeed = Movement->Velocity.Length();
		}
	}
}

void UPlayerAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}

void UPlayerAnimInstance::NativePostEvaluateAnimation()
{
	Super::NativePostEvaluateAnimation();
}

void UPlayerAnimInstance::NativeUninitializeAnimation()
{
	Super::NativeUninitializeAnimation();
}

void UPlayerAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UPlayerAnimInstance::DefaultAttack()
{
	if (!mAttackEnable || Montage_IsPlaying(mAttackMontage[mAttackIndex]))
		return;

	mAttackEnable = false;

	Montage_SetPosition(mAttackMontage[mAttackIndex], 0.f);

	Montage_Play(mAttackMontage[mAttackIndex]);

	mAttackIndex = (mAttackIndex + 1) % mAttackMontage.Num();
}

void UPlayerAnimInstance::AnimNotify_Attack()
{

}

void UPlayerAnimInstance::AnimNotify_Attack2()
{
}

void UPlayerAnimInstance::AnimNotify_AttackEnable()
{
	mAttackEnable = true;
}

void UPlayerAnimInstance::AnimNotify_AttackEnd()
{
	mAttackIndex = 0;
}
