#pragma once
#include "AbstractProduct.h"
class Food_Soup : public AbstractProduct
{
public:
	Food_Soup();
	Food_Soup(int fill, std::string name);
	~Food_Soup();

	std::string GetDescription();
	void Consume(PetData* petDataPtr);
};

