#include "PetState_Default.h"



PetState_Default::PetState_Default(AbstractFactory* factoryPtr) : _foodFactoryPtr(factoryPtr)
{
}


PetState_Default::~PetState_Default()
{
}

const std::vector<std::string> PetState_Default::CHOICES = { "Play", "Give Meal", "Give treat", "Wash" };

void PetState_Default::Interact() {
	switch (GetChoice(CHOICES)) {
	case play:
		Play();
		break;
	case meal:
		Feed(Action::meal);
		break;
	case treat:
		Feed(Action::treat);
		break;
	case wash:
		Wash();
		break;
	default:
		break;
	}
}

void PetState_Default::PrintWashMsg()
{
	std::string name = _petInterfacePtr->GetName();
	switch (_petInterfacePtr->GetMood()) {
	case Mood::happy:
		PrintLn(name + " splashed around happily.");
		break;
	case Mood::uncertain:
		PrintLn(name + " was washed.");
		break;
	case Mood::hate:
		PrintLn(name + " wriggled around violently. You didn't seem to clean it very well...");
		break;
	}
}

void PetState_Default::DoFeed(Action action)
{
	AbstractProduct* food;

	if (action == Action::meal) {
		food = _foodFactoryPtr->CreateMeal();
	}
	else {
		food = _foodFactoryPtr->CreateTreat();
	}

	_petInterfacePtr->Feed(std::unique_ptr<AbstractProduct>(food));
}

void PetState_Default::Wash() {
	_petInterfacePtr->Wash();

	PrintWashMsg();
}