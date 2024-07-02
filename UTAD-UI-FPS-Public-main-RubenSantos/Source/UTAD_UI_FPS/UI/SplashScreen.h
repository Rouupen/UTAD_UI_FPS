// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SplashScreen.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API USplashScreen : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

public:
	UPROPERTY(EditAnywhere)
	float startDisappearTime = 3;

	UPROPERTY(EditAnywhere)
	float disappearTime = 2;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	void ScreenAnimation(float InDeltaTime);



	bool startAnimation;
	float currentStartDisappearTime;
	bool startDisappear;
	float currentDisappearTime;

};
