#include"character.h"
#include"enemy.h"
#include<iostream>
#include"Menu.h"
#include<random>

#include"Party.h"





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

 void InPBAttle(Party& _party, enemy& _cpu)
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

	 int turn = 1;
	

	 bool battle = true;
	 while (battle)
	 {
		
		 if (_party.party[0].getHP()<=0&&_party.party[1].getHP()<=0&&_party.party[2].getHP()<=0&&_party.party[3].getHP()<=0)
		 {

			 system("CLS");
			
			 DisplayHPMP(_party, _cpu);
			 std::cout << _cpu.getName() << " WINS!!!"<<"\n Turns taken: "<<turn;
			 battle = false;
			 break;
		 }
		 else if (_cpu.gethealth() <= 0)
		 {
			 system("CLS");
			 DisplayHPMP(_party, _cpu);
			 std::cout << "Party WINS!!!" << "\nTurns taken: " << turn;;
			 battle = false;
			 break;
		 }
		 std::cout << "TURN " << turn << std::endl;
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
					 if(_party.party[0].getMP()<2)
					 {
						 break;
					 }else
					 {
						 _party.party[0].Cure(_party.party[0]);
						 break;

					 }
					 
					 
				 case Spells::FireBall:
					 if (_party.party[0].getMP() < 4)
					 {
						 break;
					 }
					 else
					 {
						 _party.party[0].fire(_party.party[0], _cpu);
						 break;

					 }
					 
					 break;
				 case  Spells::IceAge:
					 
					 if (_party.party[0].getMP() < 2)
					 {
						 break;
					 }
					 else
					 {
						 _party.party[0].ice(_party.party[0], _cpu);
						 break;
					 }
				 case Spells::Lightning:
					 if (_party.party[0].getMP() < 3)
					 {
						 break;
					 }
					 else
					 {
						_party.party[0].lightning(_party.party[0], _cpu);
						 break;
					 }
					 
					
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
		 if(_cpu.gethealth()<100)
		 {
			 _cpu.AttackAll(_cpu, _party);

		 }
		 
		 turn++;
	 }
	
 }

 void DisplayHPMP(Party _party, enemy _cpu)
 {
	 std::cout << "\n=======================\n";
	 std::cout << _cpu.getName() << ":HP: " << _cpu.gethealth() << "/" << _cpu.maxhealth() << "||\n";
	 std::cout << "=======================\n\tV.S\n";

	 for(int i = 0;i<4;i++)
	 { 
		 std::cout << "=======================\n";
	 std::cout << _party.party[i].getName() << ": HP: " << _party.party[i].getHP() << '/' << _party.party[i].getMaxHp()
		 << "   ||\n\tMP: " << _party.party[i].getMP() << '/' << _party.party[i].GetMaxMP()<<"    ||\n"<<"ATB: " <<_party.party[i].ATBguage<<"\n";
	 

	 }
	
	 
 }


 void InATBBAttle(Party& player, enemy& _cpu, int count)
 {


	 std::vector<std::string> Battleop = { "Attack", "spells", "items", "defend" };
	 std::vector<std::string> spell = { "Cure", "Fireball", "IceAge", "lighting" };
	 std::vector<std::string> _items = { "Potion", "Shield","Elixir"};
	 Items Potion = Items("Potion", 5, 20, ItemType::Heal);
	 Items Shield = Items("Shield", 7, 10, ItemType::Defense);
	 Items Revive = Items("Rise", 4, 100, ItemType::Revive);
	 Items Elixir = Items("Elixir", 5, 25, ItemType::Heal);
	
	 
	 std::random_device rd;
	 std::mt19937 gen(rd());

	 int turn = 1;
	 const float ATBMax = 100.0f;

	 while (player.isPartyAlive(player, count) && _cpu.isAlive())
	 {
		 for (int i = 0; i < count; i++)
		 {
			 character& _player = player.party[i];
			 if (!_player.isAlive()) 
			 {
				
				 continue;
			 }

			 _player.ATBguage += _player.Getspeed();

			 if (_player.ATBguage >= ATBMax)
			 {
				 _player.updateShield();
				 bool actionTaken = false;
				 while (!actionTaken)
				 {
					 Battlemenu battlechoice = runATBMenuLoop<Battlemenu>(
						 "\tBattle", Battleop, static_cast<int>(Battlemenu::count), player, _cpu, i);

					 switch (battlechoice)
					 {
					 case Battlemenu::Attack:
						 _player.Attack(_player, _cpu);
						 system("pause");
						 actionTaken = true;
						 break;

					 case Battlemenu::spells:
					 {
						 Spells spellchoice = runATBMenuLoop<Spells>(
							 "\tSpells", spell, static_cast<int>(Spells::count), player, _cpu, i);

						 switch (spellchoice)
						 {
						 case Spells::Cure:
							 if (_player.getMP() >= 2) {
								 _player.Cure(_player);
								 system("pause");
								 actionTaken = true;
							 }
							 break;
						 case Spells::FireBall:
							 if (_player.getMP() >= 4) {
								 _player.fire(_player, _cpu);
								 system("pause");
								 actionTaken = true;
							 }
							 break;
						 case Spells::IceAge:
							 if (_player.getMP() >= 2) {
								 _player.ice(_player, _cpu);
								 system("pause");
								 actionTaken = true;
							 }
							 break;
						 case Spells::Lightning:
							 if (_player.getMP() >= 3) {
								 _player.lightning(_player, _cpu);
								 system("pause");
								 actionTaken = true;
							 }
							 break;
						 }
						 break;
					 }

					 case Battlemenu::items:
					 {
						 items itemchoice = runATBMenuLoop<items>("\tItems", _items, static_cast<int>(items::count), player, _cpu, i);
						 switch (itemchoice)
						 {
						 case items::potion:
							 _player.potion(Potion);
							 system("pause");
							 actionTaken = true;
							 break;
						 case items::sheild:
							 _player.useShield(Shield);
							 system("pause");
							 actionTaken = true;
							 break;
						 case items::Elixir:
							 _player.useElixir(Elixir);
							 system("pause");
							 actionTaken = true;
							 break;
						 }
						 break;
					 }
						 
						 actionTaken = true;
						 break;

					 case Battlemenu::defend:
						 actionTaken = true;
						 break;
					 }
				 }
				 _player.ATBguage = 0;
			 }

			 if (!_cpu.isAlive()) 
			 {
				 std::cout << "I Will Never Be just A Memory";
				 system("pause");
				 break;
			 }
		 }

		 if (_cpu.isAlive() && player.isPartyAlive(player, count))
		 {
			 _cpu.ATBGuage += _cpu.getspeed();
			 if (_cpu.ATBGuage >= ATBMax)
			 {
				 int aliveTargets[10]{};
				 int aliveCount = 0;
				 for (int j = 0; j < count; j++)
				 {
					 if (player.party[j].isAlive())
					 {
						 aliveTargets[aliveCount++] = j;
					 }
				 }

				 if (aliveCount > 0)
				 {
					 std::uniform_int_distribution<int> targetDist(0, aliveCount - 1);
					 int targetIndex = aliveTargets[targetDist(gen)];
					 _cpu.attack(_cpu, player.party[targetIndex]);
					 system("pause");
				 }
				 _cpu.ATBGuage = 0;
			 }
		 }
		 turn++;
	 }
	 if (!player.isPartyAlive(player, count))
	 {
		 std::cout << _cpu.getName() << ": Your Nightmare Will Never ENDD!!!";
		 system("pause");
		 
	 }
 }


 /* if (_party.party[0].getHP() <= 0 && _party.party[1].getHP() <= 0 && _party.party[2].getHP() <= 0 && _party.party[3].getHP() <= 0)
		 {

			 system("CLS");

			 DisplayHPMP(_party, _cpu);
			 std::cout << _cpu.getName() << " WINS!!!" << "\n Turns taken: " << turn;
			 battle = false;
			 break;
		 }
		 else if (_cpu.gethealth() <= 0)
		 {
			 system("CLS");
			 DisplayHPMP(_party, _cpu);
			 std::cout << "Party WINS!!!" << "\nTurns taken: " << turn;;
			 battle = false;
			 break;
		 }
		 std::cout << "TURN " << turn << std::endl;
		 DisplayHPMP(_party, _cpu);

		

		 std::cout << std::endl;
		 if (_cpu.gethealth() < 100)
		 {
			 _cpu.AttackAll(_cpu, _party);

		 }*/
 
