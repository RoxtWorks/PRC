#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::AddItem(const FString& ItemName)
{
    Items.Add(ItemName);
}

bool UInventoryComponent::RemoveItem(const FString& ItemName)
{
    return Items.RemoveSingle(ItemName) > 0;
}

int32 UInventoryComponent::CountItem(const FString& ItemName) const
{
    int32 Count = 0;
    for (const FString& Item : Items)
    {
        if (Item == ItemName) { Count++; }
    }
    return Count;
}
