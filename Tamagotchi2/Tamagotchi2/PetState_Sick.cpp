#include "PetState_Sick.h"



PetState_Sick::PetState_Sick()
{
}


PetState_Sick::~PetState_Sick()
{
}


void PetState_Sick::Feed() {
	std::cout << _petDataPtr->GetName() << " won't eat...\n";
}
void PetState_Sick::Wash() {
	PetState_Default::Wash();
	std::cout << _petDataPtr->GetName() << " looks relieved.\n";
}
void PetState_Sick::Play() {
	std::cout << _petDataPtr->GetName() << " can barely move.\n";
}

bool PetState_Sick::Update() {
	_petDataPtr->UpdateStats();

	Interact();

	_petDataPtr->PrintStatus();

	if (_petDataPtr->GetHealth() != Health::sick) {
		return false;
	}

	return true;
}

SwitchType PetState_Sick::GetSwitchType() const {
	return SwitchType::pop;
}