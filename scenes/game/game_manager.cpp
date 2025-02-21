#include "save.hpp"
#include "main.hpp"
namespace qm = quickmode;

std::string gameMode[2]; // game mode name and description

void displayGameplay(int& id){
    system("cls");
    // std::cout<<"\033[?25l"; // hide cursor
    std::cout<<"\033[?25h"; // show cursor for debugging

    switch(id){
        case 0:
            gameMode[0] = "QUICK MODE";
            gameMode[1] = "Guess the country name from a random region!";
            break;
        case 1:
            gameMode[0] = "REGIONAL MODE";
            gameMode[1] = "Guess the country name from a random region!";
            break;
        default:
            std::cerr << "Invalid game ID!" << std::endl;
            state::isPlaying = false;
    }

    std::cout << "[\033[32m" << gameMode[0] << "\033[0m - " << gameMode[1] << "]\n";

    switch(id){
        case 0:
            play::quickMode();
            break;
        case 1:
            play::regionalMode();
            break;
        default:
            std::cerr << "Invalid game ID!" << std::endl;
            state::isPlaying = false;
    }
}
