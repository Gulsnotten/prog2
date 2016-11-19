#pragma once
#include "AbstractProduct.h"
class AbstractFactory
{
public:
	AbstractFactory();
	~AbstractFactory();

	virtual AbstractProduct* CreateMeal() = 0;
	virtual AbstractProduct* CreateTreat() = 0;
};