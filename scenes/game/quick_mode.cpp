#include "save.hpp"
#include "main.hpp"
namespace qm = quickmode;

void play::quickMode(){
    std::unordered_map<std::string, std::vector<std::string>> regions = {
        {"asia", asia},
        {"europe", europe},
        {"africa", africa},
        {"north america", north_america},
        {"south america", south_america},
        {"oceania", oceania}
    };
    
    std::string regionName = "asia";
    const std::vector<std::string>& region = regions[regionName];

    // Only restart var if game finish
    if(qm::answer == ""){
        while(true){
            qm::answer = region[rand() % region.size()];
            if(qm::answer.size() <= 6){
                break;
            }
        }
        qm::playerInput = "";
    }

    int maxAttempts = (qm::answer.size() <= 6) ? 5 : qm::answer.size() - 1;
    unsigned int greenLetterCount = 0;

    // Starting print line
    std::cout<<"[Press \033[1mShift + Q\033[0m to Quit (Your progress will be saved.)]\n";
    printLine(misc::titleLength);
    std::cout << "Guess a \033[1m" << qm::answer.size() << "\033[0m-letter country within \033[1m" << maxAttempts << "\033[0m attempts! ("  << qm::answer << ")\n";
    std::cout << "Continent: \033[1m" << toUpper(regionName) << "\033[0m\n\n";

    // Print guesses
    if(qm::playerGuesses.size() != 0){
        int counter = 1;
        for(auto str : qm::playerGuesses){
            std::cout << "<" << counter << "> " << coloredGuessString(str, toUpper(qm::answer), greenLetterCount) << "\n\n";
            counter++;
        }
        for(int i = counter - 1; i < maxAttempts; i++){
            if(i > counter - 1){
                std::cout<<"\033[90m";
            }
            std::cout<<"<"<<i+1<<"> "<<repeatString("- ", qm::answer.size())<<"\n\n";
        }
        greenLetterCount = 0;
    }
    else{
        for(int i = 0; i < maxAttempts; i++){
            if(i > 0){
                std::cout<<"\033[90m";
            }
            std::cout<<"<"<<i+1<<"> ";
            for(std::size_t i = 0; i < qm::answer.size(); i++){
                std::cout<<"- ";
            }
            std::cout<<"\n\n";
        }
    }
    std::cout<<"\033[0m"; // reset color

    printLine(misc::titleLength);

    std::cout<<"\033[93m! Type with keyboard to guess.\n  You can only ENTER a valid nation name.\033[0m\n";

    printLine(misc::titleLength);

    std::cout<<"\033["<<7+qm::playerGuesses.size()*2<<";5H"; // move cursor to appropriate position

    while(true){
        if(_kbhit()){
            char ch = _getch();
            char CH = toupper(ch);

            if(ch == 'Q'){ // Shift + Q to Quit
                break;
            }
            else if(ch == '\b'){ // backspace
                if(qm::playerInput.size() > 0){
                    qm::playerInput.pop_back();
                    std::cout << "\033[2D-\033[1D";
                }
            }
            else if(ch == '\r'){ // enter to check guess
                if(qm::playerInput.size() == qm::answer.size()){
                    if(validCountries.find(toLower(qm::playerInput)) != validCountries.end()){ // validate user input
                        qm::playerGuesses.push_back(qm::playerInput);
                        qm::guess++;

                        std::cout << "\033[5G" << coloredGuessString(qm::playerInput, toUpper(qm::answer), greenLetterCount);

                        if(greenLetterCount == qm::answer.size()){
                            qm::gameEndState = 1;
                            qm::guess--;
                            break;
                        }

                        // Check if last attempt is done
                        if(qm::guess > maxAttempts){
                            qm::gameEndState = greenLetterCount == qm::answer.size() ? 1 : 0 ;
                            qm::guess--;
                            break;
                        }

                        std::cout << "\033[2B\033[1G" << "<" << qm::guess << "> " << repeatString("- ", qm::answer.size()) << "\033[5G";
                        
                        qm::playerInput = "";
                        greenLetterCount = 0;
                        saveStateGame();
                    }
                }
            }
            else{ // Print the character to the screen
                if(isalpha(CH) && qm::playerInput.size() < qm::answer.size()){
                    std::cout << CH << "\033[1C";
                    qm::playerInput += CH;
                }
            }
        }
    }

    // If game ends (win/lose)
    if(qm::gameEndState != -1){
        std::string winMessage = "";
    
        if(qm::guess == 1){ winMessage = "LUCKY MAN!"; }
        else if(qm::guess == maxAttempts){ winMessage = "PHEW."; }
        else{ winMessage = "WELL DONE."; }

        std::cout<<"\033["<< 8 + maxAttempts*2 <<";1H";
        switch(qm::gameEndState){
            case 0: // Lose
                std::cout<<"\033[31mOH NO.\033[0m The answer is \033[32m"<<toUpper(qm::answer)<<"\033[0m! Better luck next time.\n";
                game::quickModeLost++;
                break;
            case 1: // Win
                std::cout<<"\033[32m"<<winMessage<<"\033[0m You've guessed it in \033[32m"<<qm::guess<<"\033[0m " << (qm::guess == 1 ? "guess!" : "guesses!") << " Keep up that skill.\n";

                // If country haven't discovered
                if(collectedCountries[capitalize(regionName)].find(qm::answer) == collectedCountries[capitalize(regionName)].end()){
                    std::cout << "\033[KNew country added to Collections: " << ansiText(toUpper(qm::answer), "32") << "!\n\n";
                }

                game::quickModeWon++;
                collectedCountries[capitalize(regionName)].insert(qm::answer);
                break;
        }
        std::cout<<"\033[K[Shift + Q] for Exit. [Enter] to Play Again.\n";
        printLine(misc::titleLength);

        while(true){
            if(_kbhit()){
                char ch = _getch();

                if(ch == 'Q'){ // Shift + Q to Quit
                    qm::guess = 1;
                    qm::gameEndState = -1;
                    qm::answer = "";
                    break;
                }
                else if(ch == '\r'){
                    qm::guess = 1;
                    qm::gameEndState = -1;
                    qm::answer = "";
                    qm::playerGuesses.clear();
                    goto playAgain;
                }
            }
        }

        qm::playerGuesses.clear();
        saveStateGame();
        saveDataGame();    
    }

    state::gameId = -1;
    state::menuId = 2;

    // GOTO (hell nah)
    playAgain:

    saveStateGame();
    saveDataGame();
    state::gameId = 0;
}
