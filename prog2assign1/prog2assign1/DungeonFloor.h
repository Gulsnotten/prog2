#pragma once
#include <vector>
#include <string>
#include "Tile.h"
class DungeonFloor
{
	std::vector<std::vector<Tile>> tiles;
public:
	DungeonFloor();
	~DungeonFloor();

	void print() const;
};