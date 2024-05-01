// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GraphEditor.h"
#include "CoreMinimal.h"

class FDialogueAssetEditor;
class UDialogueAsset;
/**
 * Dialogue Graph Editor
 */
class KARIDIALOGUEEDITOR_API SKariDialogueGraphEditor : public SGraphEditor
{
	TWeakObjectPtr<UDialogueAsset> DialogueAsset;
	TWeakPtr<FDialogueAssetEditor> DialogueAssetEditor;

	TSharedPtr<FUICommandList> CommandList;

private:
	void BindCommands();

public:
	void Construct(const FArguments& InArgs, const TSharedPtr<FDialogueAssetEditor> InAssetEditor);
};
