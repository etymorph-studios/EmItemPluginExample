// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/WeaponItem.h"
#include "TP_WeaponComponent.h"




UWeaponItemAsset::UWeaponItemAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	InfoObjectType = UWeaponItemInfoObj::StaticClass();
}
void UWeaponItemInfoObj::PopulateFromAsset_Implementation(class UEmItemParser* Parser, class UEmItemAsset* Asset)
{
	Super::PopulateFromAsset_Implementation(Parser,Asset);
	UWeaponItemAsset* ItemAsset = Cast<UWeaponItemAsset>(Asset);
	if (ItemAsset != nullptr)
	{
		SkeletalMeshAsset = ItemAsset->SkeletalMeshAsset;
	}
}





AWeaponItem::AWeaponItem(const FObjectInitializer& ObjectInitializer) : 
	//Super(ObjectInitializer.SetDefaultSubobjectClass<UTP_WeaponComponent>(TEXT("MyRootComponent")))
	Super(ObjectInitializer)
{
	TObjectPtr<USceneComponent> OldRootComponent = MyRootComponent;

	MyRootComponent = CreateDefaultSubobject<UTP_WeaponComponent>(TEXT("MyNewRootComponent"));
	check(MyRootComponent != nullptr);
	MyRootComponent->SetIsReplicated(true);
	RootComponent = MyRootComponent;

	OldRootComponent->DestroyComponent();
}


bool AWeaponItem::CanDoAction_Implementation() const
{
	return false;
}
void AWeaponItem::DoAction_Implementation()
{

}

void AWeaponItem::PopulateFromInitiatedItemInfo_Implementation()
{
	Super::PopulateFromInitiatedItemInfo_Implementation();
	UWeaponItemInfoObj* InfoObj = Cast<UWeaponItemInfoObj>(GetItemInfoObj());
	if (InfoObj != nullptr)
	{
		if (InfoObj->SkeletalMeshAsset != nullptr)
		{
			if (UTP_WeaponComponent* SMC = Cast<UTP_WeaponComponent>(RootComponent); SMC != nullptr)
			{
				SMC->AuthSetSkeletalMesh(InfoObj->SkeletalMeshAsset);
			}
		}
	}
}



