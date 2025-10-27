




///-------------------------------------------------------------------------------------
/// This file showcase how to override a item from the top down.
/// Showcase how to replace the root component, for classes that don't require a static mesh for the root component.
/// Also showcase how to create the new derived data asset, following data driven principals.
///-------------------------------------------------------------------------------------
#pragma once

#include "CoreMinimal.h"
#include "Item/Game/EmItem.h"
#include "Item/ActionInterface.h"
#include "Item/Data/EmItemAsset.h"
#include "Item/Data/EmItemParser.h"
#include "WeaponItem.generated.h"



UCLASS()
class EMITEMPLUGINEXAMPLE_API UWeaponItemAsset : public UEmItemAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly) TObjectPtr<class USkeletalMesh> SkeletalMeshAsset;
	UWeaponItemAsset(const FObjectInitializer& ObjectInitializer);
};

UCLASS()
class EMITEMPLUGINEXAMPLE_API UWeaponItemInfoObj : public UEmItemInfoObj
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) TObjectPtr<class USkeletalMesh> SkeletalMeshAsset;
	virtual void PopulateFromAsset_Implementation(class UEmItemParser* Parser, class UEmItemAsset* Asset) override;
};






UCLASS()
class EMITEMPLUGINEXAMPLE_API AWeaponItem : public AEmItem, public IActionInterface
{
	GENERATED_BODY()
	
public:

	AWeaponItem(const FObjectInitializer& ObjectInitializer);


	virtual bool CanDoAction_Implementation() const override;
	virtual void DoAction_Implementation()  override;

protected:
	virtual void PopulateFromInitiatedItemInfo_Implementation() override;
};
