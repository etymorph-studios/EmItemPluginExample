// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmItemPluginExampleGameMode.h"
#include "EmItemPluginExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEmItemPluginExampleGameMode::AEmItemPluginExampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
