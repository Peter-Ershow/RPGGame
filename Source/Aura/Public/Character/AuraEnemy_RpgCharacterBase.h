// Copyright Petr Ershov

#pragma once

#include "CoreMinimal.h"
#include "Character/RpgCharacterBase.h"
#include "Interaction/HighlightableInterface.h"
#include "AuraEnemy_RpgCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy_RpgCharacterBase : public ARpgCharacterBase, public IHighlightableInterface
{
	GENERATED_BODY()

public:

	AAuraEnemy_RpgCharacterBase();
	virtual void HighlightActor() override;

	virtual void UnhighlightActor() override;
};
