#include "save.hpp"
#include "main.hpp"

bool state::isPlaying = true;

int main(){
    initLoadData();
    initCountries();

    while(state::isPlaying){
        srand(time(0));

        if(state::menuId >= 0){
            displayMenu(state::menuId);
        } else {
            displayGameplay(state::gameId);
        }

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
    printOutroMessage();

    return 0;
}
