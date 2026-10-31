#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<conio.h>


constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_ENTER = 13;
constexpr auto KEY_ESC = 27;;

enum class MainMenu
{
	StartGame,
	loadSave,
	quit,
	Count
};

enum class IngameMenu
{
	stats,
	party,
	inventory,
	weapons,
	spells,
	count

};

enum class Battlemenu
{
    Attack,
    spells,
    items,

};



template <typename EnumType>
EnumType runMenuLoop(const std::string& menuTitle, const std::vector<std::string>& options, int enumCountValue) {
    bool menuRunning = true;
    int currentSelection = 0;
    int totalOptions = enumCountValue;
    while (menuRunning) {
        system("CLS");
        std::cout << menuTitle << "\n";


        for (int i = 0; i < totalOptions; ++i) {
            if (i == currentSelection) {
                std::cout << "-> " << options[i] << " <-\n";
            }
            else {
                std::cout << "   " << options[i] << "\n";
            }
        }

        int ch = _getch();
        if (ch == 224) {
            switch (_getch()) {
            case KEY_UP:
                currentSelection = (currentSelection == 0) ? totalOptions - 1 : currentSelection - 1;
                break;
            case KEY_DOWN:
                currentSelection = (currentSelection == totalOptions - 1) ? 0 : currentSelection + 1;
                break;
            }
        }
        else if (ch == KEY_ENTER) {
            return static_cast<EnumType>(currentSelection);
        }
        else if (ch == KEY_ESC) {
            return static_cast<EnumType>(-1);
        }
    }
    return static_cast<EnumType>(-1);
}
