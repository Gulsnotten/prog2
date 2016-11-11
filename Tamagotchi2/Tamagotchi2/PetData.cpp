#include "PetData.h"



PetData::PetData(std::string name)
{
	_name = name;
	_food = _MAX_STAT;
	_health = _MAX_STAT;
	_bowels = 0;
	_poops = 0;
	_happiness = _MAX_STAT / 2 + 1;
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


void PetData::Feed() {
	ChangeStat(_food, _FOOD_STEP);
	ChangeStat(_bowels, _BOWEL_STEP);
}
void PetData::Play() {
	ChangeStat(_happiness, _HAPPINESS_STEP);
}
void PetData::Wash() {
	switch (GetMood()) {
	case Mood::happy:
		ChangeStat(_health, _HEALTH_REGEN_HAPPY);
		break;
	case Mood::uncertain:
		ChangeStat(_health, _HEALTH_REGEN_UNCERTAIN);
		break;
	case Mood::hate:
		ChangeStat(_health, _HEALTH_REGEN_HATE);
		break;
	}
	
	_poops = 0;
}

void PetData::PrintStatus() {
	if (_poops > 0)
		std::cout << "There is poop lying around. ";

	switch (GetHealth()) {
	case Health::healthy:
		if (isHungry()) {
			std::cout << _name << " looks hungry.\n";
		}
		else {
			switch (GetMood()) {
			case Mood::happy:
				std::cout << _name << " looks energetic!\n";
				break;
			case Mood::uncertain:
				std::cout << _name << " is looking at you.\n";
				break;
			case Mood::hate:
				std::cout << _name << " is growling...\n";
				break;
			}
		}
		break;
	case Health::sick:
		if (isHungry()) {
			std::cout << _name << " seems to be in serious pain...\n";
		}
		else{
			std::cout << _name << " is sick.\n";
		}
		break;
	case Health::dead:
		std::cout << _name << " is not breathing.\n";
		break;
	}
}

void PetData::UpdateStats() {
	ChangeStat(_food, -1);
	if (_bowels == _MAX_STAT) {
		ChangeStat(_poops, 1);
		_bowels = 0;
	}
	if (_poops > 0) {
		_health -= _poops;
	}
	ChangeStat(_happiness, -1);
}

Health PetData::GetHealth() {
	if (_health <= 0 || _food <= 0) {
		return Health::dead;
	}
	else if (_health >= 3) {
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