// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro4PlayerController.h"

void APro4PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// SetInputMode�� FInputModeGameAndUI�� �־��ָ�
	// ���Ӱ� UI ��� �Է� ������ ���°� �ȴ�.
	SetInputMode(FInputModeGameOnly());
}