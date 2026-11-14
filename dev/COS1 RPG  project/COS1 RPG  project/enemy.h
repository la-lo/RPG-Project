#include<string>
#include"character.h"
#include"Party.h"
#pragma once

class enemy
{
public:
	enemy(std::string name, int maxhp, int attack,int df);
	
	std::string getName();
	int gethealth() const;
	int maxhealth() const;
	int getattack() const;
	int getDefense()const;

	void takeDamage(int damage);

	void attack(enemy& attacker,character& reciever);
	


private:
	std::string name;
	int Health;
	int Maxhealth;
	int Attackpower;
	int Defense;


};





