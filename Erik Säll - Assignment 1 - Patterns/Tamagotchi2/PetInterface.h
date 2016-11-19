#pragma once
#include "Printable.h"
#include "AbstractProduct.h"
#include "PetData.h"
#include <memory>

// alter and print data in context
class PetInterface : public Printable
{
	std::unique_ptr<PetData> _petDataPtr;
	static const int
		_FOOD_STEP,
		_BOWEL_STEP,
		_HAPPINESS_STEP,
		_HEALTH_REGEN_HAPPY,
		_HEALTH_REGEN_UNCERTAIN,
		_HEALTH_REGEN_HATE,
		_REVIVE_HP,
		_REVIVE_FOOD;

	void PrintFoodMsg(std::unique_ptr<AbstractProduct> &food);
	void PrintPlayMsg();
public:
	PetInterface(std::string name);
	~PetInterface();

	std::string GetName();
	Health GetHealth();
	Mood GetMood();

	void UpdateStats();
	void Feed(std::unique_ptr<AbstractProduct> &food);
	void Play();
	void Wash();
	void Revive();

	void PrintStatus();
};

