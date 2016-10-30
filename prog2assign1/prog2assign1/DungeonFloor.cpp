#include "DungeonFloor.h"


struct rect {
	int _x;
	int _y;
	int _w;
	int _h;
	rect(int x = 0, int y = 0, int w = 0, int h = 0) {
		_x = x;
		_y = y;
		_w = w;
		_h = h;
	}

	bool intersects(rect r) {
		return (abs(r._x - _x) < (r._w + _w) / 2) &&
			(abs(r._y - _y) < (r._h + _h) / 2);
	}
};


DungeonFloor::DungeonFloor()
{
	int size = 5;
	int iterations = 10;


}


DungeonFloor::~DungeonFloor()
{
}


void DungeonFloor::print() const {
	for (std::vector<Tile> v : tiles) {
		for (Tile t : v) {
			std::cout << t.getVisual();
		}
		std::cout << "\n";
	}
}