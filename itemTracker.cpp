#include "itemTracker.h"

ItemTracker::ItemTracker() {
    // Opens the input file
    ifstream inputFile(inputFileName);      

    if (!inputFile.is_open()) {
        cout << "Error: Could not open input file.";
        return;
    }

    string item;
    // Reads each item from the file
    while (inputFile >> item) { 
        // Increase count in the map
        itemList[item]++;  
    }

    // Closes the input file
    inputFile.close();  
    // Saves to backup file
    WriteToBackupFile();
}

int ItemTracker::FindItemCount(string item) {
    if (itemList.find(item) != itemList.end()) {
        return itemList[item];
    }
    // Returns 0 if item is not found
    return 0;                                
}

void ItemTracker::PrintAllItems() {
    for (auto pair : itemList) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void ItemTracker::PrintHistogram() {
    for (auto pair : itemList) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; i++) {
            // Prints one * per item count
            cout << "*";                     
        }
        cout << endl;
    }
}

void ItemTracker::WriteToBackupFile() {
    // Opens file to write backup data
    ofstream outFile(backupFileName);
    if (outFile.is_open()) {
        for (auto pair : itemList) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }
}