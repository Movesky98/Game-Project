// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ABaseItem.h"
#include "AGrenade.generated.h"

/**
 * 
 */
UCLASS()
class PRO4_API AAGrenade : public AABaseItem
{
	GENERATED_BODY()
	
public:
	AAGrenade();

	enum class GrenadeType : uint8
	{
		Grenade,	// ����ź
		Flash,		// ����ź
		Smoke,		// ����ź
		Molotov		// ȭ����
	};
	
	GrenadeType CurrentGrenade;

protected:
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void RandomSpawn();
};
