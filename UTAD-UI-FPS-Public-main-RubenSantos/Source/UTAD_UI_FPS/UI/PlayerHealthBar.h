// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHealthBar.generated.h"

/**
 *
 */
UCLASS()
class UTAD_UI_FPS_API UPlayerHealthBar : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* PlayerHealthBar;

	UPROPERTY(EditAnywhere)
	float barVelocity = 10;

protected:

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:

	float BlinkTimer = 0.f;
	bool bIsLowHealth = false;
	bool bBlinkTurningRed = true;
	void UpdatePlayerHealthBar(int NewHealth, int MaxHealth);

	void LowHealthBlink(float InDeltaTime); //Need DeltaTime

	FSlateColor originalColor; //Original bar color
	FSlateColor redColor = FSlateColor(FLinearColor::Red); //Red color

	//Smooth animation
	float currentHealthPercentage = 100;
	void BarSmoothAniamtion(float InDeltaTime);
};
