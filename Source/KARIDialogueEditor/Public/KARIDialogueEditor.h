// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeCategories.h"
#include "Asset/AssetTypeActionsDialogueAsset.h"
#include "Modules/ModuleManager.h"

class FKARIDialogueEditorModule : public IModuleInterface
{
private:
	TSharedPtr<FAssetTypeActionsDialogueAsset> DialogueAssetTypeActions;
public:
	static EAssetTypeCategories::Type KariDialogueAssetCategory;
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void RegisterAssets();
	void UnRegisterAssets() const;
};
