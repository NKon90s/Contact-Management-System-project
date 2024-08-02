#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

/**
 * Class representing a Contact with attributes like first name, last name, 
 * address, email, and phone number. Provides functionality to create, display, 
 * edit, delete, and search for contacts, as well as save them to and read them from a binary file.
 */


class Contact {


    private:

        string first_Name;
        string last_Name;
        string address;
        string email;
        long long phone_Num;

    public:

        // Default Constructor

        Contact() {

            /*empty constructor*/
        }


        //Public function to create a contact with user input
        void createContact();


        //Function to display contact information
        void showContact() const;


        /**
         * Static function to write a string to a binary file, prefixed by its length.
         * @param outFile Reference to the file stream to write to.
         * @param str The string to write.
         */

        static void writeString(fstream& outFile, const string& str); 


        /**
         * Static function to read a string from a binary file, based on its prefixed length.
         * @param inFile Reference to the file stream to read from.
         * @param str Reference to the string to store the read content.
         */

        static void readString(fstream& inFile, string& str);


        /**
         * Function to write the contact's data to a binary file. Allows the user 
         * to input multiple contacts in a loop.
         */

        void writeInFile(); 


        /**
         * Function to read and display all contacts from the binary file.
         */

        void readFromFile(); 
        /**
         * Function to search for a contact in the binary file by phone number,
         * first name, or last name. Displays the first matching contact.
         */

        void searchInFile();
  

        /**
         * Function to delete a contact from the binary file by phone number.
         * Copies all other contacts to a temporary file, then replaces the original file.
         */

        void deleteFromFile(); 
        /**
         * Function to edit a contact in the binary file by phone number.
         * Copies all contacts to a temporary file, replacing the details of the specified contact.
         * The original file is then replaced by the temporary file.
         */

        void editContact();
};



#endif /* CONTACT_H */
