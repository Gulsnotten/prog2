#include "PetState_Sick.h"



PetState_Sick::PetState_Sick()
{
}


PetState_Sick::~PetState_Sick()
{
}


void PetState_Sick::Feed() {
	if (std::rand() % 2 == 0) {
		std::cout << _petInterfacePtr->GetName() << " won't eat...\n";
	}
	else {
		_petInterfacePtr->Feed(std::unique_ptr<AbstractProduct>(_foodFactory.CreateMeal()));
	}
}
void PetState_Sick::Wash() {
	PetState_Default::Wash();
	std::cout << _petInterfacePtr->GetName() << " looks relieved.\n";
}
void PetState_Sick::Play() {
	std::cout << _petInterfacePtr->GetName() << " can barely move.\n";
}

bool PetState_Sick::Update() {
	_petInterfacePtr->UpdateStats();

	Interact();

	_petInterfacePtr->PrintStatus();

	if (_petInterfacePtr->GetHealth() != Health::sick) {
		return false;
	}

	return true;
}

SwitchType PetState_Sick::GetSwitchType() const {
	return SwitchType::pop;
}