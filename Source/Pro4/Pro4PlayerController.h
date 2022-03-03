// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pro4.h"
#include "GameFramework/PlayerController.h"
#include "Pro4PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PRO4_API APro4PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	APro4PlayerController();
	
	UFUNCTION(BlueprintCallable, Category = UMG_Game)
	void ChangeMenuWidget(TSubclassOf<class UPlayerDefaultWidget> NewWidgetClass);
	
protected:
	void BeginPlay() override;

	// ������ ���۵� �� ǥ�õ� UI ������ ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class UPlayerDefaultWidget> StartingWidgetClass;

	// ���� ȭ�鿡 ǥ�õǰ� �ִ� UI ������ �����ϰ� ���� ������ ����
	UPROPERTY()
	class UPlayerDefaultWidget* CurrentWidget;
};
