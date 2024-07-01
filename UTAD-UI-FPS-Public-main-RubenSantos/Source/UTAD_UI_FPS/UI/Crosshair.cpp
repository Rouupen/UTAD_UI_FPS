// Fill out your copyright notice in the Description page of Project Settings.


#include "Crosshair.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"
#include <UTAD_UI_FPS/UTAD_UI_FPS_Enemy.h>
#include "Camera/CameraComponent.h"

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

	character = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

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

	if (canvasSlot) //Size animation
	{
		animationOffset = FMath::Lerp(animationOffset, 1, CrosshairAnimVelocity * InDeltaTime);
		canvasSlot->SetSize(originalSize * animationOffset);
	}

	//Enemy detection
	if (character->bHasRifle) 
	{
		FVector StartLocation = character->GetFirstPersonCameraComponent()->GetComponentLocation();
		FVector EndLocation = StartLocation + character->GetFirstPersonCameraComponent()->GetForwardVector() * MaxEnemyDetectionDistance;
		FHitResult OutHit;

		if (GetWorld()->LineTraceSingleByChannel(OutHit, StartLocation, EndLocation, ECC_Visibility))
		{
			AUTAD_UI_FPS_Enemy* Enemy = Cast<AUTAD_UI_FPS_Enemy>(OutHit.GetActor());

			EnemyHit(Enemy != nullptr ? true : false);
		}
		else
		{
			EnemyHit(false);
		}
	}
}

void UCrosshair::IncrementCrosshairSize()
{
	animationOffset += AddMultSize;

	if (animationOffset > MaxCrosshairMult)
	{
		animationOffset = MaxCrosshairMult;
	}
}

void UCrosshair::EnemyHit(bool enemyHit)
{
	Crosshair->SetBrushTintColor(enemyHit ? FLinearColor::Red : FLinearColor::Black);
}
