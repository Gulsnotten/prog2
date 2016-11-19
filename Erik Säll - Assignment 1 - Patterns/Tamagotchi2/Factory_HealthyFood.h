#pragma once
#include "AbstractFactory.h"
#include "Food_Jalapeno.h"
#include "Food_Pizza.h"
class Factory_HealthyFood : public AbstractFactory
{
public:
	Factory_HealthyFood();
	~Factory_HealthyFood();

	Food_Pizza* CreateMeal();
	Food_Jalapeno* CreateTreat();
};

