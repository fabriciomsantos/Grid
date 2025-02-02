#pragma once

#include "CoreMinimal.h"
#include "GridPainter/GridPainter.h"
#include "GridDecalPainter.generated.h"

/**
 * Default grid painter, using decal to visualize grids
 */
UCLASS()
class GRIDRUNTIME_API UGridDecalPainter : public UGridPainter
{
	GENERATED_BODY()
	
public:
	UGridDecalPainter();
	virtual ~UGridDecalPainter() override;
	
	virtual void TickImpl_Implementation(float DeltaTime) override;

	virtual void UpdateGridState_Implementation(UGrid* Grid) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GridDecalPainter")
	UMaterialInterface* DefaultDecalMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridDecalPainter")
	float GridDecalSizeOffset = 0.98f;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GridDecalPainter")
	UMaterialInterface* GetDecalMaterial(UGrid* Grid);
	virtual UMaterialInterface* GetDecalMaterial_Implementation(UGrid* Grid);

protected:
	virtual void UpdateDecal(UGrid* Grid);

protected:
	UPROPERTY()
	TMap<UGrid*, UDecalComponent*> Grid2Decal;
};
