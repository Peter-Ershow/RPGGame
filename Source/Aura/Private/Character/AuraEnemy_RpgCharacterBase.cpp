// Copyright Petr Ershov


#include "Character/AuraEnemy_RpgCharacterBase.h"

#include "AbilitySystem/RpgAbilitySystemComponentBase.h"
#include "AbilitySystem/RpgAttributeSet.h"
#include "Aura/Aura.h"

AAuraEnemy_RpgCharacterBase::AAuraEnemy_RpgCharacterBase()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<URpgAbilitySystemComponentBase>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<URpgAttributeSet>("AttributeSet");
}

void AAuraEnemy_RpgCharacterBase::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy_RpgCharacterBase::UnhighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
