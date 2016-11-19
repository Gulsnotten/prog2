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

void Food_Jalapeno::Consume(std::unique_ptr<PetData> &petDataPtr)
{
	petDataPtr->ChangeBowels(PetData::_MAX_STAT);
}
