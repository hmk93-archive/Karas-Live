// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControlPointStatusMessage.generated.h"

// Message indicating the state of a control point is changing
USTRUCT(BlueprintType)
struct FLyraControlPointStatusMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = Gameplay)
	TObjectPtr<AActor> ControlPoint = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = Gameplay)
	int32 OwnerTeamID = 0;
};
