#include "save.hpp"
#include "main.hpp"
#include <cmath> // for log and abs

void gameTitle(std::string theme){
    if(theme == "default"){
        misc::titleWidth = 8;
        misc::titleLength = 56 - 2;
        // std::cout<<"\033[30;47m";

        std::cout<<" _______  ___      _______  _______  ___      _______ \n";
        std::cout<<"|       ||   |    |       ||  _    ||   |    |       |\n";
        std::cout<<"|    ___||   |    |   _   || |_|   ||   |    |    ___|\n";
        std::cout<<"|   | __ |   |    |  | |  ||       ||   |    |   |___ \n";
        std::cout<<"|   ||  ||   |___ |  |_|  ||  _   | |   |___ |    ___|\n";
        std::cout<<"|   |_| ||       ||       || |_|   ||       ||   |___ \n";
        std::cout<<"|_______||_______||_______||_______||_______||_______|\n";
        std::cout<<"                                                      \n";
    }
    else if(theme == "lean"){
        misc::titleWidth = 7;
        misc::titleLength = 64 - 2;

        std::cout<<"                                                              \n";
        std::cout<<"      _/_/_/  _/          _/_/    _/_/_/    _/        _/_/_/_/\n";
        std::cout<<"   _/        _/        _/    _/  _/    _/  _/        _/       \n";
        std::cout<<"  _/  _/_/  _/        _/    _/  _/_/_/    _/        _/_/_/    \n";
        std::cout<<" _/    _/  _/        _/    _/  _/    _/  _/        _/         \n";
        std::cout<<"  _/_/_/  _/_/_/_/    _/_/    _/_/_/    _/_/_/_/  _/_/_/_/    \n";
        std::cout<<"                                                              \n";
    }
    else if(theme == "block"){
        misc::titleWidth = 7;
        misc::titleLength = 61 - 2;

        std::cout<<"                                                           \n";
        std::cout<<"   _|_|_|  _|          _|_|    _|_|_|    _|        _|_|_|_|\n";
        std::cout<<" _|        _|        _|    _|  _|    _|  _|        _|      \n";
        std::cout<<" _|  _|_|  _|        _|    _|  _|_|_|    _|        _|_|_|  \n";
        std::cout<<" _|    _|  _|        _|    _|  _|    _|  _|        _|      \n";
        std::cout<<"   _|_|_|  _|_|_|_|    _|_|    _|_|_|    _|_|_|_|  _|_|_|_|\n";
        std::cout<<"                                                           \n";
    }
    else if(theme == "sweet"){
        misc::titleWidth = 14;
        misc::titleLength = 50 - 2;

        std::cout<<"          ___            ___       ___          \n";
        std::cout<<"         (   )          (   )     (   )         \n";
        std::cout<<"  .--.    | |    .--.    | |.-.    | |    .--.  \n";
        std::cout<<" /    \\   | |   /    \\   | /   \\   | |   /    \\ \n";
        std::cout<<";  ,-. '  | |  |  .-. ;  |  .-. |  | |  |  .-. ;\n";
        std::cout<<"| |  | |  | |  | |  | |  | |  | |  | |  |  | | |\n";
        std::cout<<"| |  | |  | |  | |  | |  | |  | |  | |  |  |/  |\n";
        std::cout<<"| |  | |  | |  | |  | |  | |  | |  | |  |  ' _.'\n";
        std::cout<<"| '  | |  | |  | '  | |  | '  | |  | |  |  .'.-.\n";
        std::cout<<"'  `-' |  | |  '  `-' /  ' `-' ;   | |  '  `-' /\n";
        std::cout<<" `.__. | (___)  `.__.'    `.__.   (___)  `.__.' \n";
        std::cout<<" ( `-' ;                                        \n";
        std::cout<<"  `.__.                                         \n";
        std::cout<<"                                                \n";
    }
    else if(theme == "train"){
        misc::titleWidth = 6;
        misc::titleLength = 55 - 2; // \n is 2 chars

        std::cout<<"   ___      _        ___      ___      _        ___  \n";
        std::cout<<"  / __|    | |      / _ \\    | _ )    | |      | __| \n";
        std::cout<<" | (_ |    | |__   | (_) |   | _ \\    | |__    | _|  \n";
        std::cout<<"  \\___|    |____|   \\___/    |___/    |____|   |___| \n";
        std::cout<<"_|\"\"\"\"\"| _|\"\"\"\"\"| _|\"\"\"\"\"| _|\"\"\"\"\"| _|\"\"\"\"\"| _|\"\"\"\"\"|\n";
        std::cout<<"\"`-0-0-' \"`-0-0-' \"`-0-0-' \"`-0-0-' \"`-0-0-' \"`-0-0-'\n";
    }
    else if(theme == "epic"){
        misc::titleWidth = 9;
        misc::titleLength = 56 - 2;

        std::cout<<" _______  _        _______  ______   _        _______ \n";
        std::cout<<"(  ____ \\( \\      (  ___  )(  ___ \\ ( \\      (  ____ \\\n";
        std::cout<<"| (    \\/| (      | (   ) || (   ) )| (      | (    \\/\n";
        std::cout<<"| |      | |      | |   | || (__/ / | |      | (__    \n";
        std::cout<<"| | ____ | |      | |   | ||  __ (  | |      |  __)   \n";
        std::cout<<"| | \\_  )| |      | |   | || (  \\ \\ | |      | (      \n";
        std::cout<<"| (___) || (____/\\| (___) || )___) )| (____/\\| (____/\\ \n";
        std::cout<<"(_______)(_______/(_______)|/ \\___/ (_______/(_______/\n";
        std::cout<<"\n";
    }
    else if(theme == "subzero"){
        misc::titleWidth = 6;
        misc::titleLength = 67 - 2;

        std::cout<<" ______     __         ______     ______     __         ______   \n";
        std::cout<<"/\\  ___\\   /\\ \\       /\\  __ \\   /\\  == \\   /\\ \\       /\\  ___\\  \n";
        std::cout<<"\\ \\ \\__ \\  \\ \\ \\____  \\ \\ \\/\\ \\  \\ \\  __<   \\ \\ \\____  \\ \\  __\\  \n";
        std::cout<<" \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\ \n";
        std::cout<<"  \\/_____/   \\/_____/   \\/_____/   \\/_____/   \\/_____/   \\/_____/\n";
        std::cout<<"\n";
    }
    else if(theme == "chunky"){
        misc::titleWidth = 5;
        misc::titleLength = 55 - 2;

        std::cout << R"( _______  _____    _______  ______  _____    _______ )" << "\n";
        std::cout << R"(|     __||     |_ |       ||   __ \|     |_ |    ___|)" << "\n";
        std::cout << R"(|    |  ||       ||   -   ||   __ <|       ||    ___|)" << "\n";
        std::cout << R"(|_______||_______||_______||______/|_______||_______|)" << "\n";
        std::cout << "\n";
    }
    /*else if(theme == ""){
        misc::titleWidth = 5;
        misc::titleLength = 67 - 2;

        std::cout << R"()" << "\n";
        std::cout << R"()" << "\n";
        std::cout << R"()" << "\n";
        std::cout << R"()" << "\n";
        std::cout << R"()" << "\n";
    }
    else if(theme == ""){
        misc::titleWidth = 5;
        misc::titleLength = 67 - 2;

        std::cout << R"()" << "\n";
        std::cout << R"()" << "\n";
        std::cout << R"()" << "\n";
        std::cout << R"()" << "\n";
        std::cout << R"()" << "\n";
    }*/

    std::cout<<"\033[0m";
}

void waitForKeypress(const std::string& message){
    std::cout<<message;
    while(true){
        if(_kbhit()){
            break;
        }
    }
}

std::string ansiText(std::string text, std::string code){
    return "\033[" + code + "m" + text + "\033[0m";

    // 0: Reset - 1: Bold - 2: Dim - 3: Italic - 4: Underline - 9: Strikethrough
    // 30: Black - 31: Red - 32: Green - 33: Yellow - 34: Blue - 35: Magenta - 36: Cyan - 37: White
}

void navigateOption(){
    while(true){
        if(_kbhit()){
            char ch = _getch();
            // std::cout<< "char: " << ch << std::endl;

            if(ch == 'k' || ch == 'K'){ // move cursor up
                if(state::optionId > 0){
                    state::optionId--;
                    std::cout<<"\033[A";
                    if(!conf::cursorAsPointer){
                        break;
                    }
                }
            }
            else if(ch == 'j' || ch == 'J'){ // move cursor down
                if(state::optionId < state::optionAmount - 1){
                    state::optionId++;
                    std::cout<<"\033[B";
                    if(!conf::cursorAsPointer){
                        break;
                    }
                }
            }
            else if(ch == 'h' || ch == 'H'){
                if(state::menuId == 1){ // settings menu
                    if(state::optionId == 0){
                        conf::titleThemeId = (conf::titleThemeId - 1 + conf::titleThemeList.size()) % conf::titleThemeList.size();
                        break;
                    }
                    else if(state::optionId == 1){
                        conf::cursorAsPointer = !conf::cursorAsPointer;
                        break;
                    }
                    else if(state::optionId == 2){
                        conf::disableColors = !conf::disableColors;
                        break;
                    }
                }
            }
            else if(ch == 'l' || ch == 'L'){
                if(state::menuId == 1){ // settings menu
                    if(state::optionId == 0){
                        conf::titleThemeId = (conf::titleThemeId + 1) % conf::titleThemeList.size();
                        break;
                    }
                    else if(state::optionId == 1){
                        conf::cursorAsPointer = !conf::cursorAsPointer;
                        break;
                    }
                    else if(state::optionId == 2){
                        conf::disableColors = !conf::disableColors;
                        break;
                    }
                }
            }
            else if(ch == '\r'){ // ENTER
                if(state::menuId == 1){ // settings menu
                    if(state::optionId == 3){
                        state::switchScene = true;
                        break;
                    }
                } else {
                    state::switchScene = true;
                    break;
                }
            }
        }
    }
}

void printLine(int length){
    for(int i = 0; i < length; i++){
        std::cout<<"-";
    }
    std::cout<<"\n";
}

std::string toUpper(const std::string& text){
    std::string upper = "";
    for(char c: text){
        upper += toupper(c);
    }
    return upper;
}

std::string toLower(const std::string& text){
    std::string lower = "";
    for(char c: text){
        lower += tolower(c);
    }
    return lower;
}

void printOutroMessage(){
    system("cls");
    std::cout<<"GOODBYE!\n";
    waitForKeypress("Press any key to proceed...");
}

bool isSingleWord(const std::string& str) {
    return str.find(' ') == std::string::npos;
}

std::string repeatString(const std::string& str, int n){
    std::string repeated = "";
    for(int i = 0; i < n; i++){
        repeated += str;
    }
    return repeated;
}

std::string coloredGuessString(const std::string& guess, const std::string& answer, unsigned int& greenCounter){
    std::string str = "";
    if(guess.size() != answer.size()){
        return "Guess length does not match answer length!";
    }
    else{
        for(std::size_t i = 0; i < guess.size(); i++){
            if(guess[i] == answer[i]){ // green
                str = str + "\033[32m" + guess[i] + "\033[0m ";
                greenCounter++;
            }
            else if(answer.find(guess[i]) != std::string::npos){ // yellow
                str = str + "\033[33m" + guess[i] + "\033[0m ";
            }
            else{ // grey
                str = str + "\033[90m" + guess[i] + "\033[0m ";
            }
        }
    }
    return str;
}

std::string capitalize(const std::string& text){
    std::string str = "";
    int i = 0;

    for(char ch : text){
        if(i == 0){
            str += toupper(ch);
        }
        else{
            str += ch;
        }
        i++;
    }
    return str;
}

int getDigits(const int& n){
    return (n == 0) ? 1 : static_cast<int>(log10(abs(n))) + 1;
}

void totalCollectedCountries(){
    int n = 0;
    for(const auto& region : regions){
        n += collectedCountries[region.name].size();
    }
    game::totalCollectedCountries = n;
}
