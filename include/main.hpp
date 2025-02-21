#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <conio.h>

// countries.cpp
void initCountries();
extern std::vector<std::string> asia;
extern std::vector<std::string> africa;
extern std::vector<std::string> europe;
extern std::vector<std::string> north_america;
extern std::vector<std::string> south_america;
extern std::vector<std::string> oceania;
extern std::vector<std::string> allCountries;
extern std::vector<std::string> singleWordCountries;
extern std::vector<std::string> multipleWordCountries;
extern std::unordered_set<std::string> validCountries;
extern std::unordered_map<std::string, std::set<std::string>> collectedCountries;

// utils.cpp
void waitForKeypress(const std::string& message);
void printOutroMessage();
void gameTitle(std::string theme);
void navigateOption();
void printLine(int length);
bool isSingleWord(const std::string& str);
int getDigits(const int& n);
std::string ansiText(std::string text, std::string code);
std::string toUpper(const std::string& text);
std::string toLower(const std::string& text);
std::string capitalize(const std::string& text);
std::string repeatString(const std::string& str, int n);
std::string coloredGuessString(const std::string& guess, const std::string& answer, unsigned int& greenCounter);

// scenes.cpp
void displayMenu(int& id);
void mainMenu();
void playMenu();
void settingsMenu();
void collectionsMenu();
void collectionsShowMenu();
void statisticsMenu();

// gameplay.cpp
void displayGameplay(int& id);
namespace play{
    void quickMode();
    void regionalMode();
    void streakMode();
}

// global variables
namespace misc{ //miscellaneous
    inline std::string version = "v0.69a - bbeetlesam";
    inline int titleWidth;
    inline int titleLength;
}

namespace state{ //game states
    inline int menuId = 0;
    inline int gameId = -1;
    inline int optionId;
    inline int optionAmount;
    extern bool isPlaying;
    inline bool switchScene = false;
}

struct Region{
    std::string name;
    std::vector<std::string> region;
    std::unordered_map<std::string, std::set<std::string>> collections;

    std::string getDisplayString() const;
};
extern std::vector<Region> regions;

#endif //MAIN_HPP