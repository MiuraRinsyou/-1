#pragma once

enum InputKey
{
	KEY_SPACE = (1 << 0),	// 0x0000 0000 0001
	KEY_LEFT = (1 << 1),	// 0x0000 0000 0010
	KEY_RIGHT = (1 << 2),	// 0x0000 0000 0100
	KEY_D = (1 << 3),
};

void InitInput();
void UpdateInput();
void DrawInput();
void FinInput();

bool IsInputKey(InputKey key);		// キー入力判定
bool IsTriggerKey(InputKey key);	// キー押した瞬間判定