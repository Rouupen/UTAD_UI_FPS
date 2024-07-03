// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/SkillTree.h"


void USkillTree::Show()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->bShowMouseCursor = true;
	PlayerController->SetInputMode(FInputModeGameAndUI());
	SetVisibility(ESlateVisibility::Visible);
}

void USkillTree::Hide()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->bShowMouseCursor = false;
	PlayerController->SetInputMode(FInputModeGameOnly());
	SetVisibility(ESlateVisibility::Hidden);
}

void USkillTree::SwitchMenu()
{
	if (GetVisibility() == ESlateVisibility::Hidden)
	{
		Show();
	}
	else
	{
		Hide();
	}
}

void USkillTree::NativeConstruct()
{
	Super::NativeConstruct();

	for (size_t i = 0; i < NameSpeedButtons.Num(); i++)
	{
		speedButtons.Add(Cast<USkillButton>(GetWidgetFromName(NameSpeedButtons[i])));
		speedButtons[i]->SetIsEnabled(i == 0 ? true : false);
		speedButtons[i]->Initialize(this);
	}

	for (size_t i = 0; i < NameDamageButtons.Num(); i++)
	{
		damageButtons.Add(Cast<USkillButton>(GetWidgetFromName(NameDamageButtons[i])));
		damageButtons[i]->SetIsEnabled(i == 0 ? true : false);
		damageButtons[i]->Initialize(this);
	}

	for (size_t i = 0; i < NameHealthButtons.Num(); i++)
	{
		healthButtons.Add(Cast<USkillButton>(GetWidgetFromName(NameHealthButtons[i])));
		healthButtons[i]->SetIsEnabled(i == 0 ? true : false);
		healthButtons[i]->Initialize(this);
	}

	Hide();
}

void USkillTree::TryUnlockSkill(int cost, USkillButton* button)
{
	if (Points - cost >= 0)
	{

	}
	else
	{

	}
}

