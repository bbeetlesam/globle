#include "main.hpp"
#include <iterator>

// Init
void initCountries(){
    // Copy all countries to vector allCountries
    std::copy(asia.begin(), asia.end(), std::back_inserter(allCountries));
    std::copy(africa.begin(), africa.end(), std::back_inserter(allCountries));
    std::copy(europe.begin(), europe.end(), std::back_inserter(allCountries));
    std::copy(north_america.begin(), north_america.end(), std::back_inserter(allCountries));
    std::copy(south_america.begin(), south_america.end(), std::back_inserter(allCountries));
    std::copy(oceania.begin(), oceania.end(), std::back_inserter(allCountries));

    // Copy vector allCountries to set validCountries
    validCountries.insert(allCountries.begin(), allCountries.end());

    // Copy every country in allCountries to either vector singleWordCountries or multipleWordCountries
    for(const auto& country : allCountries){
        if(isSingleWord(country)){
            singleWordCountries.push_back(country);
        } else {
            multipleWordCountries.push_back(country);
        }
    }
}

// Asia
std::vector<std::string> asia = {
    "afghanistan", "saudi arabia", "armenia", "azerbaijan", "bahrain",
    "bangladesh", "bhutan", "brunei", "china", "philippines",
    "georgia", "india", "indonesia", "iraq", "iran",
    "japan", "jordan", "cambodia", "kazakhstan",
    "kuwait", "kyrgyzstan", "laos", "lebanon", "malaysia",
    "maldives", "mongolia", "myanmar", "nepal", "north korea",
    "oman", "pakistan", "palestine", "qatar", "south korea",
    "russia", "singapore", "sri lanka", "syria", "tajikistan",
    "thailand", "timor-leste", "turkey", "turkmenistan", "united arab emirates",
    "uzbekistan", "vietnam", "yemen", /*"israel"*/
};

// Africa
std::vector<std::string> africa = {
    "south africa", "algeria", "angola", "benin", "botswana",
    "burkina faso", "burundi", "cape verde", "cameroon", "central african republic",
    "chad", "comoros", "congo", "democratic republic of the congo", "djibouti",
    "egypt", "equatorial guinea", "eritrea", "eswatini", "ethiopia",
    "gabon", "gambia", "ghana", "guinea", "guinea-bissau",
    "ivory coast", "kenya", "lesotho", "liberia", "libya",
    "madagascar", "malawi", "mali", "mauritania", "mauritius",
    "morocco", "mozambique", "namibia", "niger", "nigeria",
    "rwanda", "sao tome and principe", "senegal", "seychelles", "sierra leone",
    "somalia", "sudan", "tanzania", "togo", "tunisia",
    "uganda", "zambia", "zimbabwe"
};

// Europe
std::vector<std::string> europe = {
    "albania", "andorra", "armenia", "austria", "azerbaijan",
    "belarus", "belgium", "bosnia and herzegovina", "bulgaria", "croatia",
    "cyprus", "czechia", "denmark", "estonia", "finland",
    "france", "georgia", "germany", "greece", "hungary",
    "iceland", "ireland", "italy", "kazakhstan", "kosovo",
    "latvia", "liechtenstein", "lithuania", "luxembourg", "malta",
    "moldova", "monaco", "montenegro", "netherlands", "north macedonia",
    "norway", "poland", "portugal", "romania", "russia",
    "san marino", "serbia", "slovakia", "slovenia", "spain",
    "sweden", "switzerland", "turkey", "ukraine", "united kingdom",
    "vatican city"
};

// North America
std::vector<std::string> north_america = {
    "antigua and barbuda", "bahamas", "barbados", "belize", "canada",
    "costa rica", "cuba", "dominica", "dominican republic", "el salvador",
    "grenada", "guatemala", "haiti", "honduras", "jamaica", "mexico",
    "nicaragua", "panama", "saint kitts and nevis", "saint lucia",
    "saint vincent and the grenadines", "trinidad and tobago", "united states"
};

// South America
std::vector<std::string> south_america = {
    "argentina", "bolivia", "brazil", "chile", "colombia",
    "ecuador", "guyana", "paraguay", "peru", "suriname",
    "uruguay", "venezuela"
};

// Oceania
std::vector<std::string> oceania = {
    "australia", "fiji", "kiribati", "marshall islands", "micronesia",
    "nauru", "new zealand", "palau", "papua new guinea", "samoa",
    "solomon islands", "tonga", "tuvalu", "vanuatu"
};

// Declarations
std::vector<std::string> allCountries;
std::vector<std::string> singleWordCountries;
std::vector<std::string> multipleWordCountries;
std::unordered_set<std::string> validCountries;
std::unordered_map<std::string, std::set<std::string>> collectedCountries = {
    {"Asia", {}},
    {"Africa", {}},
    {"Europe", {}},
    {"North America", {}},
    {"South America", {}},
    {"Oceania (Australia)", {}},
};

// For Collections
std::vector<Region> regions;
