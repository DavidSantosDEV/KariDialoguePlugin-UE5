// Fill out your copyright notice in the Description page of Project Settings.


#include "Asset/DialogueAssetFactory.h"
#include "DialogueAsset.h"

UDialogueAssetFactory::UDialogueAssetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UDialogueAsset::StaticClass();
	bEditorImport = false;
	bEditAfterNew = true;
	bCreateNew = true;
}

UObject* UDialogueAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
                                                 UObject* Context, FFeedbackContext* Warn)
{
	UDialogueAsset* NewDialogue = NewObject<UDialogueAsset>(InParent, InClass, InName, Flags | RF_Transactional, Context);
	return NewDialogue;
}
