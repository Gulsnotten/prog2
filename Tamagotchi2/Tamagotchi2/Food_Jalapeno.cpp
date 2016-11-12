#include "Food_Jalapeno.h"



Food_Jalapeno::Food_Jalapeno()
{
}

Food_Jalapeno::Food_Jalapeno(int fill, std::string name) : AbstractProduct(fill, name)
{
}


Food_Jalapeno::~Food_Jalapeno()
{
}

std::string Food_Jalapeno::GetDescription()
{
	return "will mess with your bowels.";
}

void Food_Jalapeno::Consume(PetData * petDataPtr)
{
	AbstractProduct::Consume(petDataPtr);
	petDataPtr->ChangeStat(petDataPtr->_bowels, PetData::_MAX_STAT);
}
