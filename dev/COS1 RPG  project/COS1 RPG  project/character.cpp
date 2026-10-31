#include "character.h"
#include<iostream>

void character::assignedClassType()
{
	switch(type)
	{
	case CharacterType::Warrior:
		Basestats = {100.0f,10.0f,8.0f,20.0f,10.0f,15.0f};
		growthlevel = {12.0f,1.2f,1.0f,3.0f,1.0f,1.5f};
		break;

	case CharacterType::Tank:
		Basestats = {150.0f,16.0f,5.0f,10.0f,5.0f,5.0f};
		growthlevel = {20.0f,2.0f,0.4f,1.0f,0.5f,1.8f};
		break;
		
	case CharacterType::Mage:
		Basestats = {85.0f,8.0f,14.0f,45.0f,11.0f,5.0f};
		growthlevel = {9.0f,0.5f,2.2f,6.0f,1.0f,0.6f};
		break;

	case CharacterType::Rouge:
		Basestats = {80.0f,7.0f,8.0f,25.0f,16.0f,25.0f};
		growthlevel = {8.0f,0.7f,0.6f,2.0f,2.2f,1.8f};
		break;

	}
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

Stats character::GetcurrentStats() const
{
	Stats current = Basestats;
	current.HP += growthlevel.HP * (level - 1);
	current.DF += growthlevel.DF * (level - 1);
	current.Magic += growthlevel.Magic * (level - 1);
	current.Speed += growthlevel.Speed * (level - 1);
	current.AP += growthlevel.AP * (level - 1);

	if(EquippedWeapon)
	{
		current.AP += EquippedWeapon->Attackboost;
		current.Magic += EquippedWeapon->magicboost;
	}
	if(EquippedArmor)
	{
		current.DF += EquippedArmor->Defenseboost;
		current.Speed += EquippedArmor->Speedboost;
	}
	return current;
}

void character::DisplayCharacterSheet() const
{
	Stats current = GetcurrentStats();
	std::cout << "\n--- " << name << "(Lvl " << level << " ) ---\n";
	std::cout << "HealthPoints: " << current.HP << "|\n MagicPoint: " << current.MP << " |\n AttackPower: " << current.AP << " |\n Defense: " << current.DF << "|\n MagicPower: "
		<< current.Magic << "|\n Speed: " << current.Speed << "|\n";
}

void character::Attack(const character& attacker, character& receiver)
{
	Stats attack = attacker.GetcurrentStats();
	Stats defense = receiver.GetcurrentStats();
	float damage = attack.AP - (defense.DF * 0.2f);

	if (damage < 1.0f)damage = 1.0f;

	std::cout << attacker.name << " Attacked " << receiver.name << " for " << damage<<"\n";
}
