#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm> // Needed for std::shuffle
#include <iomanip>   // Needed for formatting output
using namespace std;

// Function to generate a random password
string generatePassword(int length, bool includeLowercase, bool includeUppercase, bool includeDigits, bool includeSpecialChars)
{
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string specialChars = "!@#$%^&*()-_=+[]{};:,.<>?/";

    string characterPool = "";

    // Add selected character sets to the pool
    if (includeLowercase)
        characterPool += lowercase;
    if (includeUppercase)
        characterPool += uppercase;
    if (includeDigits)
        characterPool += digits;
    if (includeSpecialChars)
        characterPool += specialChars;

    // If no character sets are selected, return an empty string
    if (characterPool.empty())
        return "";

    // Random number generation setup
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, characterPool.size() - 1);

    string password;

    // Ensure the password contains at least one of each selected character type
    if (includeLowercase)
        password += lowercase[distribution(generator) % lowercase.size()];
    if (includeUppercase)
        password += uppercase[distribution(generator) % uppercase.size()];
    if (includeDigits)
        password += digits[distribution(generator) % digits.size()];
    if (includeSpecialChars)
        password += specialChars[distribution(generator) % specialChars.size()];

    // Fill the rest of the password with random characters from the pool
    for (int i = password.size(); i < length; ++i)
    {
        password += characterPool[distribution(generator)];
    }

    // Shuffle the password to ensure random placement of mandatory characters
    shuffle(password.begin(), password.end(), generator);

    return password;
}

// Function to save password data to a file
void savePassword(const string &platform, const string &username, const string &password)
{
    ofstream file("passwords.csv", ios::app); // Open file in append mode
    if (file.is_open())
    {
        file << platform << "," << username << "," << password << endl;
        file.close();
        cout << "Password saved successfully!" << endl;
    }
    else
    {
        cerr << "Error: Unable to open file for saving." << endl;
    }
}

// Function to retrieve and display saved passwords
void viewSavedPasswords()
{
    ifstream file("passwords.csv");
    if (file.is_open())
    {
        string line;
        cout << setw(40) << left << "Platform"
             << setw(40) << left << "Username"
             << setw(40) << left << "Password" << endl;
        cout << string(120, '-') << endl;

        while (getline(file, line))
        {
            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1 + 1);

            string platform = line.substr(0, pos1);
            string username = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string password = line.substr(pos2 + 1);

            cout << setw(40) << left << platform
                 << setw(40) << left << username
                 << setw(40) << left << password << endl;
        }
        file.close();
    }
    else
    {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}

int main()
{
    char choice;
    cout << "=======================================" << endl;
    cout << "== Welcome to M3D-BOUHADI GENERATOR! ==" << endl;
    cout << "=======================================" << endl;

    do
    {
        cout << "==     Password Generator Menu:      ==" << endl;
        cout << "==== 1. Generate a new password      ==" << endl;
        cout << "==== 2. View saved passwords         ==" << endl;
        cout << "==== 3. Exit                         ==" << endl;
        cout << "=======================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1')
        {
            int passwordLength;
            string platform, username;
            bool includeLowercase = false, includeUppercase = false, includeDigits = false, includeSpecialChars = false;

            // Prompt user to enter the desired password length
            do
            {
                cout << "Enter the desired password length (8 to 16): ";
                cin >> passwordLength;
                if (passwordLength < 8 || passwordLength > 16)
                {
                    cout << "Invalid length. Please enter a value between 8 and 16." << endl;
                }
            } while (passwordLength < 8 || passwordLength > 16);

            cout << "Include lowercase letters? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
                includeLowercase = true;

            cout << "Include uppercase letters? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
                includeUppercase = true;

            cout << "Include digits? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
                includeDigits = true;

            cout << "Include special characters? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
                includeSpecialChars = true;

            // Generate the password
            string password = generatePassword(passwordLength, includeLowercase, includeUppercase, includeDigits, includeSpecialChars);

            if (!password.empty())
            {
                cout << "Generated password: " << password << endl;

                // Ask for platform and username to save the password
                cout << "Enter the platform/website for this password: ";
                cin.ignore(); // Ignore newline character from previous input
                getline(cin, platform);
                cout << "Enter the username for this platform: ";
                getline(cin, username);

                // Save the password
                savePassword(platform, username, password);
            }
            else
            {
                cout << "No character types selected. Cannot generate a password." << endl;
            }
        }
        else if (choice == '2')
        {
            viewSavedPasswords();
        }
    } while (choice != '3');

    return 0;
}
