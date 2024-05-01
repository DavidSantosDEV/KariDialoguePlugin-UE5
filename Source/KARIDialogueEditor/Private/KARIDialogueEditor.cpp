// Copyright Epic Games, Inc. All Rights Reserved.

#include "KARIDialogueEditor.h"

#include "AssetToolsModule.h"

#define LOCTEXT_NAMESPACE "FKARIDialogueEditorModule"

EAssetTypeCategories::Type FKARIDialogueEditorModule::KariDialogueAssetCategory = static_cast<EAssetTypeCategories::Type>(0);


void FKARIDialogueEditorModule::StartupModule()
{
	RegisterAssets();
}

void FKARIDialogueEditorModule::ShutdownModule()
{
	UnRegisterAssets();
}

void FKARIDialogueEditorModule::RegisterAssets()
{
	IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
	const FText CategoryName = FText::FromString("KARIDialogue");

	TArray<FAdvancedAssetCategory> AllCategories;
	AssetTools.GetAllAdvancedAssetCategories(AllCategories);

	for (const FAdvancedAssetCategory& ExistingCategory : AllCategories)
	{
		if (ExistingCategory.CategoryName.EqualTo(CategoryName))
		{
			KariDialogueAssetCategory = ExistingCategory.CategoryType;
			break;
		}
	}

	if(KariDialogueAssetCategory == EAssetTypeCategories::None)
	{
		KariDialogueAssetCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Kari Dialogue")), CategoryName);
	}

	DialogueAssetTypeActions = MakeShared<FAssetTypeActionsDialogueAsset>();
	AssetTools.RegisterAssetTypeActions(DialogueAssetTypeActions.ToSharedRef());
}

void FKARIDialogueEditorModule::UnRegisterAssets() const
{
	if (!FModuleManager::Get().IsModuleLoaded("AssetTools")) return;

	FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(DialogueAssetTypeActions.ToSharedRef());
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FKARIDialogueEditorModule, KARIDialogueEditor)