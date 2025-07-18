// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/PlayerStart.h"
#include "GameplayTagContainer.h"

#include "LyraPlayerStart.generated.h"

#define UE_API LYRAGAME_API

class AController;
class UObject;

enum class ELyraPlayerStartLocationOccupancy
{
	Empty,
	Partial,
	Full
};

/**
 * ALyraPlayerStart
 * 
 * Base player starts that can be used by a lot of modes.
 */
UCLASS(MinimalAPI, Config = Game)
class ALyraPlayerStart : public APlayerStart
{
	GENERATED_BODY()

public:
	UE_API ALyraPlayerStart(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	const FGameplayTagContainer& GetGameplayTags() { return StartPointTags; }

	UE_API ELyraPlayerStartLocationOccupancy GetLocationOccupancy(AController* const ControllerPawnToFit) const;

	/** Did this player start get claimed by a controller already? */
	UE_API bool IsClaimed() const;

	/** If this PlayerStart was not claimed, claim it for ClaimingController */
	UE_API bool TryClaim(AController* OccupyingController);

protected:
	/** Check if this PlayerStart is still claimed */
	UE_API void CheckUnclaimed();

	/** The controller that claimed this PlayerStart */
	UPROPERTY(Transient)
	TObjectPtr<AController> ClaimingController = nullptr;

	/** Interval in which we'll check if this player start is not colliding with anyone anymore */
	UPROPERTY(EditDefaultsOnly, Category = "Player Start Claiming")
	float ExpirationCheckInterval = 1.f;

	/** Tags to identify this player start */
	UPROPERTY(EditAnywhere)
	FGameplayTagContainer StartPointTags;

	/** Handle to track expiration recurring timer */
	FTimerHandle ExpirationTimerHandle;
};

#undef UE_API
