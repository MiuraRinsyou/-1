#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"

struct PlayerAnimationParam
{
	int interval;
	int frameNum;
	int width;
	int height;
};

const  PlayerAnimationParam PLAEYR_ANIM_PARAM[PLAYER_ANIM_MAX] =
{
	8, 4, 72, 72,
	5, 8, 72, 72,
	8, 2, 72, 72,
	8, 2, 72, 72,
	8, 1, 72, 72,
};


// プレイヤーの性能
#define PLAYER_DEFAULT_POS_X (100.0f)
#define PLAYER_DEFAULT_POS_Y (600.0f)
#define PLAYER_MOVE_SPEED (4.0f)

// ジャンプ力
#define PLAYER_JUMP_POWER (12.0f)
// 重力
#define PLAYER_GRAVITY (0.4f)

#define PLAYER_MAP_COLLISION_OFFSET (0.05f)

#define PLAYER_BOX_COLLISION_OFFSET_X (24)
#define PLAYER_BOX_COLLISION_OFFSET_Y (20)

#define PLAYER_BOX_COLLISION_WIDTH (20)
#define PLAYER_BOX_COLLISION_HEIGHT (40)

PlayerData g_PlayerData = { 0 };
PlayerData g_PrevPlayerData = { 0 };

void StartPlayerAnimation(PlayerAnimationType anim);
void UpdatePlayerAnimation();
void CalcBoxColision(PlayerData player, float& x, float& y, float& w, float& h);

void InitPlayer()
{
	g_PlayerData.posX = PLAYER_DEFAULT_POS_X;
	g_PlayerData.posY = PLAYER_DEFAULT_POS_Y;
	g_PlayerData.moveX = 0.0f;
	g_PlayerData.moveY = 0.0f;
	g_PlayerData.active = false;
	g_PlayerData.playAnim = PLAYER_ANIM_NONE;

	for (int i = 0; i < PLAYER_ANIM_MAX; i++)
	{
		InitAnimation(&g_PlayerData.animation[i]);
	}

	//memset(&g_PlayerData.boxCollision, 0, sizeof(g_PlayerData.boxCollision));
}

void LoadPlayer()
{
	g_PlayerData.animation[PLAYER_ANIM_IDLE].handle = LoadGraph("Data/Player/PlayerIdle.png");
	g_PlayerData.animation[PLAYER_ANIM_RUN].handle = LoadGraph("Data/Player/PlayerRun.png");
	g_PlayerData.animation[PLAYER_ANIM_JUMP].handle = LoadGraph("Data/Player/PlayerJunp.png");
	g_PlayerData.animation[PLAYER_ANIM_FALL].handle = LoadGraph("Data/Player/PlayerFall.png");
	g_PlayerData.animation[PLAYER_ANIM_LANDING].handle = LoadGraph("Data/Player/PlayerLanding.png");
}

void StartPlayer()
{
	g_PlayerData.active = true;

	StartPlayerAnimation(PLAYER_ANIM_IDLE);
}

void StepPlayer()
{
	if (!g_PlayerData.active)
	{
		return;
	}

	g_PrevPlayerData = g_PlayerData;

	g_PlayerData.moveX = 0.0f;

	g_PlayerData.moveY += PLAYER_GRAVITY;

	if (IsInputKey(KEY_LEFT))
	{
		g_PlayerData.moveX = -PLAYER_MOVE_SPEED;
		g_PlayerData.isTurn = true;
	}
	else if(IsInputKey(KEY_RIGHT))
	{
		g_PlayerData.moveX = PLAYER_MOVE_SPEED;
		g_PlayerData.isTurn = false;
	}

	if (IsTriggerKey(KEY_SPACE))
	{
		g_PlayerData.moveY = -PLAYER_JUMP_POWER;
	}
}

void UpdatePlayer()
{
	if (!g_PlayerData.active) return;

	if (g_PlayerData.moveY<0.0f || g_PlayerData.moveY>PLAYER_GRAVITY)
	{
		g_PlayerData.isAir = true;
	}

	g_PlayerData.posX += g_PlayerData.moveX;
	g_PlayerData.posY += g_PlayerData.moveY;

	UpdatePlayerAnimation();
}

void DrawPlayer()
{
	if (!g_PlayerData.active)return;

	CameraData camera = GetCamera();

	PlayerAnimationType animType = g_PlayerData.playAnim;
	AnimationData* animData = &g_PlayerData.animation[animType];
	DrawAnimation(animData, g_PlayerData.posX - camera.pos.x, g_PlayerData.posY - camera.pos.y, g_PlayerData.isTurn);
}

void FinPlayer()
{
	for (int i = 0; i < PLAYER_ANIM_MAX; i++)
	{
		DeleteGraph(g_PlayerData.animation[i].handle);
	}
}

PlayerData* GetPlayer()
{
	return &g_PlayerData;
}

void PlayerHitNormalBlock(MapChipData mapChipData)
{
	PlayerData player = g_PlayerData;
	BlockData* block = mapChipData.data;
	const float POS_OFFSET = PLAYER_MAP_COLLISION_OFFSET;
	const float SIZE_OFFSET = PLAYER_MAP_COLLISION_OFFSET * 2;

	player.isTurn = g_PrevPlayerData.isTurn;

	player.posX = g_PlayerData.posX;
	player.posY = g_PrevPlayerData.isTurn;

	float x, y, w, h;
	CalcBoxColision(player, x, y, w, h);

}