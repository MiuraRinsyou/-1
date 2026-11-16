#include "DxLib.h"
#include "../../Scene/SceneManager.h"
#include "../../Map/MapManager.h"
#include "../../Player/Player.h"
#include "../../Camera/Camera.h"
#include "../../Collision/Collision.h"
#include "../../BackGround/BackGround.h"

#define BACK_GROUND_SPEED (-1.5f)

void InitPlayScene()
{
	InitBackGround();	

	InitPlayer();

	InitMap();

	InitCamera();
}

void LoadPlayScene()
{
	LoadBackGround("Data/Map/StageBG.png", BACK_GROUND_LAYER_1);

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
	StepBackGround();

	StepPlayer();

	StepCamera();
}

void UpdatePlayScene()
{
	UpdateBackGround();

	UpdatePlayer();

	CheckCollision();
}

void DrawPlayScene()
{
	DrawBackGround();

	DrawCamera();

	DrawMap();

	DrawPlayer();
}

void FinPlayScene()
{
	FinBackGround();

	FinMap();

	FinPlayer();
}
