// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/CantUnlockSkillPopUp.h"
#include "../UI/SkillButton.h"

void UCantUnlockSkillPopUp::Show()
{
	SetVisibility(ESlateVisibility::Visible);
}

void UCantUnlockSkillPopUp::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UCantUnlockSkillPopUp::NativeConstruct()
{
	Super::NativeConstruct();
	OkeyButton->OnClicked.AddDynamic(this, &UCantUnlockSkillPopUp::Hide);
	Hide();
}