#include "PetFactory.h"



PetFactory::PetFactory()
{
}


PetFactory::~PetFactory()
{
}

const std::vector<std::string> PetFactory::_NAMES = { "Agumon", "Gabumon", "Biyomon", "Tentomon", "Palmon", "Gomamon", "Patamon", "Gatomon" };

StateMachine* PetFactory::CreatePet() {
	std::string name = _NAMES[std::rand() % _NAMES.size()];

	StateMachine* ret = new StateMachine(new PetInterface(name));

	return ret;
}