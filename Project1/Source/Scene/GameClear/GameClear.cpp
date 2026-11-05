#include "DxLib.h"
#include "GameClear.h"
#include "../../BackGround/BackGround.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"
#include <stdio.h>

#define BACK_GROUND_SPEED (-1.5)

int g_GameClearHandle = 0;

void InitGameClearScene()
{
	InitBackGround();

	g_GameClearHandle = 0;
}

void LoadGameClearScene()
{
	SetBackGroundMove(BACK_GROUND_SPEED, 0.0f, BACK_GROUND_LAYER_1);
}

void StartGameClearScene()
{
}

void StepGameClearScene()
{
	StepBackGround();

	if (IsTriggerKey(KEY_Z))
	{
		ChangeScene(SCENE_TITLE);
	}
}

void UpdateGameClearScene()
{
	UpdateBackGround();
}

void DrawGameClearScene()
{
	FinBackGround();

	DrawGraph(560, 110, g_GameClearHandle, TRUE);


}

void FinGameClearScene()
{
	FinBackGround();

	DeleteGraph(g_GameClearHandle);
}
