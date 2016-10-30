#include "RogueGame.h"



RogueGame::RogueGame()
{
}


RogueGame::~RogueGame()
{
}


void RogueGame::run() {

}

void RogueGame::draw() {

}



/*
GameObject
	visual
	solid
IPosition
	position
PushdownAutomata
	[...]
		AggroMob
			roaming
				attacking
					fleeing
		PassiveMob
		Player
Tile : GameObject
	visual
	solid
Mob : GameObject, IPosition, PushdownAutomata
	name
	position
Loot : GameObject, IPosition
	Item
Item
	...
GameObjectFactory
	CreateEnemy
	CreateLoot
	CreateBoss
		(CreateCritter)
		(CreatePerson)
DungeonFloor
	Tile[][] tiles
DungeonFloorFactory
	DungeonFloor(MobFactory, size, iterations)
*/