// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "Item/Game/EmItemAttachmentInterface.h"
#include "TP_WeaponComponent.generated.h"

class AEmItemPluginExampleCharacter;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EMITEMPLUGINEXAMPLE_API UTP_WeaponComponent : public USkeletalMeshComponent, public IEmItemAttachmentInterface
{
	GENERATED_BODY()



protected:
	FOnEmAttachParentChanged OnEmAttachParentChanged;
	UPROPERTY(Transient) AActor* LastAttachActor { nullptr };
	virtual void OnAttachmentChanged() override;


	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

public:

	/// override UEmItemAttachmentInterface. Allows this to be the root component of the AEmItem.
	virtual void RegisterForAttachmentEvents(FOnEmAttachParentChanged&& ListenEvent) override;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly) void AuthSetSkeletalMesh(USkeletalMesh* MeshAsset);

public:
	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile, BlueprintReadOnly)
	TSubclassOf<class AEmItemPluginExampleProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;
	
	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector MuzzleOffset;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* FireMappingContext;

	/** Fire Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* FireAction;

	/** Sets default values for this component's properties */
	UTP_WeaponComponent();

	/** Attaches the actor to a FirstPersonCharacter */
	UFUNCTION(BlueprintCallable, Category="Weapon")
	bool AttachWeapon(AEmItemPluginExampleCharacter* TargetCharacter);

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void Fire();



	


protected:
	/** Ends gameplay for this component. */
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


	UFUNCTION() void OnRep_SkeletalMeshAsset();
	UPROPERTY(ReplicatedUsing = OnRep_SkeletalMeshAsset, EditAnywhere, BlueprintReadWrite, Category = Mesh) USkeletalMesh* Safe_MeshAsset {nullptr};

private:
	/** The Character holding this weapon*/
	AEmItemPluginExampleCharacter* Character;
};
