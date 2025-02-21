#include "save.hpp"
#include "main.hpp"

void displayMenu(int& id){
    system("cls");

    // Cursor as Pointer setting
    std::cout << (conf::cursorAsPointer ? "\033[?25h" : "\033[?25l"); // show(h)/hide(l) cursor based on settings

    // Disable Colors setting


    if(state::switchScene){
        state::optionId = 0;
        state::switchScene = false;
    }

    gameTitle(conf::titleThemeList[conf::titleThemeId]);

    switch(id){
        case 0:
            mainMenu();
            break;
        case 1:
            settingsMenu();
            break;
        case 2:
            playMenu();
            break;
        case 3:
            collectionsMenu();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            collectionsShowMenu();
            break;
        case 10:
            statisticsMenu();
            break;
        default:
            std::cerr << "Invalid menu ID!" << std::endl;
            state::isPlaying = false;
    }
}

void mainMenu(){
    state::optionAmount = 5;

    printLine(misc::titleLength);
    std::cout << ((state::optionId == 0 || conf::cursorAsPointer) ? ansiText("> Play", "1") : ansiText("  Play", "90")) << "\n";
    std::cout << ((state::optionId == 1 || conf::cursorAsPointer) ? ansiText("> Collections", "1") : ansiText("  Collections", "90")) << "\n";
    std::cout << ((state::optionId == 2 || conf::cursorAsPointer) ? ansiText("> Statistics", "1") : ansiText("  Statistics", "90")) << "\n";
    std::cout << ((state::optionId == 3 || conf::cursorAsPointer) ? ansiText("> Settings", "1") : ansiText("  Settings", "90")) << "\n";
    std::cout << ((state::optionId == 4 || conf::cursorAsPointer) ? ansiText("> Exit", "1") : ansiText("  Exit", "90")) << "\n";
    printLine(misc::titleLength);
    std::cout << "\033[93m! Navigate using 'j' and 'k' keys, press Enter to proceed\033[0m\n";
    printLine(misc::titleLength);
    std::cout << misc::version;

    std::cout << "\033[" << misc::titleWidth + 2 << ";1H"; // move cursor
    navigateOption();

    if(state::switchScene){
        switch(state::optionId){
            case 0: state::menuId = 2;
            break;
            case 1: state::menuId = 3;
            break;
            case 2: state::menuId = 10;
            break;
            case 3: state::menuId = 1;
            break;
            case 4: state::isPlaying = false;
            break;
        }
    }
}

void playMenu(){
    state::optionAmount = 3;

    // unsigned int totalCountries = 0;
    // for(const auto& region : regions){
    //     totalCountries += collectedCountries[region.name].size();
    // }

    printLine(misc::titleLength);
    std::cout << ((state::optionId == 0 || conf::cursorAsPointer) ? ansiText("> Quick Play", "1") : ansiText("  Quick Play", "90")) << "\n";
    std::cout << ((state::optionId == 1 || conf::cursorAsPointer) ? 
        ansiText(std::string("> Regional Mode ") + (game::totalCollectedCountries < 10 ? "[LOCKED]" : " "), (game::totalCollectedCountries < 10 ? "31;1" : "1")) : 
        ansiText(std::string("  Regional Mode ") + (game::totalCollectedCountries < 10 ? "[LOCKED]" : " "), "90")) << "\n";
    std::cout << ((state::optionId == 2 || conf::cursorAsPointer) ? ansiText("> Back to Menu", "1") : ansiText("  Back to Menu", "90")) << "\n";
    printLine(misc::titleLength);
    std::cout << misc::version;

    std::cout << "\033[" << misc::titleWidth + 2 << ";1H"; // move cursor
    navigateOption();

    if(state::switchScene){
        switch(state::optionId){
            case 0: state::menuId = -1; state::gameId = 0;
            break;
            case 1: state::menuId = -1; state::gameId = 1;
            break;
            break;
            case 2: state::menuId = 0;
            break;
        }
    }
}

void settingsMenu(){
    state::optionAmount = 4;
    std::string title_theme = "<" + toUpper(conf::titleThemeList[conf::titleThemeId]) + ">";
    std::string cursor = std::string("<") + (conf::cursorAsPointer ? "ON" : "OFF") + std::string(">");
    std::string color = std::string("<") + (conf::disableColors ? "ON" : "OFF") + std::string(">");

    printLine(misc::titleLength);
    std::cout << ((state::optionId == 0 || conf::cursorAsPointer) ?
        ansiText("> Title Style", "1") + repeatString(" ", misc::titleLength - (13 + title_theme.size())) + ansiText(title_theme, "1") : 
        ansiText("  Title Style", "90") + repeatString(" ", misc::titleLength - (13 + title_theme.size())) + ansiText(title_theme, "90"))
    << "\n";
    std::cout << ((state::optionId == 1 || conf::cursorAsPointer) ?
        ansiText("> Use Cursor as the Menu Pointer", "1") + repeatString(" ", misc::titleLength - (32 + cursor.size())) + ansiText(cursor, "1") :
        ansiText("  Use Cursor as the Menu Pointer", "90") + repeatString(" ", misc::titleLength - (32 + cursor.size())) + ansiText(cursor, "90"))
    << "\n";
    std::cout << ((state::optionId == 2 || conf::cursorAsPointer) ?
        ansiText("> Disable Colors", "1") + repeatString(" ", misc::titleLength - (16 + color.size())) + ansiText(color, "1") :
        ansiText("  Disable Colors", "90") + repeatString(" ", misc::titleLength - (16 + color.size())) + ansiText(color, "90"))
    << "\n";
    std::cout << ((state::optionId == 3 || conf::cursorAsPointer) ? ansiText("> Back to Menu", "1") : ansiText("  Back to Menu", "90")) << "\n";
    printLine(misc::titleLength);
    std::cout << "\033[93m! Select/toggle options using 'h' and 'l' keys\n  Use Enter to Back to Menu\033[0m\n";
    printLine(misc::titleLength);
    std::cout << misc::version;

    std::cout << "\033[" << misc::titleWidth + 2 << ";1H"; // move cursor
    navigateOption();

    saveDataSettings();

    if(state::switchScene){
        switch(state::optionId){
            case 0: 
            break;
            case 1: conf::cursorAsPointer = !conf::cursorAsPointer;
            break;
            case 2: conf::disableColors = !conf::disableColors;
            break;
            case 3: state::menuId = 0;
            break;
        }
    }
}
