#include "PetState_Default.h"



PetState_Default::PetState_Default()
{
}


PetState_Default::~PetState_Default()
{
}

const std::vector<std::string> PetState_Default::CHOICES = { "Play", "Feed", "Wash" };
enum Action { play, feed, wash };

void PetState_Default::Interact() {
	switch (GetChoice(CHOICES)) {
	case play:
		Play();
		break;
	case feed:
		Feed();
		break;
	case wash:
		Wash();
		break;
	default:
		break;
	}
}

void PetState_Default::Wash() {
	_petDataPtr->Wash();

	std::string msg;

	switch (_petDataPtr->GetMood()) {
	case Mood::happy:
		msg = _petDataPtr->GetName() + " splashed around happily.\n";
		break;
	case Mood::uncertain:
		msg = _petDataPtr->GetName() + " was washed.\n";
		break;
	case Mood::hate:
		msg = _petDataPtr->GetName() + " wriggled around violently. You didn't seem to clean it very well...\n";
		break;
	}

	std::cout << msg;
}