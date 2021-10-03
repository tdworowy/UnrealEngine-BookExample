// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BOOKPROJECT1_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> HUDOverlayAsset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* HUDOverlay;

protected:
	virtual void BeginPlay() override;
};
