#include "MapManager.h"
#include "MapParameter.h"
#include "MapChip.h"
#include "Block.h"
#include "../Player/Player.h"

#define CHECK_ROUND_NUM (2)

float GetSlopeSurface(MapChipType type,
	int tileX,
	int tileY,
	float worldX)
{
	float localX = worldX - tileX * MAP_CHIP_WIDTH;

	if (localX < 0.0f)
		localX = 0.0f;

	if (localX > MAP_CHIP_WIDTH)
		localX = MAP_CHIP_WIDTH;

	float rate = localX / MAP_CHIP_WIDTH;

	switch (type)
	{
	case SLOPE_RIGHT:
		return tileY * MAP_CHIP_HEIGHT
			+ MAP_CHIP_HEIGHT * (1.0f - rate);
	case SLOPE_LEFT:
		return tileY * MAP_CHIP_HEIGHT
			+ MAP_CHIP_HEIGHT * rate;
	}

	return 0;
}

void InitMap()
{
	InitBlock();
}

void LoadMap()
{
	LoadMapChipData();
	
	LoadBlock();


}

void StartMap()
{
	CreateMap();
}

void DrawMap()
{
	DrawBlock();
}

void FinMap()
{
}

void CheckMapPlayerCollision()
{
	PlayerData player = GetPlayer();

	int playerX = (int)(player.posX / MAP_CHIP_WIDTH);
	int playerY = (int)(player.posY + PLAYER_HEIGHT / MAP_CHIP_HEIGHT);

	int left = playerX - CHECK_ROUND_NUM;
	int top = playerY - CHECK_ROUND_NUM;

	int right = playerX + CHECK_ROUND_NUM;
	int bottom = playerY + CHECK_ROUND_NUM;

	for (int y = top; y <= bottom; y++)
	{
		if (y < 0 || y >= MAP_CHIP_Y_NUM)continue;

		for (int x = left; x <= right; x++)
		{
			if (x < 0 || x >= MAP_CHIP_X_NUM)continue;

			MapChipData mapChipData = GetMapChipData(x, y);
			switch (mapChipData.mapChip)
			{
			case NORMAL_BLOCK:
				PlayerHitNormalBlockX(mapChipData);
				break;
			}
		}
	}

	for (int y = top; y <= bottom; y++)
	{
		if (y < 0 || y >= MAP_CHIP_Y_NUM)continue;

		for (int x = left; x <= right; x++)
		{
			if (x < 0 || x >= MAP_CHIP_X_NUM)continue;

			MapChipData mapChipData = GetMapChipData(x, y);
			switch (mapChipData.mapChip)
			{
			case NORMAL_BLOCK:
				PlayerHitNormalBlockY(mapChipData);
				break;
			case SLOPE_RIGHT:
			case SLOPE_LEFT:
				PlayerHitSlope((MapChipType)mapChipData.mapChip), x, y);
				break;
			}
		}
	}
}

