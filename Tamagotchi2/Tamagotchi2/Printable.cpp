#include "Printable.h"



Printable::Printable()
{
}


Printable::~Printable()
{
}

void Printable::Print(std::string out)
{
	std::cout << out;
}

void Printable::PrintLn(std::string out)
{
	std::cout << out << "\n";
}
