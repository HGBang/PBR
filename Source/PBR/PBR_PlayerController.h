// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameInfo.h"
#include "GameFramework/PlayerController.h"
#include "PBR_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PBR_API APBR_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APBR_PlayerController();

protected:
	bool		mClickOn;
	float		mCameraMin;
	float		mCameraMax;

public:
	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;

private:
	void SetNewDestination(const FVector& Loc);
	void MoveToMouseCursor();
	

private:
	// Move 
	void MouseRightClickOn();
	void MouseRightClickOff();

	// Default Attack
	void MouseLeftClickOn();	

	// Camera Zoom
	void CameraWheel(float _Scale);
	
};
