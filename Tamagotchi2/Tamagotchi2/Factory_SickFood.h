#pragma once
#include "AbstractFactory.h"
#include "Food_Soup.h"
#include "Food_Pill.h"
class Factory_SickFood : public AbstractFactory
{
public:
	Factory_SickFood();
	~Factory_SickFood();

	Food_Soup* CreateMeal();
	Food_Pill* CreateTreat();
};

