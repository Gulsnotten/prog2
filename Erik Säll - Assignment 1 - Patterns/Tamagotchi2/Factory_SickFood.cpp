#include "Factory_SickFood.h"



Factory_SickFood::Factory_SickFood()
{
}


Factory_SickFood::~Factory_SickFood()
{
}

Food_Soup * Factory_SickFood::CreateMeal()
{
	return new Food_Soup(3, "Soup");
}

Food_Pill * Factory_SickFood::CreateTreat()
{
	return new Food_Pill(2, "Pill");
}
