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
	if (IsInputKey(KEY_D))
	{
		g_CameraData.pos.y += DEBUG_CAMERA_SPEED;
	}

	PlayerData player = GetPlayer();

	g_CameraData.pos.y = player.posY - 650.0f;
}

void DrawCamera()
{

}

CameraData GetCamera()
{
	return g_CameraData;
}