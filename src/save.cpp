#include "save.hpp"
#include "main.hpp"
namespace qm = quickmode;

std::string conf::savePath = "bin/data.json"; // DONT FORGET TO CHANGE IT IN RELEASE VER

void initLoadData(){
    // Check if data.json is exist or not (first time)
    std::ifstream infile(conf::savePath);
    if(infile.is_open()){
        json data;

        infile >> data;
        infile.close();

        // Load all Game and Settings data
        conf::titleThemeId = data["settings"]["titleTheme"]["titleThemeId"];
        conf::cursorAsPointer = data["settings"]["cursorAsPointer"];
        conf::disableColors = data["settings"]["disableColors"];

        game::quickModeWon = data["game"]["quickMode"]["gameWon"];
        game::quickModeLost = data["game"]["quickMode"]["gameLost"];

        // Load all Collections data
        if(!data["collections"]["asia"].is_null()){
            auto array = data["collections"]["asia"].get<std::vector<std::string>>();
            for (const auto& country : array) {
                collectedCountries["Asia"].insert(country);
            }
        }

        loadStateGame(data);

        // Load other data
        totalCollectedCountries();

        regions = {
            {"Asia", asia, collectedCountries},
            {"Africa", africa, collectedCountries},
            {"Europe", europe, collectedCountries},
            {"North America", north_america, collectedCountries},
            {"South America", south_america, collectedCountries},
            {"Oceania (Australia)", oceania, collectedCountries}
        };
    }
    else{
        json data;

        // Create a json file with elements below
        data["settings"] = {
            {"cursorAsPointer", conf::cursorAsPointer},
            {"titleTheme", {
                {"titleThemeId", conf::titleThemeId},
                {"titleThemeName", conf::titleThemeList[conf::titleThemeId]},
            }},
            {"disableColors", conf::disableColors}
        };
        data["game"] = {
            {"quickMode", {
                {"gamePlayed", game::quickModeWon + game::quickModeLost},
                {"gameWon", game::quickModeWon},
                {"gameLost", game::quickModeLost},
                {"state", {
                    {"playerGuesses", qm::playerGuesses},
                    {"currentAnswer", qm::answer},
                    {"currentGuess", qm::guess}
                }}
            }}
        };
        data["collections"] = {
            {"asia", collectedCountries["Asia"]},
            {"africa", collectedCountries["Africa"]},
            {"europe", collectedCountries["Europe"]},
            {"north america", collectedCountries["North America"]},
            {"south america", collectedCountries["South America"]},
            {"oceania", collectedCountries["Oceania (Australia)"]},
        };

        std::ofstream savefile(conf::savePath);
        if(savefile.is_open()){
            savefile << data.dump(4);
            savefile.close();
        } else {
            std::cerr << "Failed to open file for saving data." << std::endl;
        }
    }

    return;
}

void saveDataSettings(){
    std::ifstream infile(conf::savePath);
    json data;
    infile >> data;
    infile.close();

    data["settings"]["cursorAsPointer"] = conf::cursorAsPointer;
    data["settings"]["titleTheme"]["titleThemeId"] = conf::titleThemeId;
    data["settings"]["titleTheme"]["titleThemeName"] = conf::titleThemeList[conf::titleThemeId];
    data["settings"]["disableColors"] = conf::disableColors;

    std::ofstream savefile(conf::savePath);
    if (savefile.is_open()) {
        savefile << data.dump(4);
        savefile.close();
    } else {
        std::cerr << "Failed to open file for saving data." << std::endl;
    }
}

void saveDataGame(){
    std::ifstream infile(conf::savePath);
    json data;
    infile >> data;
    infile.close();

    data["game"]["quickMode"]["gameWon"] = game::quickModeWon;
    data["game"]["quickMode"]["gameLost"] = game::quickModeLost;
    data["game"]["quickMode"]["gamePlayed"] = game::quickModeWon + game::quickModeLost;

    // Save discovered countries
    data["collections"]["asia"] = collectedCountries["Asia"];
    data["collections"]["africa"] = collectedCountries["Africa"];

    std::ofstream savefile(conf::savePath);
    if (savefile.is_open()) {
        savefile << data.dump(4);
        savefile.close();
    } else {
        std::cerr << "Failed to open file for saving data." << std::endl;
    }
}

void saveStateGame(){
    std::ifstream infile(conf::savePath);
    json data;
    infile >> data;
    infile.close();

    if(state::gameId == 0){ // Quick Mode
        data["game"]["quickMode"]["state"]["playerGuesses"] = qm::playerGuesses;
        data["game"]["quickMode"]["state"]["currentAnswer"] = qm::answer;
        data["game"]["quickMode"]["state"]["currentGuess"] = qm::guess;
    }

    std::ofstream savefile(conf::savePath);
    if (savefile.is_open()) {
        savefile << data.dump(4);
        savefile.close();
    } else {
        std::cerr << "Failed to open file for saving data." << std::endl;
    }
}

void loadStateGame(json& data){
    // Quick Mode state
    qm::answer = data["game"]["quickMode"]["state"]["currentAnswer"];
    qm::guess = data["game"]["quickMode"]["state"]["currentGuess"];
    qm::playerGuesses = data["game"]["quickMode"]["state"]["playerGuesses"].get<std::vector<std::string>>();
    
}
