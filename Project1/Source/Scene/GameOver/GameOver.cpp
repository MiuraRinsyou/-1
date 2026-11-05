#include "DxLib.h"
#include "GameOver.h"
#include "../../BackGround/BackGround.h"
#include "../../Input/Input.h"
#include "../../Scene/SceneManager.h"

#define BACK_GROUND_SPEED (-5.0f)

#define WAIT_TIMER (300)

int g_WaitTimer = 0;

int g_GemeOverHandle = 0;

void InitGameOverScene()
{
	InitBackGround();

	g_WaitTimer = 0;
}

void LoadGameOverScene()
{
	LoadBackGround("Data/Title/BG.png", BACK_GROUND_LAYER_1);

	SetBackGroundMove(BACK_GROUND_SPEED, 0.0f, BACK_GROUND_LAYER_1);

	g_GemeOverHandle = LoadGraph("Data/GameOver/GameOver.png");
}

void StartGameOverScene()
{
	g_WaitTimer = WAIT_TIMER;
}

void StepGameOverScene()
{
	StepBackGround();

	g_WaitTimer--;
}

void UpdateGameOverScene()
{
	UpdateBackGround();

	if (g_WaitTimer <= 0 || IsTriggerKey(KEY_D))
	{
		ChangeScene(SCENE_TITLE);
	}
}

void DrawGameOverScene()
{
	StepBackGround();

	DrawGraph(500, 350, g_GemeOverHandle, TRUE);
}

void FinGameOverScene()
{
	FinBackGround();

	DeleteGraph(g_GemeOverHandle);
}
