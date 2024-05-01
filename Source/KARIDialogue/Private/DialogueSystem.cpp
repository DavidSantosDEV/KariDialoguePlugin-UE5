// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueSystem.h"

void UDialogueSystem::Initialize(FSubsystemCollectionBase& Collection)
{
}

void UDialogueSystem::Deinitialize()
{
}

void UDialogueSystem::StartDialogue(FString dialogueId)
{
	AsyncTask(ENamedThreads::AnyNormalThreadNormalTask, [this]{


		});
}

void UDialogueSystem::NextSentence()
{
}
