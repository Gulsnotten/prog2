#pragma once
#include "DungeonFloor.h"
class RogueGame
{
	DungeonFloor dungeonFloor;

	void draw();
public:
	RogueGame();
	~RogueGame();

	void run();
};

