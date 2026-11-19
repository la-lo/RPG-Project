#include<vector>
#include"Items.h"
#include"Weapon.h"
#include"Armor.h"
class Inventory 
{
private:
	std::vector<Items> items;
	std::vector<Armor> armor;
	std::vector<Weapon> weapon;
	
};