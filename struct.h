#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;


#define txtDatabase "txt"
#define binDatabase "binary"
#define generateRandomElem true
#define benchmark true
#define findName true
#define findNumOfUnit true
#define findDate true
#define ZeroValue 0


#ifndef LAB2_1_STRUCT_H
#define LAB2_1_STRUCT_H

#endif //LAB2_1_STRUCT_H

time_t getTimeInput(const string& prompt);

int getIntInput(const string& prompt, int minValue, int maxValue);

double getDoubleInput(const string& prompt, double minValue, double maxValue);

string getStringInput(const string& prompt);

struct Monster {
    int id;
 //   static int count; // Static variable to keep track of the number of monsters
    string name;
    int health;
    int attack;
    double specialAttackChance;
    string specialAttackType;
    time_t appearanceTime;


    void initializeFromUserInput() {
        cout << "Enter monster's name: ";
        this->name = getStringInput("Enter name: ");

        cout << "Enter monster's health (must be an integer <= 50000): ";
        this->health = getIntInput("Enter health: ", 0, 50000);

        cout << "Enter monster's attack (must be an integer <= 2000): ";
        this->attack = getIntInput("Enter attack: ", 0, 2000);

        cout << "Enter monster's special attack chance (must be a double between 0 and 1): ";
        this->specialAttackChance = getDoubleInput("Enter special attack chance: ", 0.0, 1.0);

        cout << "Enter monster's special attack type: ";
        this->specialAttackType = getStringInput("Enter special attack type: ");

        cout << "Enter monster's appearance date and time:\n";
        this->appearanceTime = time(nullptr);

        cout << "Monster information has been successfully recorded.\n";
    }

    void printMonsterData() {
        cout << "----------------------\n";
        cout << "ID: " << this->id << "\n";
        cout << "Monster Name: " << this->name << "\n";
        cout << "Health: " << this->health << "\n";
        cout << "Attack damage: " << this->attack << "\n";
        cout << "Chance of special attack: " << this->specialAttackChance;
        cout << "Special Attack Type: " << this->specialAttackChance;
        cout << "Appearance Time: " << this->appearanceTime;
        cout << "\n\n";
    }

};

void insertMonster(vector<Monster>& monsterCollection, bool isDemoMode, bool isBenchmark);
void storeData(const string& filename,  vector<Monster>& monsterData, const string& DatabaseType);
void loadData(const string& source, vector<Monster>& storage, const string& DatabaseType);
void SelectAllMonsters(vector<Monster>& readVector);
void selectMonsterBy(vector<Monster>& localDatabase);
void searchByAppearanceTime(vector<Monster>& monsters, time_t startTime, time_t endTime);
void searchBySpecialAttackPercentage( vector<Monster>& database, double minSpecialAttackChance);
void searchBySpecialAttackType(vector<Monster>& database, const string& specialAttackType);
void searchByNameEnding(vector<Monster>& localDatabase, const string& fragment);
void updateMonster(vector<Monster>& localDatabase);
void deleteMonster(vector<Monster>& localDatabase);


