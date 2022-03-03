// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro4PlayerController.h"
#include "PlayerDefaultWidget.h"

APro4PlayerController::APro4PlayerController()
{
	static ConstructorHelpers::FClassFinder<UPlayerDefaultWidget> BP_PlayerUI(TEXT("/Game/UI/PlayerUI.PlayerUI_C"));
	if (BP_PlayerUI.Succeeded())
	{
		StartingWidgetClass = BP_PlayerUI.Class;
	}
}

void APro4PlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (IsLocalPlayerController())
	{
		// ������ ���۵� �� UI�� ǥ���ϵ��� �������.
		ChangeMenuWidget(StartingWidgetClass);

		// SetInputMode�� FInputModeGameAndUI�� �־��ָ�
		// ���Ӱ� UI ��� �Է� ������ ���°� �ȴ�.
		SetInputMode(FInputModeGameOnly());
	}
}

void APro4PlayerController::ChangeMenuWidget(TSubclassOf<class UPlayerDefaultWidget> NewWidgetClass)
{
	// ���� CurrentWidget�� ����ִ��� Ȯ��
	if (CurrentWidget != nullptr)
	{
		// ������� �ʴٸ� ȭ�鿡�� UI�� ������ �� CurrentWidget�� �����
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	// ���� �Ű� ������ ���� NewWidgetClass�� ��ȿ���� �˻�
	if (NewWidgetClass != nullptr)
	{
		// CreateWidget �Լ��� �� ������ ����� CurrentWidget�� ����
		CurrentWidget = CreateWidget<UPlayerDefaultWidget>(GetWorld(), NewWidgetClass);

		// ���� ����Ʈ�� ǥ���ϵ��� ������ش�.
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}