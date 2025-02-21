#include "save.hpp"
#include "main.hpp"
namespace qm = quickmode;

void play::regionalMode(){
    if(!(game::totalCollectedCountries >= 10)){
        std::cout << "This mode is currently \033[31;1mLOCKED\033[0m!\n";
        printLine(misc::titleLength);
        std::cout << "Collect \033[33;1m" << game::totalCollectedCountries << "/10\033[0m countries in Quick Play to unlock this mode.\n\n";
        std::cout << "[Press \033[1mShift + Q\033[0m or \033[1mENTER\033[0m to Back]\n";

        while(true){
            if(_kbhit()){
                char ch = _getch();

                if(ch == 'Q' || ch == '\r'){
                    state::gameId = -1;
                    state::menuId = 2;
                    break;
                }
            }
        }
    }
    else{ // Gameplay
        std::cout << "shift + q to exit\n";
        printLine(misc::titleLength);

        while(true){
            if(_kbhit()){
                char ch = _getch();

                if(ch == 'Q' || ch == '\r'){
                    state::gameId = -1;
                    state::menuId = 2;
                    break;
                }
            }
        }
    }
}
