#pragma once

#include "CoreMinimal.h"
#include "EdMode.h"
#include "Settings/SquareGridSettings.h"
#include "Settings/HexagonGridSettings.h"

class UGridSubsystem;
class UHexagonGridSubsystem;
class USquareGridSubsystem;
class UGrid;

class FEdModeGridEditor : public FEdMode
{
public:
	FEdModeGridEditor();
	virtual ~FEdModeGridEditor();

	virtual bool UsesToolkits() const override;
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;

	virtual void ActorMoveNotify() override;
	virtual void ActorPropChangeNotify() override;
	virtual void ActorSelectionChangeNotify() override;

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	UGridSubsystem* GetGridSubsystem();

	void SetCurrentMode(FName ModeName);
	FName GetCurrentMode();

	void OnSettingsChanged(const FPropertyChangedEvent& PropertyChangedEvent);

public:
	USquareGridSettings* SquareGridSettings;
	UHexagonGridSettings* HexagonGridSettings;

private:
	void OnNewCurrentLevel();
	void OnMapChanged(uint32 Event);
	void OnBeginPIE(bool bIsSimulating);
	void OnEndPIE(bool bIsSimulating);

	UWorld* GetEditorWorld();

	void FreeGridSubsystem();
	void ClearVisibleGrids();

	void UpdateGridSettings();
	void UpdateSquareSettings();
	void UpdateHexagonSettings();

	TSharedPtr<class FGridSensingComponentVisualizer> GetSensingCompVisualizer() const;

private:

	bool bEditorDelegateRegistered;

	FName CurrentModeName;

	TArray<UGrid*> VisibleGrids;

	UHexagonGridSubsystem* HexGridSubsystem;

	USquareGridSubsystem* SquareGridSubsystem;
};
