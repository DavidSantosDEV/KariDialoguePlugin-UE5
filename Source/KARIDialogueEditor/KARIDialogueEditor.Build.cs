// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class KARIDialogueEditor : ModuleRules
{
	public KARIDialogueEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"EditorSubsystem",
				"KARIDialogue",
			});
				
		
		PrivateDependencyModuleNames.AddRange(
			new string[] {
            "ApplicationCore",
            "AssetSearch",
            "AssetTools",
            "BlueprintGraph",
            "ClassViewer",
            "ContentBrowser",
            "Core",
            "CoreUObject",
            "DetailCustomizations",
            "DeveloperSettings",
            "EditorFramework",
            "EditorScriptingUtilities",
            "EditorStyle",
            "Engine",
            "GraphEditor",
            "InputCore",
            "Json",
            "JsonUtilities",
            "Kismet",
            "KismetWidgets",
            "LevelEditor",
            "LevelSequence",
            "MovieScene",
            "MovieSceneTools",
            "MovieSceneTracks",
            "Projects",
            "PropertyEditor",
            "PropertyPath",
            "RenderCore",
            "Sequencer",
            "Slate",
            "SlateCore",
            "SourceControl",
            "ToolMenus",
            "UnrealEd"
				// ... add other private include paths required here ...
			}
			);
	}
}
