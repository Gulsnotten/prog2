#pragma once
#include "AbstractProduct.h"
class Food_Jalapeno : public AbstractProduct
{
public:
	Food_Jalapeno();
	Food_Jalapeno(int fill, std::string name);
	~Food_Jalapeno();

	std::string GetDescription();
	void Consume(std::unique_ptr<PetData> &petDataPtr);
};

