// Fill out your copyright notice in the Description page of Project Settings.


#include "Crosshair.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"

void UCrosshair::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UCrosshair::Hide()
{
	SetVisibility(ESlateVisibility::Collapsed);
}

void UCrosshair::NativeConstruct()
{
	Super::NativeConstruct();

	AUTAD_UI_FPSCharacter* character = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (character)
	{
		//character->OnWeaponAttached.BindUObject(this, &UCrosshair::ShowCrosshair);
	}
	canvasSlot = Cast<UCanvasPanelSlot>(Crosshair->Slot);
	if (canvasSlot)
	{
		originalSize = canvasSlot->GetSize();
	}
	Crosshair->SetBrushTintColor(FLinearColor::Black);

}

void UCrosshair::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (canvasSlot)
	{
		animationOffset = FMath::Lerp(animationOffset, 1, 8  * InDeltaTime);
		canvasSlot->SetSize(originalSize * animationOffset);
	}
}

void UCrosshair::ShotAnimation()
{
	animationOffset += 0.75f;

	if (animationOffset > 2)
	{
		animationOffset = 2;
	}
}

void UCrosshair::SetCrosshairColor(bool color)
{
	Crosshair->SetBrushTintColor(color ? FLinearColor::Red : FLinearColor::Black);
}
