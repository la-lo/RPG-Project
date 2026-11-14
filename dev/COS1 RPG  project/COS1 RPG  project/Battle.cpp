#include"character.h"
#include"enemy.h"
#include<iostream>
#include"Menu.h"
#include<random>
#include "Battle.h"




 void InBAttle(character& player,enemy& _cpu)
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

 void InPBAttle(Party _party, enemy& _cpu)
 {

	 std::vector<std::string> Battleop =
	 { "Attack",
	"spells",
	"items",
	"defend" };

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
	 while (battle)


	 {
		 if (_party.party[0].getHP()<=0&&_party.party[1].getHP()<=0&&_party.party[2].getHP()<=0&&_party.party[3].getHP()<=0)
		 {

			 system("CLS");
			 DisplayHPMP(_party, _cpu);
			 std::cout << _cpu.getName() << " WINS!!!";
			 battle = false;
			 break;
		 }
		 else if (_cpu.gethealth() <= 0)
		 {
			 system("CLS");
			 DisplayHPMP(_party, _cpu);
			 std::cout << "Party WINS!!!";
			 battle = false;
			 break;
		 }



		 DisplayHPMP(_party, _cpu);


		 Battlemenu battlechoice = runBMenuLoop<Battlemenu>("\tBattle", Battleop, static_cast<int>(Battlemenu::count), _party, _cpu);


		 switch (battlechoice)
		 {

		 case Battlemenu::Attack:
			 _party.party[0].Attack(_party.party[0], _cpu);
			 break;
		 case Battlemenu::spells:
		 {
			 if (battlechoice == Battlemenu::spells)
			 {
				 Spells spellchoice = runBMenuLoop<Spells>("\tSpells", spell, static_cast<int>(Spells::count),_party, _cpu);
				 switch (spellchoice)
				 {
				 case Spells::Cure:
					 _party.party[0].Cure(_party.party[0]);
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
		 _party.party[0].Displayitems();
			 break;
		 case Battlemenu::defend:
			 if (dist(gen) == 0)
			 {

				 break;
			 }
			 else
			 {
				 _cpu.attack(_cpu,_party.party[0]);
				 break;
			 }

		 }

		 std::cout << std::endl;
	 }

 }

 void DisplayHPMP(Party _party, enemy _cpu)
 {
	 std::cout << "\n=======================\n";
	 std::cout << _cpu.getName() << ":HP: " << _cpu.gethealth() << "/" << _cpu.maxhealth() << "||\n";
	 std::cout << "=======================\n\tV.S\n";


	 std::cout << "=======================\n";
	 std::cout << _party.party[0].getName() << ": HP: " << _party.party[0].getHP() << '/' << _party.party[0].getMaxHp()
		 << "   ||\n\tMP: " << _party.party[0].getMP() << '/' << _party.party[0].GetMaxMP()<<"    ||\n";
	 std::cout << "=======================\n";
	 std::cout << _party.party[1].getName() << ": HP: " << _party.party[1].getHP() << '/' << _party.party[1].getMaxHp()
		 << "  ||\n\tMP: " << _party.party[1].getMP() << '/' << _party.party[1].GetMaxMP() << "    ||\n";
	 std::cout << "=======================\n";
	 std::cout << _party.party[2].getName() << ": HP: " << _party.party[2].getHP() << '/' << _party.party[2].getMaxHp()
		 << "    ||\n\tMP: " << _party.party[2].getMP() << '/' << _party.party[2].GetMaxMP() << "    ||\n";
	 std::cout << "=======================\n";
	 std::cout << _party.party[3].getName() << ": HP: " << _party.party[3].getHP() << '/' << _party.party[3].getMaxHp()
		 << "      ||\n\tMP: " << _party.party[3].getMP() << '/' << _party.party[3].GetMaxMP() << "    ||\n";
	 std::cout << "=======================\n";
 }
