#include<string>
#include"character.h"
#include"Party.h"
#pragma once

class enemy
{
public:
	float ATBGuage;
	enemy(std::string name, int maxhp, int attack,int df);
	
	std::string getName();
	int gethealth() const;
	int maxhealth() const;
	int getattack() const;
	int getDefense()const;
	int getspeed()const;
	void AttackAll(enemy& attacker, Party& reciever);
	void takeDamage(float damage);
	bool isAlive()const;

	void attack(enemy& attacker,character& reciever);
	


private:
	std::string name;
	float Health;
	int Maxhealth;
	int Attackpower;
	int Defense;
	int speed;


};





