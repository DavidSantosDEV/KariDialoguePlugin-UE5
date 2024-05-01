// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueAsset.h"

UDialogueAsset::UDialogueAsset(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), TestValue(0)
{
	if (!AssetGuid.IsValid())
	{
		AssetGuid = FGuid::NewGuid();
	}
}
