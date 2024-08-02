#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Contact.h"
 
using namespace std;
 
 void Contact::createContact() {
            cout << "Enter First Name: ";
            getline(cin, first_Name);

            cout << "Enter Last Name: ";
            getline(cin, last_Name);

            cout << "Enter Address: ";
            getline(cin, address);

            cout << "Enter Email: ";
            getline(cin, email);

            cout << "Enter Phone Number: ";
            while(!(cin >> phone_Num) || phone_Num < 0) {
                cout << "Invalid phone number. Please enter a positive number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');  //This line is to clear the buffer. Discards all of the input stream
            }

                cin.ignore(numeric_limits<streamsize>::max(),'\n');  
        }



        
        void Contact::showContact() const {

            cout << "Name: "<< first_Name << " " << last_Name << endl;
            cout << "Address: " << address << endl;
            cout << "Phone Number: " << phone_Num << endl;
            cout << "Email: " << email << endl;

        }  


        void Contact::writeString(fstream& outFile, const string& str) {
            size_t length = str.size();
            outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));

            if(!outFile) {
                cerr << "Error writing string lenght to file." << endl;
                return;
            }
            outFile.write(str.c_str(), length);
            if(!outFile) {
                cerr << "Error writing string content to file." << endl;
            }
        }



        void Contact::readString(fstream& inFile, string& str) {
            size_t length;
            inFile.read(reinterpret_cast<char*>(&length), sizeof(length));

            if(!inFile) {
                cerr << "Error reading string lenght from file." << endl;
                return;
            }
            
            if (length > inFile.rdbuf()->in_avail()) {
                cerr << "Invalid length detected, possibly corrupted file." << endl;
                str.clear();
                return;
            }

            str.resize(length);
            inFile.read(&str[0], length);

            if (!inFile) {
                cerr << "Error reading string content from file." << endl;
            }
        }



        void Contact::writeInFile() {
            char ch;
            fstream f1;
            f1.open("CMS.dat", ios::out | ios::binary | ios::app);

            if(!f1.is_open()) {
                cerr << "Error in reaching data!";
                return;
            }

                do {
                    createContact();
                    writeString(f1, first_Name);
                    writeString(f1, last_Name);
                    writeString(f1, address);
                    writeString(f1, email);
                    f1.write(reinterpret_cast<char*>(&phone_Num), sizeof(phone_Num));

                    if (!f1) {
                        cerr << "Error writing to file!" << endl;
                        f1.close();
                        return;
                    }

                    cout << "Contact Added";

                    bool validInput = false;
                    while (!validInput) {
                        cout << "Do you want to add another contact? (Y/N): ";
                        cin >> ch;
                        ch = towlower(ch);

                        // Check if the input is valid
                        if (ch == 'y' || ch == 'n') {
                            validInput = true; // Valid input, break out of the loop
                        } else {
                            cout << "Invalid input. Please enter Y or N." << endl;
                            cin.clear(); // Clear the error flag on cin
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                        }
                    }
                
                    cin.ignore(numeric_limits<streamsize>::max(),'\n'); //This line is to clear the buffer. Discards all of the input stream

                } while(ch == 'y' || ch == 'Y');

                
                f1.close();

        }


        void Contact::readFromFile() {
            fstream f2;
            f2.open("CMS.dat", ios::in | ios::binary);

            if(!f2.is_open()) {
                cerr << "Error in reaching data!";
                return;
            }
            
                cout << endl;
                cout << "==============================" << endl;
                cout << "CONTACT LIST";
                cout << endl;
                cout << "==============================" << endl;

                while(f2.peek() != EOF) {
                    readString(f2, first_Name);
                    readString(f2, last_Name);
                    readString(f2, address);
                    readString(f2, email);
                    f2.read(reinterpret_cast<char*>(&phone_Num), sizeof(phone_Num));
                        showContact();
                        cout << endl;
                        cout << "==============================" << endl;
                    
                }

                f2.close();

        }

      

        void Contact::searchInFile() {
            fstream f3;
            f3.open("CMS.dat" , ios::in | ios::binary);

            if(!f3.is_open()) {
                cerr << "Error in reaching data!";
                return;
            }

                int choice;
                cout << "Search by 1.Phone Number 2.First Name 3.Last Name" << endl;
                cout << "Enter choice: ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');  //This line is to clear the buffer. Discards all of the input stream

                bool found = false;

                switch(choice) {
                    case 1: {
                        long long phone;
                        cout << "Enter phone number: " << endl;
                        cin >> phone;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');  //This line is to clear the buffer. Discards all of the input stream

                        while(f3.peek() != EOF) {
                            readString(f3, first_Name);
                            readString(f3, last_Name);
                            readString(f3, address);
                            readString(f3, email);
                            f3.read(reinterpret_cast<char*>(&phone_Num), sizeof(phone_Num));
                            
                        if(phone == phone_Num) {
                            showContact();
                            found = true;
                            break;
                        }
                    
                    }

                    break;

                }

                    case 2: {
                        string name;
                        cout << "Enter First Name: ";
                        getline(cin, name);

                        while (f3.peek() != EOF) {
                            readString(f3, first_Name);
                            readString(f3, last_Name);
                            readString(f3, address);
                            readString(f3, email);
                            f3.read(reinterpret_cast<char*>(&phone_Num), sizeof(phone_Num));

                            if(name == first_Name) {
                                showContact();
                                found = true;
                                break;
                            }
                        }

                        break;
                    }

                    case 3: {
                        string name;
                        cout << "Enter Last Name: ";
                        getline(cin, name);

                        while (f3.peek() != EOF) {
                            readString(f3, first_Name);
                            readString(f3, last_Name);
                            readString(f3, address);
                            readString(f3, email);
                            f3.read(reinterpret_cast<char*>(&phone_Num), sizeof(phone_Num));

                            if(name == last_Name) {
                                showContact();
                                found = true;
                                break;
                            }
                        }

                        break;
                    }

                    default:
                        cout <<"Invalid choice" << endl;
                        break;
                    }

                    if(!found) {
                    cout << "No record found!" << endl;
                    }

                f3.close();
                
        }
  


        void Contact::deleteFromFile() {
            long long phone;
            fstream inputFile;
            fstream tempFile;

            inputFile.open("CMS.dat" , ios::in | ios::binary);
            tempFile.open("temp.dat" , ios::out | ios::binary);

             if(!inputFile.is_open() || !tempFile.is_open()) {
                cerr << "Error in reaching data!";
                return;
            }
            
            bool found = false;
            
            cout << "Enter phone number to delete: ";
            cin >> phone;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');  //This line is to clear the buffer. Discards all of the input stream

            while(inputFile.peek() != EOF) {
                readString(inputFile, first_Name);
                readString(inputFile, last_Name);
                readString(inputFile, address);
                readString(inputFile, email);
                inputFile.read(reinterpret_cast<char*>(&phone_Num), sizeof(phone_Num));

                    if(phone != phone_Num) {   
                        writeString(tempFile, first_Name);
                        writeString(tempFile, last_Name);
                        writeString(tempFile, address);
                        writeString(tempFile, email);
                        tempFile.write(reinterpret_cast<char*>(&phone_Num), sizeof(phone_Num));
                        found = true;
                    }
                    
            }
        

            inputFile.close();
            tempFile.close();

            if(found) {
                remove("CMS.dat");
                rename("temp.dat", "CMS.dat");
                cout << "Contact Deleted successfully." << endl;
            }
            else {
                remove("temp.dat");
                cout << "No record found." << endl;
            }


        }




        void Contact::editContact() {
            long long phone;
            fstream inputFile;
            fstream tempFile;

            inputFile.open("CMS.dat" , ios::in | ios::binary);
            tempFile.open("temp.dat" , ios::out | ios::binary);

             if(!inputFile.is_open() || !tempFile.is_open()) {
                cerr << "Error in reaching data!";
                return;
            }

                bool found = false;

                cout << "Enter phone number of contact to edit: " << endl;
                cin >> phone;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');  //This line is to clear the buffer. Discards all of the input stream

                while (inputFile.peek() != EOF) {
                    readString(inputFile, first_Name);
                    readString(inputFile, last_Name);
                    readString(inputFile, address);
                    readString(inputFile, email);
                    inputFile.read(reinterpret_cast<char*>(&phone_Num), sizeof(phone_Num));

                if (phone == phone_Num) {
                    cout << "Editing contact details for phone number: " << phone_Num << endl;
                    cout << "Enter new details:" << endl;
                    createContact();  // Reuse the createContact method to input new details
                    found = true;
                }

                writeString(tempFile, first_Name);
                writeString(tempFile, last_Name);
                writeString(tempFile, address);
                writeString(tempFile, email);
                tempFile.write(reinterpret_cast<char*>(&phone_Num), sizeof(phone_Num));

                }

                inputFile.close();
                tempFile.close();

                if(found) {
                    remove("CMS.dat");
                    rename("temp.dat", "CMS.dat");
                    cout << "Contact Edited successfully." << endl;
                }   
                else {
                    remove("temp.dat");
                    cout << "No record found." << endl;
                }
        }


