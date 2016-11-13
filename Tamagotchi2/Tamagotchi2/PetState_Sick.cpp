#include "PetState_Sick.h"



PetState_Sick::PetState_Sick() : PetState_Default(new Factory_SickFood())
{
}


PetState_Sick::~PetState_Sick()
{
}


void PetState_Sick::PrintWontEatMsg()
{
	PrintLn(_petInterfacePtr->GetName() + " won't eat...");
}

void PetState_Sick::PrintWashMsg()
{
	PrintLn(_petInterfacePtr->GetName() + " looks relieved.");
}

void PetState_Sick::PrintPlayMsg()
{
	PrintLn(_petInterfacePtr->GetName() + " can barely move.");
}

void PetState_Sick::Feed(Action action) {
	if (std::rand() % 2 == 0) {
		PrintWontEatMsg();
	}
	else {
		DoFeed(action);
	}
}
void PetState_Sick::Wash() {
	PetState_Default::Wash();
	PrintWashMsg();
}
void PetState_Sick::Play() {
	PrintPlayMsg();
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