


#include"Menu.h"
#include"CharacterType.h"
#include"character.h"
#include"enemy.h"
#include"Battle.h"
#include"Party.h"






int main()
{

    std::vector<std::string> Gameoptions =
    {
        "Start Game",
        "Quit Game"
    };


 


    int totalGOptions = static_cast<int>(IngameMenu::count);


    bool mainMenu = true;
    int currentselection = 0;
  
    
   
  
    while (mainMenu)
    {
        system("CLS");
        MainMenu mainChoice = runMenuLoop<MainMenu>("\t----Main Menu----\n", Gameoptions, static_cast<int>(MainMenu::Count));
       

       

        switch (mainChoice)
        {
        case MainMenu::StartGame:
        { 
            
           
         
            system("cls");
            std::cout << "\t\tDimension 7\n\t\t-----------\n\tAn Endless Nightmare\n\n\nPress Any Key.";
            std::cout << "\n\n\tKey\n\t---\n-Press ESC for Main Menu" ;
            if (_getch() == KEY_ESC) {
                break; 
            }
            bool nightmare = true;
           while(nightmare)
           {
               character c0 = character("Cloud", CharacterType::Warrior);
               character c1 = character("Barret", CharacterType::Tank);
               character c2 = character("AeRith", CharacterType::Mage);
               character c3 = character("Tifa", CharacterType::Rouge);




               enemy e0 = enemy("SephiRoth", 1500, 50, 20);


               Party party(c0, c1, c2, c3);
               InATBBAttle(party, e0, 4);
               std::cout << "\n--- Nightmare Reset ---\npress ESC to exit Nightmare\n";
               system("pause");
               if(_getch()==KEY_ESC)
               {
                   std::cout << "Don't Leave";
                   system("pause");
                   nightmare = false;
               }
               
           }
         
        }
        case MainMenu::quit:
            system("CLS");
            std::cout << "Your Nightmare Will Never ENDD!!!";
            mainMenu = false;
            break;
        }
    }
       
  
    return 0;
}


   