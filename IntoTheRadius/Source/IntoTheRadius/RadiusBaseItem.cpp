// Fill out your copyright notice in the Description page of Project Settings.


#include "RadiusBaseItem.h"

void ARadiusBaseItem::Setup(const FBaseItemSpawnInfo& BaseItemSpawnInfo)
{
}

void ARadiusBaseItem::ResetInventoryItemRef()
{
}

bool ARadiusBaseItem::IsInitInventoryItem()
{
	return true;
}

UInventoryItem* ARadiusBaseItem::InitInventoryItem()
{
	return nullptr;
}
