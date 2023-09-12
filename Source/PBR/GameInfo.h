// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "EngineGlobals.h"
#include "Engine.h"
#include "UObject/NoExportTypes.h"
#include "DrawDebugHelpers.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "GameInfo.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(PBR, Log, All);

#define   LOG_CALLINFO   (FString(__FUNCTION__) + TEXT("[") + FString::FromInt(__LINE__) + TEXT("]"))

// %s : 문자열을 받아와서 그 문자열로 채워준다.
// %s는 Ftring을 바로 넣어줄 수 없다. 앞에 *을 붙여서 FString이 가지고
// 있는 문자열의 주소를 가지고 오고 그 주소를 넣어주어야 한다.
// %d : 정수를 받아와서 그 정수를 문자열로 만들어서 채워준다.
// %f : 실수를 받아와서 그 정수를 문자열로 만들어서 채워준다.
#define   LOG(Format, ...)   UE_LOG(PBR, Warning, TEXT("%s : %s"), *LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

#define   LOGSTRING(str)      UE_LOG(PBR, Warning, TEXT("%S : %S"), *LOG_CALLINFO, *str)


/**
 * 
 */
UCLASS()
class PBR_API UGameInfo : public UObject
{
	GENERATED_BODY()
	
};
