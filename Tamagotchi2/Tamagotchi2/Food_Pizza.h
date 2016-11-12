#pragma once
#include "AbstractProduct.h"
class Food_Pizza : public AbstractProduct
{
public:
	Food_Pizza();
	Food_Pizza(int fill, std::string name);
	~Food_Pizza();

	std::string GetDescription();
	void Consume(std::unique_ptr<PetData> &petDataPtr);
};

