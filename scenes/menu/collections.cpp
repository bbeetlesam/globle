#include "save.hpp"
#include "main.hpp"

std::string Region::getDisplayString() const{
    auto it = collections.find(name);
    if(it != collections.end()){
        return std::string("[") + std::to_string(it->second.size()) + "/" + std::to_string(region.size()) + "]";
    }
    return std::string("[ErrorFuckIt") + "/" + std::to_string(region.size()) + "]";
}

void collectionsMenu(){
    state::optionAmount = regions.size() + 1;

    printLine(misc::titleLength);
    std::cout << "Discovered Countries: \033[1m" << repeatString(" ", misc::titleLength - (22 + 4 + getDigits(game::totalCollectedCountries))) << game::totalCollectedCountries << "/" << allCountries.size() << "\033[0m\n";
    printLine(misc::titleLength);
    for(int i = 0; i < static_cast<int>(regions.size()); i++){
        const auto& region = regions[i];

        std::cout << ((state::optionId == i || conf::cursorAsPointer) ?
            ansiText("> " + region.name, "1") + repeatString(" ", misc::titleLength - (("> " + region.name).size() + region.getDisplayString().size())) + ansiText(region.getDisplayString(), "1") : 
            ansiText("  " + region.name, "90") + repeatString(" ", misc::titleLength - (("> " + region.name).size() + region.getDisplayString().size())) + ansiText(region.getDisplayString(), "90"))
        << "\n";
    }
    std::cout << ((state::optionId == 6 || conf::cursorAsPointer) ? ansiText("> Back to Menu", "1") : ansiText("  Back to Menu", "90")) << "\n";
    printLine(misc::titleLength);
    // std::cout << "\033[93m! Select/toggle options using 'h' and 'l' keys\n  Use Enter to Back to Menu\033[0m\n";
    // printLine(misc::titleLength);
    std::cout << misc::version;

    std::cout << "\033[" << misc::titleWidth + 2 + 2 << ";1H"; // move cursor
    navigateOption();

    if(state::switchScene){
        switch(state::optionId){
            case 0: state::menuId = 4;
            break;
            case 1: state::menuId = 5;
            break;
            case 2: state::menuId = 6;
            break;
            case 3: state::menuId = 7;
            break;
            case 4: state::menuId = 8;
            break;
            case 5: state::menuId = 9;
            break;
            case 6: state::menuId = 0;
            break;
        }
    }
}

void collectionsShowMenu(){
    printLine(misc::titleLength);

    switch(state::menuId){
        case 4: // Asia
            std::cout << "\033[96mASIA" << repeatString(" ", misc::titleLength - (4 + regions[state::menuId - 4].getDisplayString().size())) << regions[state::menuId - 4].getDisplayString() << "\033[0m\n";
            std::cout << "The largest and most populous continent in the world,\nwith over 60% of the world's population living here.\n";
            printLine(misc::titleLength);

            break;
        case 5: // Africa
            std::cout << "\033[96mAFRICA" << repeatString(" ", misc::titleLength - (6 + regions[state::menuId - 4].getDisplayString().size())) << regions[state::menuId - 4].getDisplayString() << "\033[0m\n";
            std::cout << "The second-largest continent, covering over 20% of the Earth's\nland area and home to the Nile, the longest river in the world.\n";
            printLine(misc::titleLength);

            break;
    }

    std::cout << "Discovered Countries:\n\n";

    // Print all continent's discovered countries
    if(collectedCountries[regions[state::menuId - 4].name].size() > 0){
        for(const auto& country : collectedCountries[regions[state::menuId - 4].name]){
            std::cout << "- " << capitalize(country) << "\n";
        }
        std::cout << "\n";
    } else {
        std::cout << ansiText("! Cari lagi blok.\n\n", "93");
    }

    printLine(misc::titleLength);

    std::cout << ansiText("! Press [Shift + Q] to Back.", "93");

    while(true){
        if(_kbhit()){
            char ch = _getch();

            if(ch == 'Q'){
                state::menuId = 3;
                break;
            }
        }
    }
}
