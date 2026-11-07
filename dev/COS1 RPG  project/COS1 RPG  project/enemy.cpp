#include "enemy.h"

enemy::enemy(std::string _name, int maxhp, int attack,int df)
    :name(_name), Maxhealth(maxhp), Health(maxhp), Attackpower(attack),Defense(df)
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

void enemy::takeDamage(int damage)
{
    Health -= damage;
    if (Health < 0)Health = 0;

}
