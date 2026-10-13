#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PRC_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UInventoryComponent();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<FString> Items;

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AddItem(const FString& ItemName);

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool RemoveItem(const FString& ItemName);

    UFUNCTION(BlueprintPure, Category = "Inventory")
    int32 CountItem(const FString& ItemName) const;
};
