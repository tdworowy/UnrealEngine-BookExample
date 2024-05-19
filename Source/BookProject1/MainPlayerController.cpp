// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayerController.h"
#include "Blueprint/UserWIdget.h"

void AMainPlayerController::BeginPlay() {
  Super::BeginPlay();
  if (HUDOverlayAsset) {
    HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
    HUDOverlay->AddToViewport();
    HUDOverlay->SetVisibility(ESlateVisibility::Visible);

    if (WPauseMenu) {
      PauseMenu = CreateWidget<UUserWidget>(this, WPauseMenu);
      if (PauseMenu) {
        PauseMenu->AddToViewport();
        PauseMenu->SetVisibility(ESlateVisibility::Hidden);
      }
    }
  }
}
// It is ok
void AMainPlayerController::DisplayPauseMenu_Implementation() {
  if (PauseMenu) {
    bPauseMenuVisible = true;
    PauseMenu->SetVisibility(ESlateVisibility::Visible);

    FInputModeGameAndUI InputModeGameAndUI;
    SetInputMode(InputModeGameAndUI);

    bShowMouseCursor = true;
  }
}
void AMainPlayerController::RemovePauseMenu_Implementation() {
  if (PauseMenu) {
    PauseMenu->SetVisibility(ESlateVisibility::Hidden);
    bShowMouseCursor = false;
    bPauseMenuVisible = false;

    FInputModeGameOnly InputModeGameOnly;
    SetInputMode(InputModeGameOnly);
  }
}
void AMainPlayerController::TogglePauseMenu() {
  if (bPauseMenuVisible) {
    RemovePauseMenu();
  } else {
    DisplayPauseMenu();
  }
}