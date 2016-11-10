#pragma once

enum Mood { hate, uncertain, happy };

class PetData
{
	static const int MAX_STAT = 5;
public:
	PetData();
	~PetData();
	int _food;
	int _health;
	int _bowels;
	int _poops;
	int _happiness;

	void Eat() {

	}
	void UpdateStats() {
		ChangeStat(_food, -1);
		if (_bowels == MAX_STAT) {
			ChangeStat(_poops, 1);
			_bowels = 0;
		}
		if (_poops > 0) {
			_health -= _poops;
		}
		ChangeStat(_happiness, -1);
	}
	void 

	bool isDead() {
		return _health <= 0 || _food <= 0;
	}
	bool isHungry() {
		return _food <= 2;
	}
	bool getMood() {
		if (_happiness > 0 && _happiness <= 1) {
			return Mood::hate;
		}
		if (_happiness > 1 && _happiness <= 3) {
			return Mood::uncertain;
		}
		if (_happiness > 3) {
			return Mood::happy;
		}
	}
	void ChangeStat(int &stat, int change) {
		stat += change;
		if (stat > PetData::MAX_STAT) {
			stat = PetData::MAX_STAT;
		}
		if (stat < 0) {
			stat = 0;
		}
	}
};