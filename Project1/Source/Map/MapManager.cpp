#include "MapManager.h"
#include "MapParameter.h"
#include "MapChip.h"
#include "Block.h"
#include "../Player/Player.h"

#define CHECK_ROUND_NUM (2)

void InitMap()
{
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

