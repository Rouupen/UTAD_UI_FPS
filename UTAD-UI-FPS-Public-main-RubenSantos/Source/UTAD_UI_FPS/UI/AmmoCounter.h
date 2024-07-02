// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AmmoCounter.generated.h"

/**
 * 
 */

class AUTAD_UI_FPSCharacter;

UCLASS()
class UTAD_UI_FPS_API UAmmoCounter : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* CurrentAmmo;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TotalAmmo;

protected:
	virtual void NativeConstruct() override;

private:
	void UpdateCurrentAmmo(int TotalAmmo, int CurrentAmmo);

	UPROPERTY(Transient)
	AUTAD_UI_FPSCharacter* character;
};
