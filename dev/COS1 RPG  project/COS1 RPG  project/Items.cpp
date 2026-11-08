#include "Items.h"

Items::Items(std::string _name, int _quantity, int _power,ItemType _type)
	:name(_name),qauntity(_quantity),power(_power),type(_type)
{
}

Items::~Items() = default;

std::string Items::Getname() const
{
	return name;
}

int Items::GetQuantity() const
{
	return qauntity;
}

int Items::GetPower() const
{
	return power;
}

ItemType Items::Type() const
{
	return type;
}

