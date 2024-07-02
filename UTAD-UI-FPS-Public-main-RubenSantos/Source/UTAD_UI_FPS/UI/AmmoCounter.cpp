// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoCounter.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "../TP_WeaponComponent.h"
#include "Components/TextBlock.h"

void UAmmoCounter::Show()
{
	if (character)
	{
		if (character->GetAttachedWeaponComponent())
		{
			character->GetAttachedWeaponComponent()->OnBulletsChanged.BindUObject(this, &UAmmoCounter::UpdateCurrentAmmo);
		}
	}
	
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UAmmoCounter::Hide()
{
	if (character)
	{
		if (character->GetAttachedWeaponComponent())
		{
			character->GetAttachedWeaponComponent()->OnBulletsChanged.Unbind();
		}
	}

	SetVisibility(ESlateVisibility::Hidden);
}

void UAmmoCounter::NativeConstruct()
{
	Super::NativeConstruct();
	character = Cast<AUTAD_UI_FPSCharacter>(GetOwningPlayer()->GetCharacter());
	Hide();
}

void UAmmoCounter::UpdateCurrentAmmo(int totalAmmo, int currentAmmo)
{
	TotalAmmo->SetText(FText::FromString(FString::Printf(TEXT("%d"), totalAmmo)));
	CurrentAmmo->SetText(FText::FromString(FString::Printf(TEXT("%d"), currentAmmo)));
}