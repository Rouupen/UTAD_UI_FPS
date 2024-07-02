// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/PlayerHitMarker.h"

#include "../UTAD_UI_FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerHUD.h"

void UPlayerHitMarker::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UPlayerHitMarker::Hide()
{
	SetVisibility(ESlateVisibility::Collapsed);
}

void UPlayerHitMarker::ReceiveHit(float currentHealthPercentage)
{
	if (currentHealthPercentage != 1)
	{
		opacityPercentage = 1 - currentHealthPercentage;
		SetRenderOpacity(opacityPercentage);

		hitReceived = true;
		startDisappear = false;
		currentStartDisappearTime = 0;
		currentDisappearTime = 0;
	}
}

void UPlayerHitMarker::NativeConstruct()
{
	Super::NativeConstruct();

	character = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	SetRenderOpacity(0);
}

void UPlayerHitMarker::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	HitAnitmation(InDeltaTime);
}

void UPlayerHitMarker::HitAnitmation(float InDeltaTime)
{
	if (hitReceived && !startDisappear)
	{
		if (currentStartDisappearTime >= startDisappearTime)
		{
			startDisappear = true;
			hitReceived = false;
		}
		currentStartDisappearTime += InDeltaTime;
	}

	if (startDisappear)
	{
		float opacity = FMath::Lerp(opacityPercentage, 0, currentDisappearTime / disappearTime);
		currentDisappearTime += InDeltaTime;
		SetRenderOpacity(FMath::Clamp(opacity, 0, 1));

		if (opacity <= 0)
		{
			startDisappear = false;
		}
	}
}
