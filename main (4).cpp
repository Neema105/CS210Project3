/*
Neema Taghipour 06/29/2025 6:00 program
CS210 Richard Foster
Corner Grocer Data Analysis Program 
Displays counts of groceries and prints a histogram of all items
*/
 

#include <iostream>
#include "itemTracker.h"

using namespace std;

using namespace std;

// Shows menu to user
void ShowMenu() {
    cout << "\n=== Corner Grocer Menu ===" << endl;
    cout << "1. Look up an item" << endl;
    cout << "2. Print all item counts" << endl;
    cout << "3. Print item histogram" << endl;
    cout << "4. Exit program" << endl;
    cout << "Enter your choice (1-4): ";
}

// Main function
int main() {
    // Creates tracker object to handle data
    ItemTracker tracker;     
    int choice = 0;

    do {
        // Displays menu and asks for user input
        ShowMenu();
        cin >> choice;
         // If user enters invalid input
        if (cin.fail()) {  
            // Clears error
            cin.clear();      
            // Discards invalid input
            cin.ignore(10000, '\n'); 
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                string item;
                cout << "Enter the item name: ";
                cin >> item;
                int count = tracker.FindItemCount(item);
                cout << item << " was purchased " << count << " time(s)." << endl;
                break;
            }

            case 2:
                // Prints all items with counts
                tracker.PrintAllItems();  
                break;

            case 3:
                // Prints histogram of item frequencies
                tracker.PrintHistogram();
                break;

            case 4:
                cout << "Goodbye! Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    // Keeps showing menu until user chooses to exit
    } while (choice != 4);    

    return 0;
}