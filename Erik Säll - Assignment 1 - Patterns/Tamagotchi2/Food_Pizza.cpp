#include "Food_Pizza.h"


Food_Pizza::Food_Pizza()
{
}

Food_Pizza::Food_Pizza(int fill, std::string name) : AbstractProduct(fill, name)
{
}


Food_Pizza::~Food_Pizza()
{
}

std::string Food_Pizza::GetDescription()
{
	return "not very healthy, but very tasty.";
}

void Food_Pizza::Consume(std::unique_ptr<PetData> &petDataPtr)
{
	//nada
}
