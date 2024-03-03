#include <iostream>
#include "struct.h"
#include <string>
#include <ctime>
#include <fstream>

using namespace std;


void demonstrationMode()
{
//    bool manage = true;
//    date zeroValueDate(0, 0, 0, 0, 0, 0);
//    vector<Product> bufferDatabase, demonstrationDatabase; // Масив для збереження тимчасових елементів
//    cout << "\n=== START DEMONSTRATION MODE ===\n";
//    this_thread::sleep_for(chrono::seconds(1));
//
//    cout << "\n\n--- ADD 5 ELEMENTS TO DATABASE ---\n\n";
//    this_thread::sleep_for(chrono::seconds(1));
//    for (int i = 0; i < 5; i++)
//    {
//        addElement(bufferDatabase, true, false);
//    }
//    cout << "\n=== Elements added succesfully! ===\n";
//    this_thread::sleep_for(chrono::seconds(1));
//
//    cout << "\n\n--- SAVE THE DATABASE ---\n\n";
//    this_thread::sleep_for(chrono::seconds(1));
//    demonstrationDatabase = bufferDatabase;
//    cout << "\n=== Database saved successfully! ===\n";
//    this_thread::sleep_for(chrono::seconds(1));
//
//    cout << "\n\n--- RECORD THE DATABASE ---\n\n";
//    this_thread::sleep_for(chrono::seconds(1));
//    bufferDatabase = demonstrationDatabase;
//    cout << "\n=== Database was recorded successfully! ===\n";
//    this_thread::sleep_for(chrono::seconds(1));
//
//    cout << "\n\n--- PRINT THE DATABASE ---\n\n";
//    this_thread::sleep_for(chrono::seconds(1));
//    readAllDatabase(bufferDatabase);
//    cout << "\n=== Database was read successfully! ===\n";
//    this_thread::sleep_for(chrono::seconds(1));
//
//    cout << "\n\n--- SEARCH THE DATABASE FOR ALL ELEMENTS STARTING WITH THE LETTER 'A' AND HAVING A NUMBER FROM 0 TO 100 -- - \n\n";
//    this_thread::sleep_for(chrono::seconds(1));
//    vector<Monster> name = search(bufferDatabase, true, "a", true, 0, 100, false, zeroValueDate);
//
//    if (name.empty() != 0)
//        cout << "\n### Elements not founded! ###\n";
//    else
//    {
//        cout << "\nAll founded elements: \n";
//        this_thread::sleep_for(chrono::seconds(1));
//        for (auto& p : name)
//            p.printInfo();
//    }
//    this_thread::sleep_for(chrono::seconds(1));
//
//    cout << "\n\n--- CHANGE ELEMENT WITH 1 ID IN DATABASE. CHANGE THE ELEMENT NAME TO 'MILK' --- \n\n";
//    this_thread::sleep_for(chrono::seconds(1));
//    bufferDatabase[0].name = "Milk";
//    cout << "\n=== Name changed succesfully! === \n";
//    this_thread::sleep_for(chrono::seconds(1));
//
//    cout << "\n\n--- DELETE ELEMENT WITH ID 5 IN THE DATABASE ---\n\n";
//    this_thread::sleep_for(chrono::seconds(1));
//    bufferDatabase.erase(bufferDatabase.begin() + 4);
//    cout << "\n=== Element with ID 5 was deleted! ===\n";
//
//    cout << "\n\n--- SAVE THE DATABASE ---\n\n";
//    this_thread::sleep_for(chrono::seconds(1));
//    demonstrationDatabase = bufferDatabase;
//    cout << "\n=== Database was saved successfully! ===\n";
//    this_thread::sleep_for(chrono::seconds(1));
//
//    cout << "\n\n--- PRINT THE DATABASE ---\n\n";
//    this_thread::sleep_for(chrono::seconds(1));
//    readAllDatabase(bufferDatabase);
//    this_thread::sleep_for(chrono::seconds(1));
//    cout << "\n=== Database was read successfully! ===\n";
//    this_thread::sleep_for(chrono::seconds(1));
//
//    cout << "\n\n--- EXIT ---\n\n";
//    this_thread::sleep_for(chrono::seconds(1));
//    cout << "\n=== DATABASE CLOSE ===";
}