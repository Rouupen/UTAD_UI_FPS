// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHitMarker.generated.h"

/**
 * 
 */

class AUTAD_UI_FPSCharacter;
UCLASS()
class UTAD_UI_FPS_API UPlayerHitMarker : public UUserWidget
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

public:
	UPROPERTY(EditAnywhere)
	float startDisappearTime = 1;

	UPROPERTY(EditAnywhere)
	float disappearTime = 1;

	void ReceiveHit(float currentHealthPercentage);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:

	void HitAnitmation(float InDeltaTime);

	UPROPERTY(Transient)
	AUTAD_UI_FPSCharacter* character;

	float opacityPercentage;

	bool hitReceived;
	float currentStartDisappearTime;
	bool startDisappear;
	float currentDisappearTime;

};
