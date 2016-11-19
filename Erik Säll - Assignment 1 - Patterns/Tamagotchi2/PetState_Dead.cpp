#include "PetState_Dead.h"



PetState_Dead::PetState_Dead() : revive(false)
{
}


PetState_Dead::~PetState_Dead()
{
}

static const std::vector<std::string> CHOICES = { "...Poke it", "Buy new pet" };
enum Action { poke, new_pet };

bool PetState_Dead::Update() {
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

	_petInterfacePtr->PrintStatus();

	return true;
}

bool PetState_Dead::Poke() { // returns true if Pet is revived!
	revive = std::rand() % 100 == 0;
	if (revive) {
		_petInterfacePtr->Revive();
		PrintReviveMsg();
	}
	else {
		PrintFutilePokeMsg();
	}
	return revive;
}

void PetState_Dead::PrintReviveMsg()
{
	PrintLn("A divine light surrounds " + _petInterfacePtr->GetName() + ". Something is happening..!");
}

void PetState_Dead::PrintFutilePokeMsg()
{
	PrintLn(_petInterfacePtr->GetName() + " will probably never move again.");
}

SwitchType PetState_Dead::GetSwitchType() const {
	if (revive) {
		return SwitchType::pop;
	}
	else {
		return SwitchType::kill;
	}
}