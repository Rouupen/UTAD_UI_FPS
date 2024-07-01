// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Crosshair.generated.h"

/**
 *
 */
class UCanvasPanelSlot;
class AUTAD_UI_FPSCharacter;

UCLASS()
class UTAD_UI_FPS_API UCrosshair : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* Crosshair;

	UPROPERTY(EditAnywhere)
	float MaxCrosshairMult = 2;

	UPROPERTY(EditAnywhere)
	float AddMultSize = 0.75f;

	UPROPERTY(EditAnywhere)
	float MaxEnemyDetectionDistance = 5000;

	UPROPERTY(EditAnywhere)
	float CrosshairAnimVelocity= 8;

	void IncrementCrosshairSize();
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	
private:

	void EnemyHit(bool enemyHit);
	FVector2D originalSize;
	float animationOffset = 0;

	UPROPERTY(Transient)
	UCanvasPanelSlot* canvasSlot;
	
	UPROPERTY(Transient)
	AUTAD_UI_FPSCharacter* character;
};
