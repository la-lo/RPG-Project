#include "enemy.h"

Enemy::Enemy(std::string _name, int maxhp, int attack)
    :name(_name), Maxhealth(maxhp), Health(maxhp), Attackpower(attack)
{
}

std::string Enemy::getName()
{
    return name;
}

int Enemy::gethealth()
{
    return Health;
}

int Enemy::maxhealth()
{
    return Maxhealth;
}

int Enemy::getattack()
{
    return Attackpower;
}

void Enemy::takeDamage(int damage)
{
    Health -= damage;
    if (Health < 0)Health = 0;

}
