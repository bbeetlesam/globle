#ifndef SAVE_HPP
#define SAVE_HPP
 
#include "main.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
using json = nlohmann::json;

void initLoadData();
void saveDataSettings();
void saveDataGame();
void saveStateGame();
void loadStateGame(json& data);

void totalCollectedCountries();

namespace conf{ //configurations in settings
    extern std::string savePath;
    inline bool cursorAsPointer = false;
    inline int titleThemeId = 0;
    inline std::vector<std::string> titleThemeList = {
        "default", "lean", "block", "sweet", "train", "epic", "subzero", "chunky"
    };
    inline bool disableColors = false;
}

namespace game{ //game data
    inline unsigned int totalCollectedCountries = 0;
    inline unsigned int quickModeLost = 0;
    inline unsigned int quickModeWon = 0;
    inline unsigned int streakModeLost = 0;
    inline unsigned int streakModeWon = 0;

    int totalPlayCount();
    int quickModeCount();
    int streakModeCount();
}

namespace quickmode{
    inline std::string answer;
    inline std::string playerInput = "";
    inline std::vector<std::string> playerGuesses;
    inline int guess = 1;
    inline int gameEndState = -1;
}

#endif //SAVE_HPP