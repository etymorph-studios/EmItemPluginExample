// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Data/EmItemAsset.h"
#include "Item/Data/EmItemParser.h"
#include "ItemGenericAsset.generated.h"

/**
 * 
 */
UCLASS()
class EMITEMPLUGINEXAMPLE_API UItemGenericAsset : public UEmItemAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly) TObjectPtr<class UStaticMesh> RootMesh;
	

	UItemGenericAsset(const FObjectInitializer& ObjectInitializer);

};


UCLASS()
class EMITEMPLUGINEXAMPLE_API UItemInfoGenericObj : public UEmItemInfoObj
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) TObjectPtr<class UStaticMesh> RootMesh;

	virtual void PopulateFromAsset_Implementation(class UEmItemParser* Parser, class UEmItemAsset* Asset) override;

};
