#include "DxLib.h"
#include "../../Scene/SceneManager.h"
#include "../../Map/MapManager.h"


void InitPlayScene()
{
	InitMap();
}

void LoadPlayScene()
{
	LoadMap();
}

void StartPlayScene()
{
	StartMap();
}

void StepPlayScene()
{
}

void UpdatePlayScene()
{
}

void DrawPlayScene()
{
	DrawMap();
}

void FinPlayScene()
{
	FinMap();
}
