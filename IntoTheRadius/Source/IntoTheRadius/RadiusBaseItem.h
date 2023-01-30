// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "RadiusItemActor.h"
#include "RadiusBaseItem.generated.h"

/**
 * 
 */
UCLASS()
class INTOTHERADIUS_API ARadiusBaseItem : public ARadiusItemActor
{
	GENERATED_BODY()

	UFUNCTION()
	void Setup(const FBaseItemSpawnInfo& BaseItemSpawnInfo);
	UFUNCTION()
	void ResetInventoryItemRef();
	UFUNCTION()
	bool IsInitInventoryItem();
	UFUNCTION()
	UInventoryItem* InitInventoryItem();
	
};

