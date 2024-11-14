// Copyright Petr Ershov

#pragma once

#include "CoreMinimal.h"
#include "Character/RpgCharacterBase.h"
#include "Aura_RpgCharacter.generated.h"

class AAuraPlayerState;
/**
 * 
 */
UCLASS()
class AURA_API AAura_RpgCharacter : public ARpgCharacterBase
{
	GENERATED_BODY()

public:
	AAura_RpgCharacter();

	virtual void OnRep_PlayerState() override;

	//UPROPERTY(EditAnywhere, Category= "State")
	//AAuraPlayerState* PlayerState;

	virtual void PossessedBy(AController* NewController) override;

private:
	void InitAbilityActorInfo();
};

