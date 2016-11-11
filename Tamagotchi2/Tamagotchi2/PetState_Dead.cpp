#include "PetState_Dead.h"



PetState_Dead::PetState_Dead()
{
}


PetState_Dead::~PetState_Dead()
{
}

static const std::vector<std::string> CHOICES = { "...Poke it", "Buy new pet" };
enum Action { poke, new_pet };

bool PetState_Dead::Update() {
	_petDataPtr->PrintStatus();

	switch (GetChoice(CHOICES)) {
	case poke:
		if (Poke()) {
			return false;
		}
		break;
	case new_pet:
		return false;
		break;
	}

	return true;
}

bool revive = false;
bool PetState_Dead::Poke() { // returns true if Pet is revived!
	revive = std::rand() % 100 == 0;
	if (revive) {
		std::cout << "A divine light surrounds " << _petDataPtr->GetName() << ". Something is happening..!\n";
	}
	else {
		std::cout << _petDataPtr->GetName() << " will probably never move again.\n";
	}
	return revive;
}

SwitchType PetState_Dead::GetSwitchType() const {
	if (revive) {
		return SwitchType::pop;
	}
	else {
		return SwitchType::kill;
	}
}