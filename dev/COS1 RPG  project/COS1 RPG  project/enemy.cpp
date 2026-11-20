
#include"character.h"
#include "enemy.h"
#include<iostream>

enemy::enemy(std::string _name, int maxhp, int attack,int df)
    :name(_name), Maxhealth(maxhp), Health(maxhp), Attackpower(attack),Defense(df),ATBGuage(0),speed(9)
{
}


std::string enemy::getName()
{
    return name;
}

int enemy::gethealth() const
{
    return Health;
}

int enemy::maxhealth() const
{
    return Maxhealth;
}


int enemy::getattack() const
{
    return Attackpower;
}

int enemy::getDefense() const
{
    return Defense;
}

int enemy::getspeed() const
{
    return speed;
}

void enemy::AttackAll(enemy& attacker, Party& reciever)
{
    int damage = attacker.Attackpower * .1;
    for(int i = 0;i<reciever.party.size();i++)
    {
        reciever.party[i].takedamage(damage);
    }
}

void enemy::takeDamage(float damage)
{
    Health -= damage;
    if (Health < 0)Health = 0;

}

bool enemy::isAlive() const
{
    return Health > 0;
}

void enemy::attack(enemy& attacker, character& reciever)
{
    
    float damage = attacker.Attackpower * 3;

    reciever.takedamage(damage / reciever.GetDefense() * .4);
    std::cout << attacker.getName() << " Attacked " << reciever.getName()<<'\n';
    
}



