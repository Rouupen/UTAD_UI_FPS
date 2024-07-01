// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/PlayerHitMarker.h"

#include "../UTAD_UI_FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
//#include "Components/Image.h"
//#include "Components/CanvasPanelSlot.h"

void UPlayerHitMarker::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UPlayerHitMarker::Hide()
{
	SetVisibility(ESlateVisibility::Collapsed);
}

void UPlayerHitMarker::NativeConstruct()
{
	Super::NativeConstruct();

	AUTAD_UI_FPSCharacter* character = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (character)
	{
		//character->OnWeaponAttached.BindUObject(this, &UCrosshair::ShowCrosshair);
	}
	//canvasSlot = Cast<UCanvasPanelSlot>(Crosshair->Slot);
	//if (canvasSlot)
	//{
	//	originalSize = canvasSlot->GetSize();
	//}
	//Crosshair->SetBrushTintColor(FLinearColor::Black);

}

void UPlayerHitMarker::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	//if (canvasSlot)
	//{
	//	animationOffset = FMath::Lerp(animationOffset, 1, 8 * InDeltaTime);
	//	canvasSlot->SetSize(originalSize * animationOffset);
	//}
}
