// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHealthBar.h"
#include "Kismet/GameplayStatics.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Components/ProgressBar.h"
#include "Math/Color.h"
#include "Styling/SlateColor.h"

#define BLINK_ANIMATION_TIME 1.f
#define BLINK_THRESHOLD 0.25f

void UPlayerHealthBar::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UPlayerHealthBar::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerHealthBar::NativeConstruct()
{
	Super::NativeConstruct();

	originalColor = PlayerHealthBar->GetWidgetStyle().FillImage.TintColor; //Save original color

	AUTAD_UI_FPSCharacter* character = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (character)
	{
		character->OnHealthUpdated.BindUObject(this, &UPlayerHealthBar::UpdatePlayerHealthBar);
	}
}

void UPlayerHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	BarSmoothAniamtion(InDeltaTime);
	LowHealthBlink(InDeltaTime);
}

void UPlayerHealthBar::UpdatePlayerHealthBar(int NewHealth, int MaxHealth)
{
	currentHealthPercentage = static_cast<float>(NewHealth) / static_cast<float>(MaxHealth);

	bIsLowHealth = currentHealthPercentage <= BLINK_THRESHOLD ? true : false;

	if (!bIsLowHealth)
	{
		FProgressBarStyle progressBarStyle = PlayerHealthBar->GetWidgetStyle();

		progressBarStyle.FillImage.TintColor = originalColor; //Original color

		PlayerHealthBar->SetWidgetStyle(progressBarStyle);
	}
}

void UPlayerHealthBar::LowHealthBlink(float InDeltaTime)
{
	if (bIsLowHealth)
	{
		FProgressBarStyle progressBarStyle = PlayerHealthBar->GetWidgetStyle();
		
		if (bBlinkTurningRed && BlinkTimer == 0)
		{
			progressBarStyle.FillImage.TintColor = redColor; //Red
		}
		else if (BlinkTimer == 0)
		{
			progressBarStyle.FillImage.TintColor = originalColor; //Original color
		}

		BlinkTimer += InDeltaTime;

		if (BlinkTimer >= BLINK_ANIMATION_TIME)
		{
			BlinkTimer = 0.f;
			bBlinkTurningRed = !bBlinkTurningRed;
		}
		
		PlayerHealthBar->SetWidgetStyle(progressBarStyle);
	}
}

void UPlayerHealthBar::BarSmoothAniamtion(float InDeltaTime)
{
	PlayerHealthBar->SetPercent(FMath::Lerp(PlayerHealthBar->GetPercent(), currentHealthPercentage, barVelocity * InDeltaTime));
}
