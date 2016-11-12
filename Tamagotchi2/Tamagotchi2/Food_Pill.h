#pragma once
#include "AbstractProduct.h"
class Food_Pill : public AbstractProduct
{
public:
	Food_Pill();
	Food_Pill(int fill, std::string name);
	~Food_Pill();

	std::string GetDescription();
	void Consume(PetData* petDataPtr);
};

