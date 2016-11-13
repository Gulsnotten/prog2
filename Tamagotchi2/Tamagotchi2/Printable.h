#pragma once
#include <iostream>
#include <string>
class Printable
{
public:
	Printable();
	~Printable();

	void Print(std::string out) const;
	void PrintLn(std::string out) const;
};

