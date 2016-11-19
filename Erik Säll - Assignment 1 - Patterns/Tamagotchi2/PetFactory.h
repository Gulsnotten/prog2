#pragma once
#include <vector>
#include <string>
#include "StateMachine.h"
class PetFactory
{
	static const std::vector<std::string> _NAMES;
public:
	PetFactory();
	~PetFactory();

	static StateMachine* CreatePet();
};

