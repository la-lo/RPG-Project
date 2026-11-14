#include"character.h"
#include"enemy.h"
#include<iostream>
#include"Menu.h"
#include<random>
#include "Battle.h"




 void inBAttle(character& player,enemy& _cpu)
{
	 std::vector<std::string> Battleop = 
	 {"Attack",
	"spells",
	"items",
	"defend"};

	 std::vector<std::string> spell =
	 { "Cure",
		 "Fireball",
		"IceAge",
		 "lighting"
	 };
	 std::random_device rd;
	 std::mt19937 gen(rd());
	 std::uniform_int_distribution<int>dist(0, 1);
	
	bool battle = true;
	while(battle)


	{
		if (player.getHP() <= 0) 
		{
			
			system("CLS");
			DisplayHPMP(player,_cpu);
			std::cout << _cpu.getName() << " WINS!!!";
			battle = false;
			break;
		}else if(_cpu.gethealth() <= 0)
		{
			system("CLS");
			DisplayHPMP(player, _cpu);
			std::cout << player.getName() << " WINS!!!";
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
		{
			if (battlechoice == Battlemenu::spells)
			{Spells spellchoice = runBMenuLoop<Spells>("\tSpells", spell, static_cast<int>(Spells::count), player, _cpu);
				switch (spellchoice)
				{
				case Spells::Cure:
					player.Cure(player);
					break;
				case Spells::FireBall:
					break;
				case  Spells::IceAge:
					break;
				case Spells::Lightning:
					break;
				}

				break;
			}
			break;
		}
			
		case Battlemenu::items:
			player.Displayitems();
			break;
		case Battlemenu::defend:
			if(dist(gen)==0)
			{
				
				break;
			}
			else
			{_cpu.attack(_cpu, player);
				break;
			}
		
		}
		
		std::cout << std::endl;
	}

}

 void DisplayHPMP(character player, enemy _cpu)
 {
	 std::cout << "\n" << player.getName() << ":\n HP: " << player.getHP() << '/' << player.getMaxHp()
		 << "\n\tMP: "<<player.getMP()<<'/'<< player.GetMaxMP();

	 std::cout <<"\n\n";


	 std::cout << _cpu.getName() << ":\nHP: " << _cpu.gethealth() << "/" << _cpu.maxhealth()<<'\n';
 }
