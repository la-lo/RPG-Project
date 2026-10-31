


#include"Menu.h"
#include"CharacterType.h"
#include"character.h"





int main()
{
    std::vector<std::string> Gameoptions =
    {
        "Start Game",
        "Load  Save",
        "Quit Game"
    };
    std::vector<std::string>  playeroptions = 
    { 
     "Stats",
    "Party",
    "Inventory",
    "Weapons",
    "Spells" };

    std::cout<<getClassName(CharacterType::Warrior);
    
    
    int totalGOptions = static_cast<int>(IngameMenu::count);

    bool mainMenu = true;
    bool chaMenu = true;
    int currentselection = 0;
    character c1 = character("cloud", CharacterType::Warrior);
    character c2 = character("Barret", CharacterType::Tank);
    character c3 = character("Areith", CharacterType::Mage);
    character c4 = character("Tifa", CharacterType::Rouge);

    while (mainMenu)
    {
        MainMenu mainChoice = runMenuLoop<MainMenu>("\t----Main Menu----\n", Gameoptions, static_cast<int>(MainMenu::Count));

        switch (mainChoice)
        {
        case MainMenu::StartGame:
        {
            system("CLS");

            std::cout << "WELCOME LET OUR ADVENTURE BEGIN!!!";
            _getch();
            while (chaMenu)
            {
                IngameMenu gamechoice = runMenuLoop<IngameMenu>("\t----Character Menu----", playeroptions, static_cast<int>(IngameMenu::count));
                if (static_cast<int>(gamechoice)==-1)
                {
                    chaMenu = false;
                    break;
                }
                system("CLS");
                switch (gamechoice)
                {
                case IngameMenu::stats:
                    system("CLS");
                    std::cout << "\t---PLAYER STATS---\n";
                    c1.DisplayCharacterSheet();
                    c2.DisplayCharacterSheet();
                    c3.DisplayCharacterSheet();
                    c4.DisplayCharacterSheet();
                    break;
                case IngameMenu::party:
                    system("CLS");
                    std::cout << "\t---PARTY---\n";
                    break;
                case IngameMenu::inventory:
                    system("CLS");
                    std::cout << "\t---INVENTORY---";
                    break;
                case IngameMenu::weapons:
                    system("CLS");
                    std::cout << "\t---WEAPONS---\n";
                    break;
                case IngameMenu::spells:
                    system("CLS");
                    std::cout << "\t---SPELLS---\n";
                    break;
                }
                std::cout << "\nPress ESC to Return To Character Menu.";
                while (_getch() != KEY_ESC);
                
            }break;
        }
        case MainMenu::loadSave:
            std::cout << "\n---Select Load Save---\n"; 
            std::cout << "\nPress ESC to Return To Main Menu.";
            while (_getch() != KEY_ESC);
                break;
        case MainMenu::quit:
            system("CLS");
            std::cout << "BYE, WE WILL MEET AGAIN";
            mainMenu = false;
            break;
        }
    }
       
  
    return 0;
}


   