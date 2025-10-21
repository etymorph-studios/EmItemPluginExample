// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EmItemPluginExample : ModuleRules
{
	public EmItemPluginExample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Slate", "SlateCore", "EngineSettings", "DeveloperSettings", "UMG", "NetCore", "CoreOnline", "GamePlayTags" });
	}
}