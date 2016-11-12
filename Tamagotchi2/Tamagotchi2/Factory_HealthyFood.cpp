#include "Factory_HealthyFood.h"



Factory_HealthyFood::Factory_HealthyFood()
{
}


Factory_HealthyFood::~Factory_HealthyFood()
{
}

Food_Pizza * Factory_HealthyFood::CreateMeal()
{
	return new Food_Pizza(2, "Pizza");
}

Food_Jalapeno * Factory_HealthyFood::CreateTreat()
{
	return new Food_Jalapeno(3, "Jalapeno");
}
