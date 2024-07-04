// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../UI/SkillButton.h"

#include "SkillTree.generated.h"

/**
 *
 */

class UUnlockSkillPopUp;
class UCantUnlockSkillPopUp;
class UTextBlock;

UCLASS()
class UTAD_UI_FPS_API USkillTree : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void SwitchMenu();
protected:
	virtual void NativeConstruct() override;

public:

	//----Cada vez que compilo el blueprint pierdo la referencia y no se por que----
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TArray<USkillButton*> SpeedButtons;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TArray<USkillButton*> DamageButtons;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TArray<USkillButton*> HealthButtons;
	//-------------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> NameSpeedButtons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> NameDamageButtons;
					
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> NameHealthButtons;

	UFUNCTION()
	void TryUnlockSkill(int cost, USkillButton* button);

	UFUNCTION()
	void UnlockSkill();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Points = 3;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUnlockSkillPopUp* unlockSkillPopUp;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCantUnlockSkillPopUp* cantUnlockSkillPopUp;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TotalPoints;

private:
	UPROPERTY(Transient)
	TArray<USkillButton*> speedButtons;

	UPROPERTY(Transient)
	TArray<USkillButton*> damageButtons;

	UPROPERTY(Transient)
	TArray<USkillButton*> healthButtons;

	USkillButton* currentSkillButton;
	int currentCost;
};
