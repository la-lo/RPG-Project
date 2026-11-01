#pragma once
#include<memory>
#include"CharacterType.h"
#include"stats.h"
#include"Weapon.h"
#include"Armor.h"
class character:public Stats
{
private:
	std::string name;
	CharacterType type;
	int level;
	Stats Basestats;
	Stats growthlevel;
	
	float currentHP;
	float currentMP;

	std::shared_ptr<Weapon> EquippedWeapon;
	std::shared_ptr<Armor> EquippedArmor;

	void assignedClassType();

public:

	character(const std::string& _name, CharacterType _type);

	void LevelUp();
	std::string getName();

	void takedamage(float _damage);

	

	bool WeaponEquip(const std::shared_ptr<Weapon>& _weapon);
	bool ArmorEquip(const std::shared_ptr<Armor>& _armor);

	void DisplayMaxStats()const;
	Stats GetcurrentStats() const;

	void DisplayCurrentStats() const;

	void Attack(const character& attacker, character& receiver);
};

