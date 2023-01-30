// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTags.h"
#include "Delegates/MulticastDelegateBase.h"
#include "InventoryItem.generated.h"


UENUM()
enum EItemSlot
{
	None     = 0,
	Magazine = 1,
	Barrel   = 2,
	Stock    = 3,
	Rail_01  = 4,
	Rail_02  = 5,
	Rail_03  = 6,
	Rail_04  = 7,
	Slot_01  = 8,
	Slot_02  = 9,
	Slot_03  = 10,
	Slot_04  = 11,
	MAX      = 12
};

USTRUCT()
struct INTOTHERADIUS_API FAmmoContainerData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FGameplayTag>                                Ammo;                                                    // 0x0000(0x0010) Edit, BlueprintVisible, ZeroConstructor, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	FGameplayTag                                        ChamberAmmo;                                             // 0x0010(0x0008) Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	
};

USTRUCT()
struct FPRItemInfo : public FTableRowBase
{
	GENERATED_BODY()
public:
	FGameplayTag                                        ItemTypeID;                                              // 0x0008(0x0008) Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	FGameplayTag                                        AttachmentTypeID;                                        // 0x0010(0x0008) Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UClass*                                              ActorClass;                                              // 0x0018(0x0008) Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UClass*                                              ProxyClass;                                              // 0x0020(0x0008) Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic
	FText                                                ItemName;                                                // 0x0028(0x0018) Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic
	FText                                                ItemDescription;                                         // 0x0040(0x0018) Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic
	FText                                                ItemHelp;                                                // 0x0058(0x0018) Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic
	bool                                                       DestroyedAtZeroDurability;                               // 0x0070(0x0001) Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	bool                                                       ChangeWeightFromDurability;                              // 0x0071(0x0001) Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	//FItemShopInfo                                       Prices;                                                  // 0x0080(0x0050) Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, NativeAccessSpecifierPublic
	//FItemParameters                                     ItemParameters;                                          // 0x00D0(0x0018) Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, NativeAccessSpecifierPublic
	//FArmorParameters                                    ArmorParameters;                                         // 0x00E8(0x0058) Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic
	TArray<FGameplayTag>                                PossibleUpgrades;                                        // 0x0140(0x0010) Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NativeAccessSpecifierPublic
	TMap<EItemSlot, FGameplayTag>                       AttachmentSlots;                                         // 0x0150(0x0050) Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic
};


/**
 * 
 */
UCLASS(BlueprintType)
class INTOTHERADIUS_API UInventoryItem : public UDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere)
	FString                                              InstanceId;                                              // 0x0040(0x0010) Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	FGameplayTag                                        ItemId;                                                  // 0x0050(0x0008) Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	FString                                              AttachedTo;                                              // 0x0058(0x0010) Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	TEnumAsByte<EItemSlot>                                                  AttachmentSlot;                                          // 0x0068(0x0001) Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	FGameplayTag                                        holderID;                                                // 0x006C(0x0008) Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	FTransform                                          HolderRelativeTransform;                                 // 0x0080(0x0030) Edit, BlueprintVisible, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	float                                                      Durability;                                              // 0x00B0(0x0004) Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	FAmmoContainerData                                  AmmoInfo;                                                // 0x00B8(0x0018) Edit, BlueprintVisible, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	TArray<FString>                                      Attachments;                                             // 0x00D0(0x0010) Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	AActor*                                              ActorReference;                                          // 0x00E0(0x0008) Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	TArray<FGameplayTag>                                AdditionalTags;                                          // 0x00E8(0x0010) Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	TArray<FGameplayTag>                                Upgrades;                                                // 0x00F8(0x0010) Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NativeAccessSpecifierPublic

};
