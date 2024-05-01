// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "DialogueAssetFactory.generated.h"

/**
 * 
 */
UCLASS(HideCategories = Object)
class KARIDIALOGUEEDITOR_API UDialogueAssetFactory : public UFactory
{
	GENERATED_UCLASS_BODY()


	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
