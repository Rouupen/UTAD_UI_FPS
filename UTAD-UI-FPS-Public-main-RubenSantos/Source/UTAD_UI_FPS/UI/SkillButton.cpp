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
	skillTreeInstance = instance;
	this->OnClicked.AddDynamic(this, &USkillButton::SkillClick);


}

bool USkillButton::IsUnlocked()
{
	return unlocked;
}

void USkillButton::SetUnlocked(bool Unlocked)
{
	unlocked = Unlocked;
}
