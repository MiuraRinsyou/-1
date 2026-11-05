#include "DxLib.h"
#include "Title.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"
#include "../../BackGround/BackGround.h"
#include <math.h>

#define BACK_GROUND_SPEED (-0.3f)

#define TITLE_POS_X (600)
#define TITLE_POS_Y (130)

#define PRESS_Z_KEY_POS_X (670)
#define PRESS_Z_KEY_POS_Y (700)

#define PRESS_Z_KEY_BLINK_SPEED (0.04f)

int g_BGHandle = 0;
int g_TitleHandle = 0;
int g_PressZKeyHandle = 0;

float g_PressZKeyAlpha = 0.0f;
float g_PressZKeyRadian = 0.0f;

void InitTitleScene()
{
	g_BGHandle = 0;
	g_TitleHandle = 0;
	g_PressZKeyHandle = 0;
	g_PressZKeyAlpha = 0.0f;
	g_PressZKeyRadian = 0.0f;

	InitBackGround();
}

void LoadTitleScene()
{
	LoadBackGround("Data/Title/TitleBG.png", BACK_GROUND_LAYER_1);

	SetBackGroundMove(BACK_GROUND_SPEED, 0.0f, BACK_GROUND_LAYER_1);

	g_BGHandle = LoadGraph("Data/Title/TitleBG.png");
	g_TitleHandle = LoadGraph("Data/Title/TitleText.png");
	g_PressZKeyHandle = LoadGraph("Data/Title/TitlePressZKey.png");
}

void StartTitleScene()
{
}

void StepTitleScene()
{
	g_PressZKeyAlpha = (sinf(g_PressZKeyRadian) + 1) / 2;

	g_PressZKeyRadian += PRESS_Z_KEY_BLINK_SPEED;

	if (g_PressZKeyRadian > DX_TWO_PI_F)
	{
		g_PressZKeyRadian -= DX_TWO_PI_F;
	}

	if (IsTriggerKey(KEY_Z))
	{
		ChangeScene(SCENE_PLAY);
	}

	StepBackGround();
}

void UpdateTitleScene()
{
	UpdateBackGround();
}

void DrawTitleScene()
{
	DrawBackGround();

	DrawGraph(TITLE_POS_X, TITLE_POS_Y, g_TitleHandle, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(g_PressZKeyAlpha * 255));

	DrawGraph(PRESS_Z_KEY_POS_X, PRESS_Z_KEY_POS_Y, g_PressZKeyHandle, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void FinTitleScene()
{
	FinBackGround();

	DeleteGraph(g_TitleHandle);
	DeleteGraph(g_PressZKeyHandle);


}
