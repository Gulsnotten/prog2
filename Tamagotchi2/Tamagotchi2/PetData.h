#pragma once
#include <string>

enum Mood { hate, uncertain, happy };
enum Health { healthy, sick, dead};

class PetData
{
	std::string _name;
	int _food;
	int _hp;
	int _bowels;
	int _poops;
	int _happiness;

	void ChangeStat(int &stat, int change);
public:
	PetData(std::string name);
	~PetData();

	static const int _MAX_STAT;
	
	void ChangeFood(int change);
	void ChangeHP(int change);
	void ChangeBowels(int change);
	void ChangePoops(int change);
	void ChangeHappiness(int change);

	int GetFood();
	int GetHP();
	int GetBowels();
	int GetPoops();
	int GetHappiness();
	
	Health GetHealth();
	bool isHungry();
	Mood GetMood();
	std::string GetName();
};