// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ActionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UActionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class EMITEMPLUGINEXAMPLE_API IActionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent) bool CanDoAction() const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent) void DoAction();

};
