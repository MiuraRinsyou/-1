#include "DxLib.h"
#include "Camera.h"
#include "../Input/Input.h"
#include "../Player/Player.h"

#define DEBUG_CAMERA_SPEED (4.0f)
#define CAMERA_SCROLL_START_X (0.0f)

CameraData g_CameraData = { 0 };

void InitCamera()
{
}

void StepCamera()
{
	/*if (IsInputKey(KEY_D))
	{
		g_CameraData.posY += DEBUG_CAMERA_SPEED;
	}*/

	PlayerData player = GetPlayer();

	g_CameraData.pos.x = player.posX - 600.0f;
	g_CameraData.pos.y = player.posY - 600.0f;
}

void DrawCamera()
{

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ÉJÉÅÉâÇÃç¿ïW=[%f. %f]", g_CameraData.pos.x, g_CameraData.pos.y);
}

CameraData GetCamera()
{
	return g_CameraData;
}