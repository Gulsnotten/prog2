#include "Printable.h"



Printable::Printable()
{
}


Printable::~Printable()
{
}

void Printable::Print(std::string out) const
{
	std::cout << out;
}

void Printable::PrintLn(std::string out) const
{
	std::cout << out << "\n";
}
