// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "SentenceData.generated.h"

/**
 * 
 */
USTRUCT()
struct KARIDIALOGUE_API FSentenceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = SentenceData)
	FString Sentence;
	UPROPERTY(EditDefaultsOnly, Category = SentenceData)
	class USpeakerData* SpeakerData;
};
