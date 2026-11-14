#include "character.h"
#include"enemy.h"
#include<iostream>

void character::assignedClassType()
{
	switch(type)
	{
	case CharacterType::Warrior:

		// 0HP,1D,2MPW,3MP,4SP,5AP
		Basestats = {100,10,8,20,10,15};
		growthlevel = {12,1,1,3,1,2};
		break;

	case CharacterType::Tank:
		Basestats = {150,16,5,10,5,5};
		growthlevel = {20,2,1,1,1,2};
		break;
		
	case CharacterType::Mage:
		Basestats = {85,8,14,45,11,5};
		growthlevel = {9,1,2,6,1,1};
		break;

	case CharacterType::Rouge:
		Basestats = {80,7,8,25,16,25};
		growthlevel = {8,1,1,2,2,2};
		break;

	}

	currentHP = Basestats[0];
	currentMP = Basestats[3];
}

character::character(const std::string& _name, CharacterType _type)
	:name(_name),type(_type),level(1),EquippedWeapon(nullptr),EquippedArmor(nullptr)
{
	
	assignedClassType();
	
}

void character::LevelUp()
{
	level++;
	std::cout << name << " is now level " << level<<"!\n";
	for(int i = 0;i<sizeof(Basestats)+1;i++)
	{
		Basestats[i] += growthlevel[i];
	}
}

std::string character::getName()
{
	return name;
}



bool character::WeaponEquip(const std::shared_ptr<Weapon>& _weapon)
{
	if(_weapon->reqclass!=type)
	{
		std::cout << _weapon->name<< " Can not Equip on " << name;
		return false;
	}
	EquippedWeapon = _weapon;
	
}

bool character::ArmorEquip(const std::shared_ptr<Armor>& _armor)
{
	if(_armor->reqclass!=type)
	{
		std::cout << _armor->name << " Can not Equip on " << name;
		return false;
	}

	EquippedArmor = _armor;
	
}

void character::DisplayMaxStats() const
{
	
	std::cout << "\n--- " << name << "(Lvl " << level << " ) ---\n";
	std::cout << "HealthPoints: " << Basestats[0] 
		<< "|\n MagicPoint: " << Basestats[3]
		<< " |\n AttackPower: " << Basestats[5]
		<< " |\n Defense: " << Basestats[1]
		<< "|\n MagicPower: " << Basestats[2]
		<< "|\n Speed: " << Basestats[4] << "|\n";
}

int character::getMaxHp() const
{
	return Basestats[0];
}



int character::getHP() const
{
	return currentHP;

}

int character::GetMaxMP() const
{
	return Basestats[3];
}



int character::getMP() const
{
	return currentMP;
}

int character::getMPower() const
{
	return Basestats[2];
}

int character::GetDefense() const
{
	return Basestats[1];
}



void character::DisplayCurrentStats() const
{
	
	std::cout << "\n--- " << name << "(Lvl " << level << " ) ---\n";
	std::cout << "HealthPoints: " << currentHP <<"/"<<Basestats[0] 
		<< "|\n MagicPoint: " << currentMP <<"/"<<Basestats[3]
		<< " |\n AttackPower: " << Basestats[5]
		<< " |\n Defense: " << Basestats[1]
		<< "|\n MagicPower: "<< Basestats[2]
		<< "|\n Speed: " << Basestats[4] << "|\n";
}

void character::Displayitems() const
{
	if (items.empty())
	{
		std::cout << "items is empty";
		return;
	}
	std::cout << "\n---- Party's Inventory----\n";

	for (int i=0;sizeof(items)+1;i++ )
	{
		std::cout << items[i].Getname();
		if (items[i].Type() == ItemType::Heal)
		{
			std::cout << "Heals: " << items[i].GetPower() << " HP";
		}std::cout << "\n";
	}
}

void character::takedamage(int _damage)
{
	
	currentHP -= _damage;
	if (currentHP < 0) currentHP = 0;
}

void character::Heal(int _heal)
{
	currentHP += _heal;

	if (currentHP > Basestats[0]) 
	{ 
		currentHP = Basestats[0];
		
	}
	currentMP -= 2;
}

void character::Attack(const character& attacker, enemy& receiver)
{
	
	
	int damage = attacker.Basestats[5] - (receiver.getattack() * 2);

	if (damage < 1)damage = 1;
	
	receiver.takeDamage(damage);
	

	
	
	
	
}



void character::Cure( character& receiver)
{
	int  heal = receiver.Basestats[2] * 2;

	receiver.Heal(heal);
}


