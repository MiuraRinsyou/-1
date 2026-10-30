#include "DxLib.h"
#include "../../Scene/SceneManager.h"
#include "../../Map/MapManager.h"
#include "../../Player/Player.h"
#include "../../Camera/Camera.h"


void InitPlayScene()
{
	InitPlayer();

	InitMap();

	InitCamera();
}

void LoadPlayScene()
{
	LoadPlayer();

	LoadMap();
}

void StartPlayScene()
{
	StartPlayer();

	StartMap();
}

void StepPlayScene()
{
	StepPlayer();

	StepCamera();
}

void UpdatePlayScene()
{
	UpdatePlayer();
}

void DrawPlayScene()
{
	DrawMap();

	DrawPlayer();

	DrawCamera();
}

void FinPlayScene()
{
	FinMap();

	FinPlayer();
}
