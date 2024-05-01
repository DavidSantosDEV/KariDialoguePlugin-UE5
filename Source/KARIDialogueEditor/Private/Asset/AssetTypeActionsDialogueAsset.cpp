// Fill out your copyright notice in the Description page of Project Settings.


#include "Asset/AssetTypeActionsDialogueAsset.h"

#include "DialogueAsset.h"
#include "KARIDialogueEditor.h"
#include "Asset/DialogueAssetEditor.h"

UClass* FAssetTypeActionsDialogueAsset::GetSupportedClass() const
{
	return UDialogueAsset::StaticClass();
}

FText FAssetTypeActionsDialogueAsset::GetName() const
{
	return INVTEXT("Dialogue Asset");
}

FColor FAssetTypeActionsDialogueAsset::GetTypeColor() const
{
	return FColor::Emerald;
}

uint32 FAssetTypeActionsDialogueAsset::GetCategories()
{
	return FKARIDialogueEditorModule::KariDialogueAssetCategory;
}

void FAssetTypeActionsDialogueAsset::OpenAssetEditor(const TArray<UObject*>& InObjects,
	TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for(auto ItObj = InObjects.CreateConstIterator(); ItObj;++ItObj )
	{
		if(UDialogueAsset* DialogueAsset = Cast<UDialogueAsset>(*ItObj))
		{
			//Create editor;
			MakeShared<FDialogueAssetEditor>()->InitToolKit(DialogueAsset, *ItObj);
		}		
	}
}
