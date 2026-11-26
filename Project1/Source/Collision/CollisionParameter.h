#pragma once

struct  BlockData;

struct Body
{
	bool isAir;
	VECTOR pos;
	VECTOR move;
	float width;
	float height;
	float prevPosX;
	float prevPosY;
	const BlockData* groundBlock;
};
