#include <iostream>
#include "struct.h"
#include <string>
#include <ctime>
#include <fstream>

using namespace std;


void demoMode() {
    vector<Monster> localStorage, demoDB;
    cout << "\n----- DEMO MODE -----\n";

    cout << "\n\n@@@@@    INSERTING 10 ELEMENTS TO DATABASE    @@@@@\n\n";
    loadingAnimation();
    for (int i = 0; i < 10; i++) {
        insertMonster(localStorage, false);
    }
    cout << "\n***** Elements inserted succesfully! *****\n";


    cout << "\n\n@@@@@ SAVING THE DATABASE TO LOCAL STORAGE @@@@@\n\n";
    loadingAnimation();
    demoDB = localStorage;
    cout << "\n***** Database saved successfully! *****\n";

    cout << "\n\n@@@@@ RECORDING THE DATABASE FROM LOCAL STORAGE @@@@@\n\n";
    loadingAnimation();
    localStorage = demoDB;
    cout << "\n***** Database was recorded successfully! *****\n";


    cout << "\n\n@@@@@    SELECTING ALL THE MONSTERS    @@@@@\n\n";
    loadingAnimation();
    SelectAllMonsters(localStorage);
    cout << "\n***** All the monsters selected! *****\n";


    cout << "\n\n@@@@@ SELECTING MONSTER WITH THE LETTER 'm' IN NAME @@@@@\n\n";
    loadingAnimation();
    loadingAnimation();
    searchByNameEnding(localStorage, "m");


    cout << "\n\n@@@@@ SELECTING MONSTER WITH THE SPECIAL ATTACK TYPE 'Fire'  @@@@@\n\n";
    loadingAnimation();
    loadingAnimation();
    searchBySpecialAttackType(localStorage, "Fire");


    cout << "\n\n@@@@@ SELECTING MONSTER WITH THE SPECIAL ATTACK PERCENTAGE HIGHER THAN 0.5  @@@@@\n\n";
    loadingAnimation();
    loadingAnimation();
    searchBySpecialAttackPercentage(localStorage, 0.5);


    cout << "\n\n@@@@@ SELECTING MONSTER WITH THE APPEARANCE TIME FROM 3 HOURS AGO TO NOW  @@@@@\n\n";
    auto currentTime = chrono::system_clock::now();
    auto threeHoursAgo = currentTime - chrono::hours(3);
    time_t threeHoursAgoTimeT = chrono::system_clock::to_time_t(threeHoursAgo);
    time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);
    loadingAnimation();
    loadingAnimation();
    searchByAppearanceTime(localStorage, threeHoursAgoTimeT, currentTimeT);


    cout << "\n\n@@@@@ UPDATE ELEMENT WITH RANDOM ID IN DATABASE. CHANGE THE ELEMENT NAME TO 'Monster_1' @@@@@ \n\n";
    loadingAnimation();
    int randomNum = rand() % 10 + 1;
    localStorage[randomNum].name = "Monster_1";
    cout << "\n***** Monster name changed! *****\n";

    cout << "\n\n@@@@@ DELETING ELEMENT WITH RANDOM ID FROM THE LOCAL DATABASE @@@@@\n\n";
    loadingAnimation();
    randomNum = rand() % 10 + 1;
    localStorage.erase(localStorage.begin() + randomNum);
    cout << "\n***** Element with ID 5 was deleted! *****\n";

    cout << "\n\n@@@@@ SAVE THE DATABASE @@@@@\n\n";
    loadingAnimation();
    demoDB = localStorage;
    cout << "\n***** Database was saved successfully! *****\n";

    cout << "\n\n@@@@@ PRINT THE DATABASE @@@@@\n\n";
    loadingAnimation();
    SelectAllMonsters(localStorage);


    cout << "\n\n@@@@@ EXIT @@@@@\n\n";

}