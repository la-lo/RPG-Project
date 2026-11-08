#pragma once
#include<string>

enum class ItemType
{
	Heal,
	Defense,
	Revive,

};
class Items
{
private:
	int qauntity;
	int power;
	std::string name;
	ItemType type;

public:
	
		Items(std::string _name, int _quantity, int _power, ItemType _type);
		virtual ~Items();
		std::string Getname() const;
		int GetQuantity() const;
		int GetPower() const;

		ItemType Type() const;


};

