#pragma once
#include "DxLib.h"

#define BLOCK_MAX (9000)
#define MAP_CHIP_X_NUM (32)
#define MAP_CHIP_Y_NUM (210)
#define MAP_CHIP_WIDTH (50)
#define MAP_CHIP_HEIGHT (50)

enum MapChipType
{
	MAP_CHIP_NONE = 0,
	// ëêÇÃìπ
	NORMAL_BLOCK,
	// âEéŒÇﬂç‚
	SLOPE_RIGHT,
	// ç∂éŒÇﬂç‚
	SLOPE_LEFT,
	// ìyÇÃìπ
	SOIL_BLOCK,
	// åÑä‘Ç§Çﬂ
	GAP_SOIL_BLOCK,
	// ê·ÇÃínñ 
	SNOW_BLOCK,
	// ê·ÇÃâEéŒÇﬂç‚
	SNOW_RIGHT,
	// ê·ÇÃç∂éŒÇﬂç‚
	SNOW_LEFT,
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