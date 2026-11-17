#pragma once
#include "DxLib.h"

#define BLOCK_MAX (2048)
#define MAP_CHIP_X_NUM (18)
#define MAP_CHIP_Y_NUM (200)
#define MAP_CHIP_WIDTH (50)
#define MAP_CHIP_HEIGHT (50)

enum MapChipType
{
	MAP_CHIP_NONE = 0,
	// í èÌÇÃìπ
	NORMAL_BLOCK,
	// âEéŒÇﬂÇÃç‚
	SLOPE_RIGHT,
	// ç∂éŒÇﬂÇÃç‚
	SLOPE_LEFT,
	BLOCK_TYPE_MAX,
};

struct BlockData
{
	bool active;
	int handle;
	MapChipType type;
	VECTOR pos;
};

struct MapChipData
{
	int mapChip;
	BlockData* data;
};