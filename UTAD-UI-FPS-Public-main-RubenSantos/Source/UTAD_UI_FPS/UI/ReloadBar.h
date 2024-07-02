// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ReloadBar.generated.h"

/**
 * 
 */
class AUTAD_UI_FPSCharacter;
UCLASS()
class UTAD_UI_FPS_API UReloadBar : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* ReloadBar;

private:

	void UpdateReloadBarValue(float NewValue);

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(Transient)
	AUTAD_UI_FPSCharacter* character;
};
