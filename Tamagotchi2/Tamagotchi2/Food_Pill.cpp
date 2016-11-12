#include "Food_Pill.h"



Food_Pill::Food_Pill()
{
}

Food_Pill::Food_Pill(int fill, std::string name) : AbstractProduct(fill, name)
{
}


Food_Pill::~Food_Pill()
{
}

std::string Food_Pill::GetDescription()
{
	return "\"Might help when sick.\"";
}

void Food_Pill::Consume(PetData * petDataPtr)
{
	AbstractProduct::Consume(petDataPtr);
	petDataPtr->ChangeStat(petDataPtr->_health, 1);
}
