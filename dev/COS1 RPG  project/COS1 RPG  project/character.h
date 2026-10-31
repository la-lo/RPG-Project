#pragma once
#include<memory>
#include"CharacterType.h"
#include"stats.h"
#include"Weapon.h"
#include"Armor.h"
class character
{
private:
	std::string name;
	CharacterType type;
	int level;
	Stats Basestats;
	Stats growthlevel;

	std::shared_ptr<Weapon> EquippedWeapon;
	std::shared_ptr<Armor> EquippedArmor;

	void assignedClassType();

public:

	character(const std::string& _name, CharacterType _type);

	void LevelUp();

	bool WeaponEquip(const std::shared_ptr<Weapon>& _weapon);
	bool ArmorEquip(const std::shared_ptr<Armor>& _armor);

	Stats GetcurrentStats() const;

	void DisplayCharacterSheet() const;

	void Attack(const character& attacker, character& receiver);
};

