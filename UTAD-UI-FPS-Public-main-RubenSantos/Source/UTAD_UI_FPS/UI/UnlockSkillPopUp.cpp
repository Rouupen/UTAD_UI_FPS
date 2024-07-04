// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/UnlockSkillPopUp.h"
#include "../UI/SkillTree.h"

void UUnlockSkillPopUp::Show()
{
	SetVisibility(ESlateVisibility::Visible);
}

void UUnlockSkillPopUp::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UUnlockSkillPopUp::SetSkillTree(USkillTree* instance)
{
	skillTreeInstance = instance;
}

void UUnlockSkillPopUp::NativeConstruct()
{
	Super::NativeConstruct();
	UnlockButton->OnClicked.AddDynamic(this, &UUnlockSkillPopUp::UnlockSkill);
	CancelButton->OnClicked.AddDynamic(this, &UUnlockSkillPopUp::Hide);

	Hide();
}

void UUnlockSkillPopUp::UnlockSkill()
{
	if (skillTreeInstance)
	{
		skillTreeInstance->UnlockSkill();
	}
	Hide();
}
