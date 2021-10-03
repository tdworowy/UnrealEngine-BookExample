// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"
#include "Blueprint/UserWIdget.h"
void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (HUDOverlayAsset)
	{
		HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
		HUDOverlay->AddToViewport();
		HUDOverlay->SetVisibility(ESlateVisibility::Visible);
	}
}
