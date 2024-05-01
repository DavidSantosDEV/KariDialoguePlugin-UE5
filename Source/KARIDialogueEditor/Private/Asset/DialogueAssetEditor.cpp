// Fill out your copyright notice in the Description page of Project Settings.


#include "Asset/DialogueAssetEditor.h"

#include "DialogueAsset.h"
#include "Internationalization/Text.h"

#define LOCTEXT_NAMESPACE "DialogueAssetEditor"

const FName FDialogueAssetEditor::GraphTabId(TEXT("Dialogue Graph"));
const FName FDialogueAssetEditor::NodeSearchTabId(TEXT("Node Search"));
const FName FDialogueAssetEditor::DetailsTabId(TEXT("Asset Details"));

void FDialogueAssetEditor::CreateEditorWidgets()
{
	//Details Panel
	FDetailsViewArgs Args;
	Args.bHideSelectionTip = true;
	Args.bShowPropertyMatrixButton = false;
	Args.DefaultsOnlyVisibility = EEditDefaultsOnlyNodeVisibility::Hide;
	Args.NotifyHook = this;

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	DetailsView = PropertyModule.CreateDetailView(Args);
	DetailsView->SetIsPropertyEditingEnabledDelegate(FIsPropertyEditingEnabled::CreateStatic(&FDialogueAssetEditor::CanEditAsset));
	DetailsView->SetObject(DialogueAsset);
}

bool FDialogueAssetEditor::CanEditAsset()
{
	//Todo: Maybe check what is needed to allow editing in the future, for now allow either way.
	return true;
}


void FDialogueAssetEditor::InitToolKit(UDialogueAsset* InDialogueAsset, UObject* UnCastObject)
{
    DialogueAsset = InDialogueAsset;
	GEditor->RegisterForUndo(this);

	CreateEditorWidgets();

	const TSharedRef<FTabManager::FLayout> WindowLayout = FTabManager::NewLayout("KariDialogueEditor_Layout")->AddArea
	(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Horizontal)
		->Split
		(
			FTabManager::NewStack()
			->SetSizeCoefficient(0.2f)
			->AddTab(DetailsTabId, ETabState::OpenedTab)
		)
		->Split
		(
			FTabManager::NewSplitter()
			->SetSizeCoefficient(0.65f)
			->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.8f)
				->SetHideTabWell(true)
				->AddTab(GraphTabId, ETabState::OpenedTab)
			)
		)
		->Split
		(
			FTabManager::NewStack()
			->SetSizeCoefficient(0.125f)
			->AddTab(NodeSearchTabId, ETabState::OpenedTab)
		)
	);


	InitAssetEditor(EToolkitMode::Standalone, {}, TEXT("KariDialogueEditorApp"), WindowLayout, true, true, UnCastObject);
	RegenerateMenusAndToolbars();
}

void FDialogueAssetEditor::CreateToolBar()
{
	FName ParentToolbarName;
	const FName ToolBarName = GetToolMenuToolbarName(ParentToolbarName);

	UToolMenus* ToolMenus = UToolMenus::Get();
	UToolMenu* FoundMenu = ToolMenus->FindMenu(ToolBarName);
	if (!FoundMenu || !FoundMenu->IsRegistered())
	{
		FoundMenu = ToolMenus->RegisterMenu(ToolBarName, ParentToolbarName, EMultiBoxType::ToolBar);
	}

	if (FoundMenu)
	{
		//AssetToolbar = MakeShareable(new FFlowAssetToolbar(SharedThis(this), FoundMenu));
	}
}

void FDialogueAssetEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkSpaceMenu_KariDialogueEditor", "Kari Dialogue Editor"));
	const TSharedRef<FWorkspaceItem> MenuCategoryReference  = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(DetailsTabId, FOnSpawnTab::CreateSP(this, &FDialogueAssetEditor::SpawnTabDetails))
		.SetDisplayName(LOCTEXT("DetailsTab", "Details"))
		.SetGroup(MenuCategoryReference)
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details"));

	/*
	TabManager->RegisterTabSpawner(GraphTab, FOnSpawnTab::CreateSP(this, &FFlowAssetEditor::SpawnTab_Graph))
		.SetDisplayName(LOCTEXT("GraphTab", "Graph"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "GraphEditor.EventGraph_16x"));*/

	/*
	TabManager->RegisterTabSpawner(NodeSearchTabId, FOnSpawnTab::CreateSP(this, &FDialogueAssetEditor::SpawnTabSearch))
		.SetDisplayName(LOCTEXT("PaletteTab", "Palette"))
		.SetGroup(MenuCategoryReference)
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "Kismet.Tabs.Palette"));*/
}

void FDialogueAssetEditor::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	TabManager->UnregisterTabSpawner(DetailsTabId);
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
}

TSharedRef<SDockTab> FDialogueAssetEditor::SpawnTabDetails(const FSpawnTabArgs& Args) const
{
	check(Args.GetTabId() == DetailsTabId);

	return SNew(SDockTab)
		.Label(LOCTEXT("DialogueDetailsTitle", "Details"))
		[
			DetailsView.ToSharedRef()
		];
}

TSharedRef<SDockTab> FDialogueAssetEditor::SpawnTabSearch(const FSpawnTabArgs& Args) const
{
	return SpawnTabDetails(Args);
}

TSharedRef<SDockTab> FDialogueAssetEditor::SpawnTabGraph(const FSpawnTabArgs& Args) const
{
	return SpawnTabDetails(Args);
}

FLinearColor FDialogueAssetEditor::GetWorldCentricTabColorScale() const
{
    return FLinearColor::Blue;
}

FName FDialogueAssetEditor::GetToolkitFName() const
{
    return FName("Test");
}

FText FDialogueAssetEditor::GetBaseToolkitName() const
{
    return LOCTEXT("AppLabel", "Dialogue Asset Editor");
}

FString FDialogueAssetEditor::GetWorldCentricTabPrefix() const
{
    return FString("Empty");
}

void FDialogueAssetEditor::AddReferencedObjects(FReferenceCollector& Collector)
{
}
