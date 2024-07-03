// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/SkillButton.h"
#include "../UI/SkillTree.h"

void USkillButton::SkillClick()
{
	if (skillTreeInstance)
	{
		skillTreeInstance->TryUnlockSkill(skillPointsCost, this);
	}
}

void USkillButton::Initialize(USkillTree* instance)
{
	this->OnClicked.AddDynamic(this, &USkillButton::SkillClick);

	skillTreeInstance = instance;

}
