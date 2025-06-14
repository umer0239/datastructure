#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>

using namespace std;

const int MAX_FILES = 100;
string files[MAX_FILES] = {
    "Mudaxs.txt", "Simeras.xls", "Umers.pptx", "Samsons.txt",
    "Christina.txt", "Ermiyas.xls"
};
int fileCount = 6;

string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void displayFiles() {
    if (fileCount == 0) {
        cout << "No files to display.\n";
        return;
    }
    cout << "Files:\n";
    for (int i = 0; i < fileCount; ++i) {
        cout << i + 1 << ". " << files[i] << endl;
    }
}

void searchFile() {
    string query;
    cout << "Enter file name to search: ";
    getline(cin, query);

    bool found = false;
    for (int i = 0; i < fileCount; ++i) {
        if (toLower(files[i]) == toLower(query)) {
            cout << "File found: " << files[i] << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "File not found: " << query << endl;
}

void sortFiles() {
    int sortChoice;
    cout << "Choose sorting order:\n";
    cout << "1. Ascending Order\n";
    cout << "2. Descending Order\n";
    cout << "Enter your choice: ";
    cin >> sortChoice;
    cin.ignore();

    if (sortChoice == 1) {
        sort(files, files + fileCount);
        cout << "Files sorted in ascending order.\n";
    } else if (sortChoice == 2) {
        sort(files, files + fileCount, greater<string>());
        cout << "Files sorted in descending order.\n";
    } else {
        cout << "Invalid choice. Sorting cancelled.\n";
        return;
    }

    displayFiles();
}

void addFile() {
    if (fileCount >= MAX_FILES) {
        cout << "Maximum file limit reached. Cannot add more files.\n";
        return;
    }

    string newFile;
    cout << "Enter new file name: ";
    getline(cin, newFile);

    for (int i = 0; i < fileCount; ++i) {
        if (toLower(files[i]) == toLower(newFile)) {
            cout << "File already exists. Cannot add duplicate.\n";
            return;
        }
    }

    files[fileCount++] = newFile;
    cout << "File added successfully.\n";
}
void deleteFile() {
    // Show available files first
    if (fileCount == 0) {
        cout << " Your folder is empty - nothing to delete!\n";
        return;
    }
    cout << "\n Files you can delete:\n";
    for (int i = 0; i < fileCount; i++) {
        cout << "  " << (i+1) << ") " << files[i] << "\n";
    }
    cout << "\n Which file should I remove? (1-" << fileCount << "): ";
    int choice;
    cin >> choice;
    cin.ignore(); // Clear the input buffer

    // Validate choice
    if (choice < 1 || choice > fileCount) {
        cout << " Please enter a number between 1 and " << fileCount << ".\n";
        return;
    }
 // Confirm deletion
    cout << "Are you sure you want to delete '" << files[choice-1] << "'? (y/n): ";
    char confirm;
    cin >> confirm;
    cin.ignore();

    if (tolower(confirm) == 'y') {
        // Shift files to fill the gap
        for (int i = choice-1; i < fileCount-1; i++) {
            files[i] = files[i+1];
        }
        fileCount--;
        cout << "✔ Successfully deleted!\n";
    } else {
        cout << "Phew! File kept safe.\n";
    }
}
void countFileTypes() {
    map<string, int> typeCount;

    for (int i = 0; i < fileCount; ++i) {
        size_t dotPos = files[i].rfind('.');
        if (dotPos != string::npos) {
            string ext = toLower(files[i].substr(dotPos));
            typeCount[ext]++;
        }
    }

    cout << "File type summary:\n";
    for (const auto& entry : typeCount) {
        cout << entry.first << ": " << entry.second << " file(s)\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Display Files\n";
        cout << "2. Search for a File\n";
        cout << "3. Sort Files\n";
        cout << "4. Add a New File\n";
        cout << "5. Delete a File\n";
        cout << "6. Show File Type Summary\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: displayFiles(); break;
            case 2: searchFile(); break;
            case 3: sortFiles(); break;
            case 4: addFile(); break;
            case 5: deleteFile(); break;
            case 6: countFileTypes(); break;
            case 7: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
