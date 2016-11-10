#include "PetState_Idle.h"



PetState_Idle::PetState_Idle()
{
}


PetState_Idle::~PetState_Idle()
{
}

static const std::vector<std::string> CHOICES = { "Play", "Feed", "Wash" };
static const enum Action {play, feed, wash};

bool PetState_Idle::Update() {
	switch (GetChoice(CHOICES)) {
	case play:
		Play();
		return true;
	case feed:
		Feed();
		break;
	case wash:
		Wash();
		break;
	default:
		break;
	}

	return true;
}

void PetState_Idle::Feed() {
	_petDataPtr->ChangeStat(_petDataPtr->_food, 1);
	_petDataPtr->ChangeStat(_petDataPtr->_bowels, 1);
}

void PetState_Idle::Wash() {

}

void PetState_Idle::Play() {

}