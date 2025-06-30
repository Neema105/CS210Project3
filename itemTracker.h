#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class ItemTracker {
private:
     // Maps to store item names and the amount of times purchased
    map<string, int> itemList;              
    string inputFileName = "CS210_Project_Three_Input_File.txt";
    string backupFileName = "frequency.dat";

public:
    // Constructor that reads the input file
    ItemTracker();          
    // Gets the count of a specific item
    int FindItemCount(string item);   
     // Prints all items and their counts
    void PrintAllItems();    
    // Prints a histogram of items using asterisks
    void PrintHistogram();  
    // Saves the data to frequency.dat
    void WriteToBackupFile();   
};

#endif