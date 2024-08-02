#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Contact.h"


using namespace std;

/**
 * Clears the terminal screen based on the operating system.
 * 
 * If the code is running on a Windows system, it will use the "cls" command.
 * If running on a Unix-like system (Linux, macOS, etc.), it will use the "clear" command.
 */

void clearScreen() {
#ifdef _WIN32
    system("cls"); // Use the "cls" command to clear the screen on Windows
#else
    system("clear"); // Use the "clear" command to clear the screen on Unix-like systems
#endif
}


/**
 * Pauses the program execution until the user presses Enter.
 * 
 * This function first clears the input buffer to discard any remaining characters,
 * then waits for the user to press the Enter key.
 */

void pause() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard any remaining characters in the input buffer
    cin.get();  // Wait for the user to press the Enter key
}


int main() {

    clearScreen();

    cout << endl;
    cout <<" * WELCOME TO THE CONTACT MANAGEMENT SYSTEM * " << endl;
    pause(); //Wait for user to press Enter 

    

    while(true) {
        clearScreen();

        Contact myContact;
        int choice;

        cout << endl;
        cout << "CONTACT MANAGEMENT SYSTEM" << endl;
        cout << "============================================" << endl;
        cout << "MAIN MENU" << endl;
        cout << "============================================" << endl;
        cout << "[1] Add new Contact" << endl;
        cout << "[2] List all Contacts" << endl;
        cout << "[3] Search for Contact" << endl;
        cout << "[4] Edit a Contact" << endl;
        cout << "[5] Delete a Contact" << endl;
        cout << "[0] Exit" << endl;
        cout << "============================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch(choice) {
            case 1:
            clearScreen();
            myContact.writeInFile();
            pause();
            break;

            case 2:
            clearScreen();
            myContact.readFromFile();
            pause();
            break;

            case 3:
            clearScreen();
            myContact.searchInFile();
            pause();
            break;

            case 4:
            clearScreen();
            myContact.editContact();
            pause();
            break;

            case 5:
            clearScreen();
            myContact.deleteFromFile();
            pause();
            break;

            case 0:
            clearScreen();
            cout << endl;
            cout << "Thank you for using CMS" << endl;
            return 0;
            break;

            default:
            cout << "Invalid choice. Please try again." << endl;
            pause();
            continue;

        }
        
            pause();
    }

    return 0;

}
