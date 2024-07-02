// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHealthBar.h"

#include "Components/ProgressBar.h"

void UEnemyHealthBar::UpdateEnemyHealthBarValue(int Value, int MaxValue)
{
	currentHealthPercentage = (float)Value / (float)MaxValue;
}

void UEnemyHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	BarSmoothAniamtion(InDeltaTime);
}

void UEnemyHealthBar::BarSmoothAniamtion(float InDeltaTime)
{
	EnemyHealthBar->SetPercent(FMath::Lerp(EnemyHealthBar->GetPercent(), currentHealthPercentage, barVelocity * InDeltaTime));
}