// Copyright https://github.com/DavidSantosDEV

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "DialogueSchemaActionNewNode.generated.h"

/**
 * Adding a node to dialogue graph
 */
USTRUCT()
struct KARIDIALOGUEEDITOR_API FDialogueSchemaActionNewNode : public FEdGraphSchemaAction
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	UClass* NodeClass;

	static FName StaticGetTypeId()
	{
		static FName Type("FDialogueSchemaActionNewNode");
		return Type;
	}

	virtual FName GetTypeId() const override { return StaticGetTypeId(); }

};
