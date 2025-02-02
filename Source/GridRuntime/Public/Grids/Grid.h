#pragma once

#include "CoreMinimal.h"
#include "Info/GridInfo.h"
#include "Grid.generated.h"

class UGridSubsystem;
class UGridPainter;

UENUM(BlueprintType)
enum class EGridType : uint8
{
	Unknown,
	Square,
	Hexagon
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVisibilityChanged,bool,bVisible);

/**
*
*/
UCLASS(Transient, Blueprintable)
class GRIDRUNTIME_API UGrid : public UBaseObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Grid")
	FOnVisibilityChanged OnVisibilityChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Grid")
	EGridType GridType;

	UPROPERTY(BlueprintReadOnly, Category = "Grid")
	FBoxSphereBounds Bounds;

	UPROPERTY(BlueprintReadOnly, Category = "Grid")
	float Height;

	UPROPERTY(BlueprintReadOnly, Category = "Grid")
	UGridInfo* GridInfo;

	UPROPERTY(BlueprintReadOnly, Category = "Grid")
	UGridSubsystem* GridSubsystem;

	FIntVector Coord;

protected:

	bool bVisible;

	float GridSize;

	friend class UGridSubsystem;
	friend class UGridPainter;

private:

public:

	UGrid();
	virtual ~UGrid() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Grid")
	void BeginPlay();
	virtual void BeginPlay_Implementation();

	UFUNCTION(BlueprintCallable, Category = "Grid")
	virtual FVector GetCenter() const;

	UFUNCTION(BlueprintCallable, Category = "Grid")
	virtual void SetGridSize(float Size);

	UFUNCTION(BlueprintCallable, Category = "Grid")
	virtual float GetGridSize() const;

	UFUNCTION(BlueprintCallable, Category = "Grid")
	virtual bool Equal(const UGrid* R) const;

	UFUNCTION(BlueprintCallable, Category = "Grid")
	virtual void SetVisibility(bool bNewVisibility);

	UFUNCTION(BlueprintCallable, Category = "Grid")
	virtual bool GetVisibility() const;

	UFUNCTION(BlueprintCallable, Category = "GridSubsystem")
	virtual int GetDistance(const UGrid* Dest) const;

	/**
	if line trace test can't hit any WorldStatic object, then this grid is empty
	*/
	UFUNCTION(BlueprintCallable, Category = "Grid")
	virtual bool IsEmpty() const;

	UFUNCTION(BlueprintCallable, Category = "Grid")
	virtual FIntVector GetCoord() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Grid")
	void GetNeighbors(TArray<UGrid*>& Grids);
	virtual void GetNeighbors_Implementation(TArray<UGrid*>& Grids);


protected:

private:
};
