#include<string>
class Enemy
{
public:
	Enemy(std::string name, int maxhp, int attack);
	
	std::string getName();
	int gethealth();
	int maxhealth();
	int getattack();

	void takeDamage(int damage );


private:
	std::string name;
	int Health;
	int Maxhealth;
	int Attackpower;


};





