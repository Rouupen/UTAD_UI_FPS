// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/SplashScreen.h"

void USplashScreen::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void USplashScreen::Hide()
{
	SetVisibility(ESlateVisibility::Collapsed);
}

void USplashScreen::NativeConstruct()
{
	Super::NativeConstruct();

	SetRenderOpacity(1);
	currentStartDisappearTime = 0;
	currentDisappearTime = 0;
	startAnimation = true;
	startDisappear = false;
}

void USplashScreen::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	ScreenAnimation(InDeltaTime);
}

void USplashScreen::ScreenAnimation(float InDeltaTime)
{
	if (startAnimation && !startDisappear)
	{
		if (currentStartDisappearTime >= startDisappearTime)
		{
			startDisappear = true;
			startAnimation = false;
		}
		currentStartDisappearTime += InDeltaTime;
	}

	if (startDisappear)
	{
		float opacity = FMath::Lerp(1.f, 0.f, currentDisappearTime / 1);
		currentDisappearTime += InDeltaTime;
		SetRenderOpacity(FMath::Clamp(opacity, 0, 1));

		if (opacity <= 0)
		{
			Hide();
			startDisappear = false;
		}
	}

}
