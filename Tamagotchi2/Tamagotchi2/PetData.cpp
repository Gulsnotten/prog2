#include "PetData.h"


const int PetData::_MAX_STAT = 5;



PetData::PetData(std::string name) : _name(name), _food(_MAX_STAT), _hp(_MAX_STAT),
									_bowels(0), _poops(0), _happiness(_MAX_STAT / 2 + 1)
{
}

PetData::~PetData()
{
}


void PetData::ChangeStat(int &stat, int change) {
	stat += change;
	if (stat > PetData::_MAX_STAT) {
		stat = PetData::_MAX_STAT;
	}
	if (stat < 0) {
		stat = 0;
	}
}


void PetData::ChangeFood(int change)
{
	ChangeStat(_food, change);
}

void PetData::ChangeHP(int change)
{
	ChangeStat(_hp, change);
}

void PetData::ChangeBowels(int change)
{
	ChangeStat(_bowels, change);
}

void PetData::ChangePoops(int change)
{
	ChangeStat(_poops, change);
}

void PetData::ChangeHappiness(int change)
{
	ChangeStat(_happiness, change);
}

int PetData::GetFood()
{
	return _food;
}
int PetData::GetHP()
{
	return _hp;
}
int PetData::GetBowels()
{
	return _bowels;
}
int PetData::GetPoops()
{
	return _poops;
}
int PetData::GetHappiness()
{
	return _happiness;
}


Health PetData::GetHealth() {
	if (_hp <= 0 || _food <= 0) {
		return Health::dead;
	}
	else if (_hp >= 3) {
		return Health::healthy;
	}
	else
		return Health::sick;
}

bool PetData::isHungry() {
	return _food <= 2;
}
Mood PetData::GetMood() {
	if (_happiness >= 0 && _happiness <= 1) {
		return Mood::hate;
	}
	if (_happiness > 1 && _happiness <= 3) {
		return Mood::uncertain;
	}

	//_happiness > 3
	return Mood::happy;
}

std::string PetData::GetName() {
	return _name;
}