// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/SkillTree.h"
#include "../UI/UnlockSkillPopUp.h"
#include "../UI/CantUnlockSkillPopUp.h"
#include "Components/TextBlock.h"
#include "Styling/SlateBrush.h"


void USkillTree::Show()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->bShowMouseCursor = true;
	PlayerController->SetInputMode(FInputModeGameAndUI());
	TotalPoints->SetText(FText::FromString(FString::Printf(TEXT("Points: %i"), Points)));
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

		if (i > 0)
		{
			speedButtons[i - 1]->nextSkillPoint = speedButtons[i];
		}
	}

	for (size_t i = 0; i < NameDamageButtons.Num(); i++)
	{
		damageButtons.Add(Cast<USkillButton>(GetWidgetFromName(NameDamageButtons[i])));
		damageButtons[i]->SetIsEnabled(i == 0 ? true : false);
		damageButtons[i]->Initialize(this);

		if (i > 0)
		{
			damageButtons[i - 1]->nextSkillPoint = damageButtons[i];
		}
	}

	for (size_t i = 0; i < NameHealthButtons.Num(); i++)
	{
		healthButtons.Add(Cast<USkillButton>(GetWidgetFromName(NameHealthButtons[i])));
		healthButtons[i]->SetIsEnabled(i == 0 ? true : false);
		healthButtons[i]->Initialize(this);

		if (i > 0)
		{
			healthButtons[i - 1]->nextSkillPoint = healthButtons[i];
		}
	}
	unlockSkillPopUp->SetSkillTree(this);
	Hide();
}

void USkillTree::TryUnlockSkill(int cost, USkillButton* button)
{
	if (button->IsUnlocked())
	{
		return;
	}

	if (Points - cost >= 0)
	{
		currentSkillButton = button;
		currentCost = cost;
		unlockSkillPopUp->Show();
	}
	else
	{
		cantUnlockSkillPopUp->Show();
	}
}

void USkillTree::UnlockSkill()
{
	Points -= currentCost;
	currentSkillButton->SetUnlocked();

	UTexture* image =  Cast<UTexture>(currentSkillButton->WidgetStyle.Normal.GetResourceObject());
	FButtonStyle newStyle = currentSkillButton->GetStyle();
	FSlateBrush disabled = FSlateBrush();
	disabled.TintColor = FSlateColor(FLinearColor(0.724268f, 0.589121f, 0.081767f, 1.f));
	disabled.ImageType = ESlateBrushImageType::Type::Linear;
	disabled.DrawAs = ESlateBrushDrawType::Image;
	disabled.SetResourceObject(image);
	newStyle.SetDisabled(disabled);
	currentSkillButton->SetStyle(newStyle);
	currentSkillButton->SetIsEnabled(false);

	if (currentSkillButton->nextSkillPoint)
	{
		currentSkillButton->nextSkillPoint->SetIsEnabled(true);
	}
	TotalPoints->SetText(FText::FromString(FString::Printf(TEXT("Points: %i"), Points)));
}

