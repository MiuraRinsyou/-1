#include "DxLib.h"
#include "Camera.h"
#include "../Input/Input.h"
#include "../Player/Player.h"

#define DEBUG_CAMERA_SPEED (4.0f)
#define CAMERA_SCROLL_START_X (200.0f)

CameraData g_CameraData = { 0 };

void InitCamera()
{
}

void StepCamera()
{
	if (IsInputKey(KEY_D))
	{
		g_CameraData.posX += DEBUG_CAMERA_SPEED;
	}
}

void DrawCamera()
{

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ÉJÉÅÉâÇÃç¿ïW=[%f. %f]", g_CameraData.posX, g_CameraData.posY);
}

CameraData GetCamera()
{
	return g_CameraData;
}