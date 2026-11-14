#pragma once
#include<memory>
#include"CharacterType.h"
#include<vector>

#include"Weapon.h"
#include"Armor.h"
#include"Items.h"
class enemy;
class character
{
private:
	std::string name;
	CharacterType type;
	int level;

	float currentHP;
	float currentMP;


	
	std::vector<int>Basestats;
	std::vector<int>growthlevel;

	std::vector<Items>items;
	

	std::shared_ptr<Weapon> EquippedWeapon;
	std::shared_ptr<Armor> EquippedArmor;

	void assignedClassType();

public:

	character(const std::string& _name, CharacterType _type);

	void LevelUp();
	std::string getName();

	void takedamage(int _damage);
	void Heal(int _heal);

	void Attack(const character& attacker, enemy& receiver);

	void Cure( character& receiver);

	

	bool WeaponEquip(const std::shared_ptr<Weapon>& _weapon);
	bool ArmorEquip(const std::shared_ptr<Armor>& _armor);

	void DisplayMaxStats()const;
	int getMaxHp()const;
	int getHP() const;
	int GetMaxMP()const;
	int getMP() const;
	int getMPower()const;
	int GetDefense()const;

	void DisplayCurrentStats() const;
	void Displayitems()const;

	
	


};

