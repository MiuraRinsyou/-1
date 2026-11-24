#pragma once
#include "DxLib.h"

#define BLOCK_MAX (9000)
#define MAP_CHIP_X_NUM (32)
#define MAP_CHIP_Y_NUM (204)
#define MAP_CHIP_WIDTH (50)
#define MAP_CHIP_HEIGHT (50)

enum MapChipType
{
	MAP_CHIP_NONE = 0,
	// ëêÇÃìπ
	NORMAL_BLOCK,
	// âEéŒÇﬂÇÃç‚
	SLOPE_RIGHT,
	// ç∂éŒÇﬂÇÃç‚
	SLOPE_LEFT,
	// ìyÇÃìπ
	SOIL_BLOCK,
	// åÑä‘Ç§Çﬂ
	GAP_SOIL_BLOCK,
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