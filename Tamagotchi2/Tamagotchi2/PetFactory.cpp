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

	std::shared_ptr<PetData> pd = std::make_shared<PetData>(name);

	StateMachine* ret = new StateMachine(pd);

	return ret;
}