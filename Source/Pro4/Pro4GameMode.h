// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Pro4.h"
#include "GameFramework/GameModeBase.h"
#include "Pro4GameMode.generated.h"

UCLASS()
class APro4GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APro4GameMode();

	UFUNCTION(BlueprintCallable, Category=UMG_Game)
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
	void BeginPlay() override;

	// ������ ���۵� �� ǥ�õ� UI ������ ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> StartingWidgetClass;
	
	// ���� ȭ�鿡 ǥ�õǰ� �ִ� UI ������ �����ϰ� ���� ������ ����
	UPROPERTY()
	UUserWidget* CurrentWidget;
};



