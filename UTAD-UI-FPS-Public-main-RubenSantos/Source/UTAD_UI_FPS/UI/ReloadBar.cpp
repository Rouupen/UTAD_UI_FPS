// Fill out your copyright notice in the Description page of Project Settings.


#include "ReloadBar.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "../TP_WeaponComponent.h"
#include "Components/ProgressBar.h"
#include "../UTAD_UI_FPSCharacter.h"

void UReloadBar::Show()
{
	if (character)
	{
		if (character->GetAttachedWeaponComponent())
		{
			character->GetAttachedWeaponComponent()->OnReloadValue.BindUObject(this, &UReloadBar::UpdateReloadBarValue);
		}
	}

	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UReloadBar::Hide()
{
	if (character)
	{
		if (character->GetAttachedWeaponComponent())
		{
			character->GetAttachedWeaponComponent()->OnReloadValue.Unbind();
		}
	}

	SetVisibility(ESlateVisibility::Hidden);
}

void UReloadBar::UpdateReloadBarValue(float NewValue)
{
	ReloadBar->SetPercent(NewValue);
}

void UReloadBar::NativeConstruct()
{
	Super::NativeConstruct();
	character = Cast<AUTAD_UI_FPSCharacter>(GetOwningPlayer()->GetCharacter());
	UpdateReloadBarValue(0); 
	Hide();
}
