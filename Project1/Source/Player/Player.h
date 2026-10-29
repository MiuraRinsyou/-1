#pragma once
#include "../Map/MapParameter.h"

#define PLAYER_WIDTH (70.0f)
#define PLAYER_HEIGHT (70.0f)
#define PLAYER_RADIUS (36.0f)

struct PlayerData
{
	bool active;	// 生存フラグ
	bool isTurn;	// 左を向いているか
	bool isAir;		// 空中にいるか
	float posX;		// X座標
	float posY;		// Y座標
	float moveX;	// X移動量
	float moveY;	// Y移動量
};

void InitPlayer();
void LoadPlayer();
void StartPlayer();
void StepPlayer();
void UpdatePlayer();
void DrawPlayer();
void FinPlayer();

PlayerData* GetPlayer();

void PlayerHitNormalBlock(MapChipData mapChipData);