#include "ArchMoveBlock.h"
#include "MapParameter.h"
#include "../Collision/CollisionParameter.h"

#define ARCH_WIDTH (200.0f)
#define ARCH_HEIGHT (100.0f)
#define ARCH_SPEED (0.5f)

void StartArchMoveBlock(BlockData* block)
{
	block->moveX = ARCH_SPEED;
}

void StepArchMoveBlock(BlockData* block)
{
	if (block->posX > (block->startPosX + ARCH_WIDTH) || block->posX < block->startPosX)
	{
		block->moveX = -block->moveX;
	}
}

void UpdateArchMoveBlock(BlockData* block)
{
	block->posX += block->moveX;

	float x = block->startPosX;
	float y = block->startPosY;
	float h = block->startPosX + (ARCH_WIDTH * 0.5f);
	float k = block->startPosY - ARCH_HEIGHT;

	float a = (y - k) / ((x - h) * (x - h));

	block->posY = a * ((block->posX - h) * (block->posX - h)) + k;
}

void ResolveArchMoveBlockX(Body* body, const BlockData* block)
{
	if ((body->prevPosX + body->width) <= block->prevPosX)
	{
		body->pos.x -= (body->pos.x + body->height) - block->posX;
	}
	else if (body->prevPosX >= (block->prevPosX + block->width))
	{
		body->pos.x += (block->posX + block->width) - body->pos.x;
	}

	body->move.x = 0.0f;
}

void ResolveArchMoveBlockY(Body* body, const BlockData* block)
{
	if ((body->prevPosY + body->height) <= block->prevPosY)
	{
		body->pos.y -= (body->pos.y + body->height) - block->posY;

		body->isAir = false;

		body->groundBlock = block;

		body->move.y = 0.0f;
	}
}