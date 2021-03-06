// Fill out your copyright notice in the Description page of Project Settings.


#include "AWeapon.h"
#include "Net/UnrealNetwork.h"

AAWeapon::AAWeapon() 
{
	ItemType = BaseItemType::Weapon;
	bReplicates = true;

	// 서버만 아이템을 스폰하도록 설정
	if (HasAuthority()) 
	{
		int32 Random = FMath::RandRange(0, 3);
		RandomSpawn(Random);
	}
}

void AAWeapon::NotifyActorBeginOverlap(AActor* OtherActor)
{
	UE_LOG(Pro4, Log, TEXT("Weapon is overlapping."));
}

void AAWeapon::RandomSpawn_Implementation(int32 Random)
{
	CurrentWeapon = static_cast<WeaponType>(Random);

	switch (CurrentWeapon)
	{
	case AAWeapon::WeaponType::AR:
	{
		UE_LOG(Pro4, Log, TEXT("AR is spawned."));

		static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Weapon(TEXT("/Game/FPS_Weapon_Bundle/Weapons/Meshes/AR4/SM_AR4_X.SM_AR4_X"));
		if (SM_Weapon.Succeeded())
		{
			BoxMesh->SetStaticMesh(SM_Weapon.Object);
		}
	}
		break;
	case AAWeapon::WeaponType::SR:
	{
		UE_LOG(Pro4, Log, TEXT("SR is spawned."));

		static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Weapon(TEXT("/Game/FPS_Weapon_Bundle/Weapons/Meshes/KA_Val/SM_KA_Val.SM_KA_Val"));
		if (SM_Weapon.Succeeded())
		{
			BoxMesh->SetStaticMesh(SM_Weapon.Object);
		}
	}
		break;
	case AAWeapon::WeaponType::Pistol:
	{
		UE_LOG(Pro4, Log, TEXT("Pistol is spawned."));

		static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Weapon(TEXT("/Game/FPS_Weapon_Bundle/Weapons/Meshes/SMG11/SM_SMG11.SM_SMG11"));
		if (SM_Weapon.Succeeded())
		{
			BoxMesh->SetStaticMesh(SM_Weapon.Object);
		}
	}
		break;
	case AAWeapon::WeaponType::Knife:
	{
		UE_LOG(Pro4, Log, TEXT("Knife is spawned."));

		static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Weapon(TEXT("/Game/FPS_Weapon_Bundle/Weapons/Meshes/M9_Knife/SM_M9_Knife.SM_M9_Knife"));
		if (SM_Weapon.Succeeded())
		{
			BoxMesh->SetStaticMesh(SM_Weapon.Object);
		}
	}
		break;
	}
}
