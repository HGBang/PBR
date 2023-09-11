// Fill out your copyright notice in the Description page of Project Settings.


#include "PBR_PlayerController.h"
#include "Character/PBRPlayerBase.h"
#include "Animation/PlayerAnimInstance.h"

APBR_PlayerController::APBR_PlayerController()
{
	mClickOn = false;

	bShowMouseCursor = true;
}

void APBR_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();


	InputComponent->BindAction(TEXT("MoveClick"), EInputEvent::IE_Pressed, this, &APBR_PlayerController::MouseRightClickOn);
	InputComponent->BindAction(TEXT("MoveClick"), EInputEvent::IE_Released, this, &APBR_PlayerController::MouseRightClickOff);
	InputComponent->BindAction(TEXT("DefaultAttack"), EInputEvent::IE_Pressed, this, &APBR_PlayerController::MouseLeftClickOn);

}

void APBR_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (mClickOn)
		MoveToMouseCursor();
}

void APBR_PlayerController::SetNewDestination(const FVector& Loc)
{
	APawn* const PlayerPawn = GetPawn();

	if (PlayerPawn)
	{
		float Distance = FVector::Dist(Loc, PlayerPawn->GetActorLocation());

		if (Distance > 120.f)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, Loc);
		}
	}
}

void APBR_PlayerController::MoveToMouseCursor()
{
	FHitResult MouseHit;

	GetHitResultUnderCursor(ECC_Visibility, false, MouseHit);

	if (MouseHit.bBlockingHit)
		SetNewDestination(MouseHit.ImpactPoint);

}

void APBR_PlayerController::MouseRightClickOn()
{
	mClickOn = true;
}

void APBR_PlayerController::MouseRightClickOff()
{
	mClickOn = false;
}

void APBR_PlayerController::MouseLeftClickOn()
{
	APawn* const PlayerPawn = GetPawn();

	APBRPlayerBase* PBRPlayer = Cast<APBRPlayerBase>(PlayerPawn);

	UPlayerAnimInstance* PlayerAnim = Cast<UPlayerAnimInstance>(PBRPlayer->GetMesh()->GetAnimInstance());

	PlayerAnim->DefaultAttack();	
}
