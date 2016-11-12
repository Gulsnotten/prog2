#include "AbstractProduct.h"



AbstractProduct::AbstractProduct()
{
}
AbstractProduct::AbstractProduct(int fill, std::string name) : _fill(fill), _name(name)
{
}

AbstractProduct::~AbstractProduct()
{
}

std::string AbstractProduct::GetName()
{
	return _name;
}

int AbstractProduct::GetFill()
{
	return _fill;
}

std::string AbstractProduct::GetDescription()
{
	return std::string();
}

void AbstractProduct::Consume(std::unique_ptr<PetData> &petDataPtr)
{
}
