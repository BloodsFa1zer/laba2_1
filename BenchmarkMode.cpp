#include <iostream>
#include "struct.h"
#include <string>
#include <fstream>

using namespace std;
using namespace chrono;


time_t generateRandomTime() {
    // Get the current system time
    auto currentTime = system_clock::now();
    // Convert current time to time_t
    time_t currentTimestamp = system_clock::to_time_t(currentTime);
    return currentTimestamp;
}

string generateRandomString(int length) {
    const string characters = "abcdefghijklmnopqrstuvwxyz";
    string result;
    for (int i = 0; i < length; ++i) {
        result += characters[rand() % characters.size()];
    }
    return result;
}

double calculateBufferSize(const vector<Monster>& buffer, int num) {
    // Calculate the size of a single element in bytes
    size_t elementSize = sizeof(buffer[0]);

    // Calculate the total size of the buffer vector in bytes
    size_t totalSizeBytes = elementSize * num;

    // Convert the total size to megabytes
    double totalSizeMB = static_cast<double>(totalSizeBytes) / (1024.0 * 1024.0);

    return totalSizeMB;
}



void benchmarkMode() {
    cout << "\nYou are now in the benchmark dbMode, time of each operation will be written afterwards\n";

    string txt = "Benchmark.txt", bin = "Benchmark.bin";
    fstream benchmarkTxt(txt, ios::app), benchmarkBin(bin, ios::app | ios::binary);
    vector<Monster> benchmarkVector;

    int num = getIntInput("Enter a number of element for database(from 1 to 1000): ", 1, 1000);


    for (int dbMode = 2; dbMode >= 0; dbMode--) {
        vector<Monster> buffer;
        buffer.reserve(num);
        string file = txt;
        if (dbMode == 2) {
            cout << "\n    BENCHMARK TXT DATABASE     \n";
        } else if (dbMode == 1) {
            cout << "\n\n    START BENCHMARK BIN DATABASE    \n";
            file = bin;
        } else {
            cout << "\n\n    START BENCHMARK LOCAL DATABASE    \n";
            buffer.clear();
        }



        auto startTime = high_resolution_clock::now();
        auto startTimeInsert = high_resolution_clock::now();
        for (int i = 0; i < num; i++) {
            insertMonster(buffer, false, true);
        }
        auto endTimeInsert = high_resolution_clock::now();



        auto startTimeLoad = high_resolution_clock::now();
        if (dbMode != 0) {
            loadData(file, buffer, dbMode == 2 ? txtDatabase : binDatabase);
        }
        else benchmarkVector = buffer;
        auto endTimeLoad = high_resolution_clock::now();



        auto startTimeStoreData = high_resolution_clock::now();
        if (dbMode != 0) {
            storeData(file, buffer, dbMode == 2 ? txtDatabase : binDatabase);
        }
        else buffer = benchmarkVector;
        auto endTimeStoreData = high_resolution_clock::now();



        auto startTimeSelectByAll = high_resolution_clock::now();

        auto startTimeSearchByNameEnding = high_resolution_clock::now();
        searchByNameEnding(buffer, generateRandomString(rand() % 10 + 1));
        auto endTimeSearchByNameEnding = high_resolution_clock::now();

        auto startTimeSearchBySpecialAttackType = high_resolution_clock::now();
        string specialAttackTypes[4] = {"Fire", "Ice", "Fire", "Electric"};
        int randomSearch = rand() % 3 + 1;
        searchBySpecialAttackType(buffer, specialAttackTypes[randomSearch]);
        auto endTimeSearchBySpecialAttackType = high_resolution_clock::now();

        auto startTimeSearchBySpecialAttackPercentage = high_resolution_clock::now();
        double minSpecialAttackChance = static_cast<double>(rand()) / RAND_MAX;
        searchBySpecialAttackPercentage(buffer, minSpecialAttackChance);
        auto endTimeSearchBySpecialAttackPercentage = high_resolution_clock::now();

        auto startTimeSearchByAppearanceTime = high_resolution_clock::now();
        time_t startT = generateRandomTime();
        time_t endT = startT + 3600;
        searchByAppearanceTime(buffer, startT, endT);
        auto endTimeSearchByAppearanceTime = high_resolution_clock::now();

        auto endTimeSelectByAll = high_resolution_clock::now();
        auto endTime = high_resolution_clock::now();



        auto durationTotal = duration_cast<milliseconds>(endTime - startTime);
        auto durationInsert = duration_cast<milliseconds>(endTimeInsert - startTimeInsert);
        auto durationRecord = duration_cast<milliseconds>(endTimeLoad - startTimeLoad);
        auto durationRestore = duration_cast<milliseconds>(endTimeStoreData - startTimeStoreData);
        auto durationSearchByNameEnding = duration_cast<milliseconds>(endTimeSearchByNameEnding - startTimeSearchByNameEnding);
        auto durationSearchBySpecialAttackType = duration_cast<milliseconds>(endTimeSearchBySpecialAttackType - startTimeSearchBySpecialAttackType);
        auto durationSearchBySpecialAttackPercentage = duration_cast<milliseconds>(endTimeSearchBySpecialAttackPercentage - startTimeSearchBySpecialAttackPercentage);
        auto durationSearchByAppearanceTime = duration_cast<milliseconds>(endTimeSearchByAppearanceTime - startTimeSearchByAppearanceTime);
        auto durationSelectByAll = duration_cast<milliseconds>(endTimeSelectByAll - startTimeSelectByAll);

        cout << "\n---------------------------\n";
        cout << "\nTime insert: " << durationInsert.count() << " milliseconds\n" <<
             "\nRecording time: " << durationRecord.count() << " milliseconds\n" <<
             "\nRestore time: " << durationRestore.count() << " milliseconds\n" <<
             "\nSelect time by monster name: " << durationSearchByNameEnding.count() << " milliseconds\n" <<
             "\nSelect time by special attack type: " << durationSearchBySpecialAttackType.count() << " milliseconds\n" <<
             "\nSelect time by special attack percentage: " << durationSearchBySpecialAttackPercentage.count() << " milliseconds\n" <<
             "\nSelect time by monster appearance time: " << durationSearchByAppearanceTime.count() << " milliseconds\n" <<
             "\nTotal select by criteria time: " << durationSelectByAll.count() << " milliseconds\n" <<
             "\nTotal db time: " << durationTotal.count() / 1000.0 << "seconds\n";

        if (dbMode == 0) {
            cout << "\nSize: " << calculateBufferSize(buffer, num) << " Mb \n";
        }
        cout << "\n---------------------------\n";

    }
    benchmarkBin.close();
    benchmarkTxt.close();


    cout << "\n\n    BENCHMARK IS ENDED UP WITH THE ABOVE-MENTIONED RESULTS    \n";

}

