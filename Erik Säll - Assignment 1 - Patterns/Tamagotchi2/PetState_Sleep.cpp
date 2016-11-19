#include "PetState_Sleep.h"



PetState_Sleep::PetState_Sleep()
{
}


PetState_Sleep::~PetState_Sleep()
{
}

bool PetState_Sleep::Update()
{
	std::string name = _petInterfacePtr->GetName();
	switch (_petInterfacePtr->GetHealth()) {
	case Health::healthy:
		switch (_petInterfacePtr->GetMood()) {
		case Mood::happy:
			PrintLn(name + " is snoozing peacefully.");
			break;
		case Mood::uncertain:
			PrintLn(name + " is sleeping...");
			break;
		case Mood::hate:
			PrintLn(name + " won't sleep.");
			break;
		}
		break;
	case Health::sick:
		PrintLn(name + " seems to be having a nightmare.");
		break;
	case Health::dead:
		PrintLn(name + "'s cold body appears to be staring at you...");
		break;
	}
	
	return true;
}
