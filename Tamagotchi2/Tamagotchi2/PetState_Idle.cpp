#include "PetState_Idle.h"


PetState_Idle::PetState_Idle()
{
}


PetState_Idle::~PetState_Idle()
{
}

bool PetState_Idle::Update() {
	if (_petInterfacePtr->GetHealth() != Health::healthy) {
		return false;
	}
	
	_petInterfacePtr->UpdateStats();

	Interact();

	_petInterfacePtr->PrintStatus();

	return true;
}

void PetState_Idle::Feed() {
	_petInterfacePtr->Feed(std::unique_ptr<AbstractProduct>(_foodFactory.CreateMeal()));
}

void PetState_Idle::Wash() {
	PetState_Default::Wash();
}

void PetState_Idle::Play() {
	_petInterfacePtr->Play();
}

PetState* PetState_Idle::NextState() const{
	if (_petInterfacePtr->GetHealth() == Health::sick) {
		return new PetState_Sick();
	}
	else{
		return new PetState_Dead();
	}
}

SwitchType PetState_Idle::GetSwitchType() const {
	return SwitchType::push;
}