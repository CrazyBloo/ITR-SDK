// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Grippables/GrippableStaticMeshActor.h"
#include "RadiusItemActor.generated.h"

/**
 * 
 */
UCLASS()
class INTOTHERADIUS_API ARadiusItemActor : public AGrippableStaticMeshActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMesh*                                         ProxyModel;                                              // 0x0430(0x0008) Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
	UPROPERTY(EditAnywhere)
	TArray<UStaticMeshComponent*>                        OriginalModelCompList;                                   // 0x0438(0x0010) BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, ContainsInstancedReference, Protected, NativeAccessSpecifierProtected
	UPROPERTY(EditAnywhere)
	TArray<UPrimitiveComponent*>                         ProxyOmittableColliderList;                              // 0x0448(0x0010) BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, ContainsInstancedReference, Protected, NativeAccessSpecifierProtected
	UPROPERTY(EditAnywhere)
	bool                                                       bCanAddToLevelInventory;                                 // 0x0458(0x0001) BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent*                                ProxyComp;    
	
};


USTRUCT()
struct INTOTHERADIUS_API FActorSpawnInfo
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
	FTransform                                          Transform;                                               // 0x0000(0x0030) Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	UClass*                                             ActorClass;                                              // 0x0030(0x0008) Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	bool                                                UseRelevanceManager;                                     // 0x0038(0x0001) Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	AActor*                                             Owner; 
};



USTRUCT()
struct INTOTHERADIUS_API FBaseItemSpawnInfo : public FActorSpawnInfo
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere)
	bool                                                       Preconfigured;                                           // 0x0048(0x0001) BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	FString                                              CustomUID;                                               // 0x0050(0x0010) BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	bool                                                       NotUnique;                                               // 0x0060(0x0001) BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	TArray<FGameplayTag>                                CustomAdditionalTags;                                    // 0x0068(0x0010) BlueprintVisible, ZeroConstructor, NativeAccessSpecifierPublic
	UPROPERTY(EditAnywhere)
	float                                                      CustomDurabilityRatio;  
	
};

