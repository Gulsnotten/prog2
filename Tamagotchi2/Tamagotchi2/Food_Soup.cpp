#include "Food_Soup.h"



Food_Soup::Food_Soup()
{
}

Food_Soup::Food_Soup(int fill, std::string name) : AbstractProduct(fill, name)
{

}

Food_Soup::~Food_Soup()
{
}

std::string Food_Soup::GetDescription()
{
	return "warms the belly on cold nights.";
}

void Food_Soup::Consume(std::unique_ptr<PetData> &petDataPtr)
{
	// nada
}
