#include <iostream>
#pragma once
class Tile
{
	std::string visual;
	bool solid;
public:
	Tile();
	~Tile();

	std::string getVisual() const;
	bool isSolid() const;
};

