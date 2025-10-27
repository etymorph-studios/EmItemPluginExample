// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/ItemGenericAsset.h"


#include "Item/Game/EmItemSubsystem.h"


UItemGenericAsset::UItemGenericAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	InfoObjectType = UItemInfoGenericObj::StaticClass();
}

void UItemInfoGenericObj::PopulateFromAsset_Implementation(class UEmItemParser* Parser, class UEmItemAsset* Asset)
{
	Super::PopulateFromAsset_Implementation(Parser, Asset);
	
	UItemGenericAsset* MyAsset = Cast<UItemGenericAsset>(Asset);
	if (MyAsset != nullptr)
	{
		RootMesh = MyAsset->RootMesh;
	}
}