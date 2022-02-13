// Copyright Epic Games, Inc. All Rights Reserved.

#include "Pro4GameMode.h"
#include "Pro4PlayerController.h"
#include "Pro4Character.h"
#include <Blueprint/UserWidget.h>

APro4GameMode::APro4GameMode()
{
	// set default pawn class to our Blueprinted character
	DefaultPawnClass = APro4Character::StaticClass();
	PlayerControllerClass = APro4PlayerController::StaticClass();
}

void APro4GameMode::BeginPlay()
{
	Super::BeginPlay();

	// ������ ���۵� �� UI�� ǥ���ϵ��� �������.
	ChangeMenuWidget(StartingWidgetClass);
}

void APro4GameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
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
		CurrentWidget = CreateWidget(GetWorld(), NewWidgetClass);

		// ���� ����Ʈ�� ǥ���ϵ��� ������ش�.
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}
