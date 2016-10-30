#include "Tile.h"



Tile::Tile()
{
}


Tile::~Tile()
{
}

std::string Tile::getVisual() const {
	return visual;
}

bool Tile::isSolid() const {
	return solid;
}