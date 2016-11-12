#include "PetInterface.h"

const int
	PetInterface::_FOOD_STEP = 3,
	PetInterface::_BOWEL_STEP = 2,
	PetInterface::_HAPPINESS_STEP = 3,

	PetInterface::_HEALTH_REGEN_HAPPY = PetData::_MAX_STAT,
	PetInterface::_HEALTH_REGEN_UNCERTAIN = 3,
	PetInterface::_HEALTH_REGEN_HATE = 1,
	PetInterface::_REVIVE_HP = 2,
	PetInterface::_REVIVE_FOOD = 2;


void PetInterface::PrintFoodMsg(std::unique_ptr<AbstractProduct>& food)
{
	PrintLn(_petDataPtr->GetName() + " munched on the " + food->GetName());
}

void PetInterface::PrintPlayMsg()
{
	switch (GetMood()) {
	case Mood::hate:
		PrintLn(GetName() + " hesitantly played with you.");
		break;
	case Mood::uncertain:
		PrintLn(GetName() + " played with you.");
		break;
	case Mood::happy:
		PrintLn(GetName() + " played gleefully!");
		break;
	}
}

PetInterface::PetInterface(std::string name) : _petDataPtr(new PetData(name))
{
}


PetInterface::~PetInterface()
{
}

std::string PetInterface::GetName()
{
	return _petDataPtr->GetName();
}

Health PetInterface::GetHealth()
{
	return _petDataPtr->GetHealth();
}

Mood PetInterface::GetMood()
{
	return _petDataPtr->GetMood();
}


void PetInterface::Feed(std::unique_ptr<AbstractProduct> &food) {
	food->Consume(_petDataPtr);

	_petDataPtr->ChangeFood(food->GetFill());
	_petDataPtr->ChangeBowels(_BOWEL_STEP);

	PrintFoodMsg(food);
}
void PetInterface::Play() {
	PrintPlayMsg();
	_petDataPtr->ChangeHappiness(_HAPPINESS_STEP);
}
void PetInterface::Wash() {
	switch (GetMood()) {
	case Mood::happy:
		_petDataPtr->ChangeHP(_HEALTH_REGEN_HAPPY);
		break;
	case Mood::uncertain:
		_petDataPtr->ChangeHP(_HEALTH_REGEN_UNCERTAIN);
		break;
	case Mood::hate:
		_petDataPtr->ChangeHP(_HEALTH_REGEN_HATE);
		break;
	}

	_petDataPtr->ChangePoops(-PetData::_MAX_STAT);
}

void PetInterface::Revive()
{
	_petDataPtr->ChangeHP(_REVIVE_HP);
	_petDataPtr->ChangeFood(_REVIVE_FOOD);
}

void PetInterface::PrintStatus() {
	if (_petDataPtr->GetPoops() > 0) {
		Print("There is poop lying around. ");
	}

	std::string name = GetName();

	switch (GetHealth()) {
	case Health::healthy:
		if (_petDataPtr->isHungry()) {
			PrintLn(name + " looks hungry.");
		}
		else {
			switch (GetMood()) {
			case Mood::happy:
				PrintLn(name + " looks energetic!");
				break;
			case Mood::uncertain:
				PrintLn(name + " is looking at you.");
				break;
			case Mood::hate:
				PrintLn(name + " is growling...");
				break;
			}
		}
		break;
	case Health::sick:
		if (_petDataPtr->isHungry()) {
			PrintLn(name + " seems to be in serious pain...");
		}
		else {
			PrintLn(name + " is sick.");
		}
		break;
	case Health::dead:
		PrintLn(name + " is not breathing.");
		break;
	}
}

void PetInterface::UpdateStats() {
	_petDataPtr->ChangeFood(-1);
	if (_petDataPtr->GetBowels() == PetData::_MAX_STAT) {
		_petDataPtr->ChangePoops(1);
		_petDataPtr->ChangeBowels(-PetData::_MAX_STAT);
	}
	if (_petDataPtr->GetPoops() > 0) {
		_petDataPtr->ChangeHP(-_petDataPtr->GetPoops());
	}
	_petDataPtr->ChangeHappiness(-1);
}