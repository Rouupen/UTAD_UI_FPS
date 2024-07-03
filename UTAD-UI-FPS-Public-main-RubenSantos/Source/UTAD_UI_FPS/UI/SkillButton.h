// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "SkillButton.generated.h"

/**
 * 
 */
class USkillTree;

UCLASS()
class UTAD_UI_FPS_API USkillButton : public UButton
{
	GENERATED_BODY()
	
	UFUNCTION()
	void SkillClick();
public:
	void Initialize(USkillTree* instance);

	UPROPERTY(EditAnywhere)
	int skillPointsCost = 1;
private:
	USkillTree* skillTreeInstance;
};
