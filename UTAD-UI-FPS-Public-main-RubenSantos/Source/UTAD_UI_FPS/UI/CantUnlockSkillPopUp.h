// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CantUnlockSkillPopUp.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UCantUnlockSkillPopUp : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* OkeyButton;

protected:
	virtual void NativeConstruct() override;
};
