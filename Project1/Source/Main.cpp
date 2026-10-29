#include "DxLib.h"
#include "GameSetting/GameSetting.h"
#include "Input/Input.h"
#include "Scene/SceneManager.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpOmdLine, _In_ int nShowCnd)
{
	ChangeWindowMode(TRUE);

	SetGraphMode(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_COLOR_DEPTH);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetWindowSize(SCREEN_WIDHT, SCREEN_HEIGHT);

	SetTransColor(TRANS_COLOR_R, TRANS_COLOR_G, TRANS_COLOR_B);

	SetDrawScreen(DX_SCREEN_BACK);

	InitInput();

	while (ProcessMessage() >= 0)
	{
		Sleep(1);

		ClearDrawScreen();

		UpdateInput();

		DrawInput();

		if (CheckHitKey(KEY_INPUT_ESCAPE))break;

		ScreenFlip();
	}
	FinInput();

	DxLib_End();

	return 0;
}