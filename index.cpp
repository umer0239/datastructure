#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_FILES = 100; 
string files[MAX_FILES] = {
    "Mudaxs.txt", "Simeras.xls","Umers.pptx", "Samsons.txt",
    "Christina.txt","Ermiyas.xls" };
int fileCount = 6;

void displayFiles() {
       if (fileCount == 0) {
        cout << "No files to display.\n"; 
        return;
 }
     cout << "Files:\n";
   for (int i = 0; i < fileCount; ++i {
     cout << i+1 << ". " << files[i] << endl;
}
}
void searchFile() {
    string query;
    cout << "Enter file name to search: ";
    getline(cin, query);
    
    for (int i = 0; i <fileCount; ++i) {
        if (files[i] == query) {
            cout << "File found: " << files[i] << endl;
            return;
        }
    }
    cout << "File not found: " << query << endl;
}

void sortFiles() {
    int sortChoice;
    cout << "Choose sorting order:\n";
    cout << "1. Ascending Order:\n";
    cout << "2. Descending Order:\n";
    cout << "Enter your choice: ";
    cin >> sortChoice;

    if (sortChoice == 1) {
        sort(files, files + fileCount); 
        cout << "Files sorted successfully in ascending order.\n";
    } else if (sortChoice == 2) {
        sort(files, files + fileCount, greater<string>());
        cout << "Files sorted successfully in descending order.\n";
    } else {
        cout << "Invalid choice. Sorting operation canceled.\n";
        return; // Exit the function if invalid choice
    }

    displayFiles();
}

int main() {
    int choice;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Display Files\n";
        cout << "2. Search for a File\n";
        cout << "3. Sort Files\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                displayFiles();
                break;
            case 2:
                searchFile();
                break;
            case 3:
                sortFiles();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
