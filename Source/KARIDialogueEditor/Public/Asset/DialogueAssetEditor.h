// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EditorUndoClient.h"
#include "Misc/NotifyHook.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "Toolkits/IToolkitHost.h"
#include "UObject/GCObject.h"

class UDialogueAsset;

class KARIDIALOGUEEDITOR_API FDialogueAssetEditor final : public FAssetEditorToolkit, public FEditorUndoClient, public FGCObject, public FNotifyHook
{
protected:
	UDialogueAsset* DialogueAsset = nullptr;

	TSharedPtr<class SKariDialogueGraphEditor> GraphEditor;
	TSharedPtr<IDetailsView> DetailsView;
	TSharedPtr<class SFlowPalette> Palette;

	void CreateEditorWidgets();
	static bool CanEditAsset();

public:
	static const FName GraphTabId;
	static const FName NodeSearchTabId;
	static const FName DetailsTabId;

	void InitToolKit(UDialogueAsset* InDialogueAsset, UObject* UnCastObject);

	//Getters
	UDialogueAsset* GetDialogueAsset() const { return DialogueAsset; }

	//Window Creation
	void CreateToolBar();


	//Tab Spawners
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	
	TSharedRef<SDockTab> SpawnTabDetails(const FSpawnTabArgs& Args) const;
	TSharedRef<SDockTab> SpawnTabSearch(const FSpawnTabArgs& Args) const;
	TSharedRef<SDockTab> SpawnTabGraph(const FSpawnTabArgs& Args) const;

	// Inherited via FAssetEditorToolkit
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;

	//virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	virtual FString GetReferencerName() const override
	{
		return TEXT("KARIDialogueEditor");
	}
};
