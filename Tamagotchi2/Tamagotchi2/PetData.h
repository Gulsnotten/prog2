#pragma once
#include <string>
#include <iostream>
#include "AbstractProduct.h"
#include <memory>

class AbstractProduct;

enum Mood { hate, uncertain, happy };
enum Health { healthy, sick, dead};

class PetData
{
	std::string _name;
public:
	static const int
		_MAX_STAT,
		_FOOD_STEP,
		_BOWEL_STEP,
		_HAPPINESS_STEP,
		_HEALTH_REGEN_HAPPY,
		_HEALTH_REGEN_UNCERTAIN,
		_HEALTH_REGEN_HATE;

	PetData(std::string name);
	~PetData();
	
	void ChangeStat(int &stat, int change);
	int _food;
	int _health;
	int _bowels;
	int _poops;
	int _happiness;

	void UpdateStats();
	void Feed(AbstractProduct* food);
	void Play();
	void Wash();

	void PrintStatus();

	Health GetHealth();
	bool isHungry();
	Mood GetMood();
	std::string GetName();
};