#pragma once
#include<string>
#include"CharacterType.h"

struct Weapon
{
	std::string name;
	float Attackboost;
	float magicboost;
	CharacterType reqclass;
};