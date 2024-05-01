// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SentenceData.h"
#include "DialogueData.generated.h"

/**
 * 
 */
UCLASS()
class KARIDIALOGUE_API UDialogueData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Dialogue")
	TArray<FSentenceData> SentenceList;
};
