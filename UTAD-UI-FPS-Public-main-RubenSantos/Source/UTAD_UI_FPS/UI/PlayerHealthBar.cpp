// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHealthBar.h"
#include "Kismet/GameplayStatics.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Components/ProgressBar.h"
#include "Math/Color.h"
#include "Styling/SlateColor.h"

#define BLINK_ANIMATION_TIME 1.f
#define BLINK_THRESHOLD 0.25f

void UPlayerHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	BarSmoothAniamtion(InDeltaTime);
	LowHealthBlink(InDeltaTime);
}

void UPlayerHealthBar::NativeConstruct()
{
	Super::NativeConstruct();

	originalColor = PlayerHealthBar->GetWidgetStyle().FillImage.TintColor;

	AUTAD_UI_FPSCharacter* character = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (character)
	{
		character->OnHealthUpdated.BindUObject(this, &UPlayerHealthBar::UpdatePlayerHealthBar);
	}
}

void UPlayerHealthBar::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UPlayerHealthBar::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerHealthBar::UpdatePlayerHealthBar(int NewHealth, int MaxHealth)
{
	currentHealthPercentage = static_cast<float>(NewHealth) / static_cast<float>(MaxHealth);

	bIsLowHealth = currentHealthPercentage <= BLINK_THRESHOLD ? true : false;
}

void UPlayerHealthBar::LowHealthBlink(float InDeltaTime)
{
	FProgressBarStyle progressBarStyle = PlayerHealthBar->GetWidgetStyle();

	if (bIsLowHealth)
	{
		if (bBlinkTurningRed)
		{
			progressBarStyle.FillImage.TintColor = redColor; //Red
		}
		else
		{
			progressBarStyle.FillImage.TintColor = originalColor; //Original color
		}

		if (BlinkTimer >= BLINK_ANIMATION_TIME)
		{
			BlinkTimer = 0.f;
			bBlinkTurningRed = !bBlinkTurningRed;
		}

		BlinkTimer += InDeltaTime;
	}
	else
	{
		progressBarStyle.FillImage.TintColor = originalColor; //Original color
	}

	PlayerHealthBar->SetWidgetStyle(progressBarStyle);
}

void UPlayerHealthBar::BarSmoothAniamtion(float InDeltaTime)
{
	PlayerHealthBar->SetPercent(FMath::Lerp(PlayerHealthBar->GetPercent(), currentHealthPercentage, barVelocity * InDeltaTime));
}
