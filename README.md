# Contact Management System

A simple console-based Contact Management System (CMS) built in C++. This application allows users to create, view, search, edit, and delete contacts. The contacts are stored in a binary file for persistent storage.

## Features

- **Add New Contact**: Input and store new contact details.
- **List All Contacts**: Display all stored contacts.
- **Search for Contact**: Search contacts by phone number, first name, or last name.
- **Edit a Contact**: Modify the details of an existing contact.
- **Delete a Contact**: Remove a contact from the system.

## File Structure

- **Contact.h**: Contains the `Contact` class which defines the contact details and all the functions to manage contacts.
- **main.cpp**: The main file that runs the Contact Management System.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., GCC, Clang)
- Basic knowledge of C++ and file handling

### Installation

1. **Clone the repository**:
    ```bash
    git clone https://github.com/yourusername/contact-management-system.git
    ```
2. **Navigate to the project directory**:
    ```bash
    cd contact-management-system
    ```

3. **Compile the project**:
    ```bash
    g++ main.cpp -o CMS
    ```

4. **Run the executable**:
    ```bash
    ./CMS
    ```

## Usage

Upon running the application, a menu will be displayed with the following options:

1. **Add new Contact**: Enter details to add a new contact.
2. **List all Contacts**: View all the stored contacts.
3. **Search for Contact**: Find a contact by phone number, first name, or last name.
4. **Edit a Contact**: Modify an existing contact's details.
5. **Delete a Contact**: Remove a contact from the system.
0. **Exit**: Close the application.

### Code Overview

- **`Contact` Class**:
    - **Data Members**:
        - `first_Name`: First name of the contact.
        - `last_Name`: Last name of the contact.
        - `address`: Address of the contact.
        - `email`: Email address of the contact.
        - `phone_Num`: Phone number of the contact.
    - **Member Functions**:
        - `createContact()`: Inputs new contact details.
        - `showContact()`: Displays the contact details.
        - `writeString()`: Writes a string to the binary file.
        - `readString()`: Reads a string from the binary file.
        - `writeInFile()`: Saves a contact to the file.
        - `readFromFile()`: Reads and displays all contacts from the file.
        - `searchInFile()`: Searches for a contact by phone number, first name, or last name.
        - `deleteFromFile()`: Deletes a contact by phone number.
        - `editContact()`: Edits the details of an existing contact.

- **Helper Functions**:
    - `clearScreen()`: Clears the console screen.
    - `pause()`: Pauses the console until the user presses Enter.

## Known Issues

- Ensure that the binary file (`CMS.dat`) is not corrupted to prevent errors in reading/writing contacts.
- Case-sensitivity in search: Searching for names is case-sensitive.

## Contributing

If you would like to contribute to this project, please fork the repository and create a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- The design of this system is inspired by basic C++ console applications.
- Thanks to the C++ community for valuable resources and tutorials.
