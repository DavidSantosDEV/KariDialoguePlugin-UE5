// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DialogueAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class KARIDIALOGUE_API UDialogueAsset : public UObject
{
public:
	GENERATED_BODY()

	explicit UDialogueAsset(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere)
	FGuid AssetGuid;
	UPROPERTY(Category = "Test", EditAnywhere)
	float TestValue;
};
