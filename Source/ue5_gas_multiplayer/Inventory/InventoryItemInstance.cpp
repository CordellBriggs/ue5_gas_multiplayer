﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryItemInstance.h"

#include "Net/UnrealNetwork.h"

void UInventoryItemInstance::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(UInventoryItemInstance, ItemStaticDataClass);
    DOREPLIFETIME(UInventoryItemInstance, bEquipped);
}

void UInventoryItemInstance::Init(TSubclassOf<UItemStaticData> InItemStaticDataClass)
{
    ItemStaticDataClass = InItemStaticDataClass;
}

void UInventoryItemInstance::OnRep_Equipped()
{
    if (bEquipped)
    {
        OnEquipped();
    }
    else
    {
        OnUnequipped();
    }
}
