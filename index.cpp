#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
#include <fstream>
#include <limits> 

using namespace std;

const int MAX_FILES = 100;
string files[MAX_FILES] = {
    "Mudaxs.txt", "Simeras.xls", "Umers.pptx", "Samsons.txt",
    "Christina.txt", "Ermiyas.xls"
};
int fileCount = 6;


int getValidatedInput(int min, int max) {
    int choice;
    while (true) {
        cout << "Enter your choice (" << min << "-" << max << "): ";
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
        } else {
            cin.ignore();
            return choice;
        }
    }
}

string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void displayWelcome() {
    cout << "=================================\n";
    cout << "  FILE MANAGEMENT SYSTEM v1.1\n"; 
    cout << "=================================\n";
    cout << "Welcome! Manage your files easily.\n\n";
}

// NEW: Case-insensitive comparison for sorting
bool caseInsensitiveCompare(const string& a, const string& b) {
    return toLower(a) < toLower(b);
}

void displayFiles() {
    if (fileCount == 0) {
        cout << "No files to display.\n";
        return;
    }
    cout << "Files (" << fileCount << " total):\n"; 
    for (int i = 0; i < fileCount; ++i) {
        cout << i + 1 << ". " << files[i] << endl;
    }
}

void searchFile() {
    if (fileCount == 0) { 
        cout << "No files to search.\n";
        return;
    }

    string query;
    cout << "Enter file name to search: ";
    getline(cin, query);

    bool found = false;
    for (int i = 0; i < fileCount; ++i) {
        if (toLower(files[i]).find(toLower(query)) != string::npos) { 
            cout << "Found: " << files[i] << endl;
            found = true;
        }
    }
    if (!found) cout << "No matches found.\n";
}

void sortFiles() {
    if (fileCount == 0) { 
        cout << "No files to sort.\n";
        return;
    }

    cout << "Choose sorting order:\n";
    cout << "1. A-Z\n"; 
    cout << "2. Z-A\n";
    int sortChoice = getValidatedInput(1, 2); 

    if (sortChoice == 1) {
        sort(files, files + fileCount, caseInsensitiveCompare); 
    } else {
        sort(files, files + fileCount, [](const string& a, const string& b) {
            return toLower(a) > toLower(b);
        });
    }
    displayFiles();
}
int main() {
    displayWelcome();
    int choice;

    do {
        cout << "\nMain Menu:\n"; 
        cout << "1. Display Files\n";
        cout << "2. Search for a File\n";
        cout << "3. Sort Files\n";
        cout << "4. Add a New File\n";
        cout << "5. Delete a File\n";
        cout << "6. Show File Type Summary\n";
        cout << "7. Exit\n";

        choice = getValidatedInput(1, 7); 

        switch (choice) {
            case 1: displayFiles(); break;
            case 2: searchFile(); break;
            case 3: sortFiles(); break;
            case 4: addFile(); break;
            case 5: deleteFile(); break;
            case 6: countFileTypes(); break;
            case 7: cout << "Exiting program.\n"; break;
        }
    } while (choice != 7);

    return 0;
}
