#pragma once
#include<memory>
#include"CharacterType.h"
#include<vector>

#include"Weapon.h"
#include"Armor.h"
#include"Items.h"

class enemy;
class Party;
class character
{
private:
	std::string name;
	CharacterType type;
	int level;

	float currentHP;
	float currentMP;

	bool isready;

	int sheildturns = 0;
	int sheildbonus = 0;
	

	
	std::vector<int>Basestats;
	std::vector<int>growthlevel;

	std::vector<Items>items;
	

	std::shared_ptr<Weapon> EquippedWeapon;
	std::shared_ptr<Armor> EquippedArmor;

	void assignedClassType();

public:
	float ATBguage;
	character(const std::string& _name, CharacterType _type);
	bool isAlive()const;

	void LevelUp();
	std::string getName();

	void takedamage(int _damage);
	void Heal(int _heal);
	void fire(character& attacker, enemy& reciever);

	void ice(character& attacker, enemy& reciever);
	
	void lightning(character&, enemy&  reviever);

	void Attack(const character& attacker, enemy& receiver);

	void Cure(character& receiver);


	bool potion(Items&potion);
	void useShield(Items& item);
	void updateShield();
	void useElixir(Items& item);
	

	

	bool WeaponEquip(const std::shared_ptr<Weapon>& _weapon);
	bool ArmorEquip(const std::shared_ptr<Armor>& _armor);

	void DisplayMaxStats()const;
	int getMaxHp()const;
	int getHP() const;
	int GetMaxMP()const;
	int getMP() const;
	int getMPower()const;
	int GetDefense()const;
	float GetAtb()const;
	int Getspeed()const;

	void DisplayCurrentStats() const;
	void Displayitems()const;

	
	


};

