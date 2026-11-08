#include"character.h"
#include"enemy.h"
#include<iostream>
#include"Menu.h"
#include<random>
#include "Battle.h"




 void inBAttle(character& player,enemy& _cpu)
{
	 std::vector<std::string> Battleop = {"Attack",
	"spells",
	"items",
	"defend"};
	 std::random_device rd;
	 std::mt19937 gen(rd());
	 std::uniform_int_distribution<int>dist(0, 1);
	
	bool battle = true;
	while(battle)


	{
		if (player.getHP() <= 0 || _cpu.gethealth() <= 0) 
		{
			battle = false;
			break;
		}
		


		DisplayHPMP(player, _cpu);
		

		Battlemenu battlechoice = runBMenuLoop<Battlemenu>("\tBattle",Battleop,static_cast<int>(Battlemenu::count),player,_cpu);
		switch(battlechoice)
		{
		case Battlemenu::Attack:
			player.Attack(player,_cpu);
			break;
		case Battlemenu::spells:
			break;
		case Battlemenu::items:
			break;
		case Battlemenu::defend:
			
			_cpu.attack(_cpu, player);
				
			
			break;

		}
		
		std::cout << std::endl;
		
		
	}

}

 void DisplayHPMP(character player, enemy _cpu)
 {
	 std::cout << "\n" << player.getName() << ": HP: " << player.getHP() << '/' << player.getMaxHp();

	 std::cout << std::endl;


	 std::cout << _cpu.getName() << ": HP: " << _cpu.gethealth() << "/" << _cpu.maxhealth();
	 std::cout<<'\n';
 }
