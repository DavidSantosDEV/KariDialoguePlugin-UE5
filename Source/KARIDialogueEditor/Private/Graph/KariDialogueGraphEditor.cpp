// Fill out your copyright notice in the Description page of Project Settings.


#include "Graph/KariDialogueGraphEditor.h"

#include "DialogueAsset.h"
#include "Asset/DialogueAssetEditor.h"

void SKariDialogueGraphEditor::Construct(const FArguments& InArgs, const TSharedPtr<FDialogueAssetEditor> InAssetEditor)
{
	DialogueAssetEditor = InAssetEditor;
	DialogueAsset = DialogueAssetEditor.Pin()->GetDialogueAsset();

	BindCommands();

	SGraphEditor::FArguments Arguments;
	Arguments._AdditionalCommands = CommandList;
	//Arguments._Appearance = GetGraphAppearanceInfo(); //Todo
	//Arguments._GraphToEdit = FlowAsset->GetGraph();
	Arguments._GraphEvents = InArgs._GraphEvents;
	Arguments._AutoExpandActionMenu = true;
	/*
	Arguments._GraphEvents.OnSelectionChanged = FOnSelectionChanged::CreateSP(this, );
	Arguments._GraphEvents.OnNodeDoubleClicked = FSingleNodeEvent::CreateSP(this, );
	Arguments._GraphEvents.OnTextCommitted = FOnNodeTextCommitted::CreateSP(this, );
	Arguments._GraphEvents.OnSpawnNodeByShortcut = FOnSpawnNodeByShortcut::CreateStatic(, static_cast<UEdGraph*>(DialogueAsset->GetGraph()));
	*/
	SGraphEditor::Construct(Arguments);
}

void SKariDialogueGraphEditor::BindCommands()
{
}
