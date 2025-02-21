#include "save.hpp"
#include "main.hpp"

int game::totalPlayCount(){
    return quickModeWon + quickModeLost + streakModeWon + streakModeLost;
}

int game::quickModeCount(){
    return quickModeWon + quickModeLost;
}

int game::streakModeCount(){
    return streakModeWon + streakModeLost;
}

void statisticsMenu(){
    printLine(misc::titleLength);
    std::cout << "- Total Games Played:" << repeatString(" ", misc::titleLength - (21 + getDigits(game::totalPlayCount()))) << game::totalPlayCount() << "\n";
    printLine(misc::titleLength);

    std::cout << "Quick Mode:\n";
    std::cout << "  - Games Played:" << repeatString(" ", misc::titleLength - (17 + getDigits(game::quickModeCount()))) << game::quickModeCount() << "\n";
    std::cout << "  - Games Won:" << repeatString(" ", misc::titleLength - (14 + getDigits(game::quickModeWon))) << game::quickModeWon << "\n";
    std::cout << "  - Games Lost:" << repeatString(" ", misc::titleLength - (15 + getDigits(game::quickModeLost))) << game::quickModeLost << "\n";

    printLine(misc::titleLength);

    std::cout << "Streak Mode:\n";
    std::cout << "  - COMING SOON\n";

    printLine(misc::titleLength);
    std::cout << ansiText("! Press [Shift + Q] to Back.", "93");

    while(true){
        if(_kbhit()){
            char ch = _getch();

            if(ch == 'Q'){
                break;
            }
        }
    }

    state::menuId = 0;
}