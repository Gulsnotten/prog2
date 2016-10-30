#pragma once
class Pet
{
	const int _HEALTH = 5;

	int _hunger;
	int _belly;
	int _sickness;
public:
	Pet();
	~Pet();

	void PrintStatus() const;
	void Feed();
};

