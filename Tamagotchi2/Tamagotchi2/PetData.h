#pragma once
#include <string>
#include <iostream>

enum Mood { hate, uncertain, happy };
enum Health { healthy, sick, dead};

class PetData
{
	static const int
		_MAX_STAT = 5,
		_FOOD_STEP = 3,
		_BOWEL_STEP = 2,
		_HAPPINESS_STEP = 3,
		
		_HEALTH_REGEN_HAPPY = _MAX_STAT,
		_HEALTH_REGEN_UNCERTAIN = 3,
		_HEALTH_REGEN_HATE = 1;

	std::string _name;
	int _food;
	int _health;
	int _bowels;
	int _poops;
	int _happiness;

	void ChangeStat(int &stat, int change);
public:
	PetData(std::string name);
	~PetData();
	
	void UpdateStats();
	void Feed();
	void Play();
	void Wash();

	void PrintStatus();

	Health GetHealth();
	bool isHungry();
	Mood GetMood();
	std::string GetName();
};