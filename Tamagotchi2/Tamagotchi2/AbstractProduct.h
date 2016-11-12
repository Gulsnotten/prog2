#pragma once
#include <iostream>
#include <memory>
#include "PetData.h"
#include <string>

class PetData;

class AbstractProduct
{
protected:
	int _fill;
	std::string _name;
public:
	AbstractProduct();
	AbstractProduct(int fill, std::string name);
	~AbstractProduct();

	std::string GetName();
	int GetFill();
	virtual std::string GetDescription() = 0;
	virtual void Consume(std::unique_ptr<PetData> &petDataPtr) = 0;
};

