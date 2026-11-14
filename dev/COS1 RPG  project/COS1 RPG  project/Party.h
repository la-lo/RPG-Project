#pragma once
#include  "character.h"


class  Party
{
public:
	std::vector<character> party;

	Party(character p0, character p1, character p2, character p3)
	{
		party.push_back(p0);
		party.push_back(p1);
		party.push_back(p2);
		party.push_back(p3);
	}
};
