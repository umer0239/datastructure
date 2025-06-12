# Data structure and Algorithm Group Assignment in Arba Minch University.
|Name:         | ID No     |Github Username   |                     
|-------------------------|-----------|-----|
|1.Muhidin Mitiku         | NSR/723/16 |Mudax36
|2.Umer     Hussen        | NSR/1125/16 |umer0239
|3.Christina Bereket      | NSR/226/16 |ChristinaBereket
|4.Samson    Anteneh      | NSR/842/16 |Samford17
|5.Ermiyas   Girma        | NSR/311/16 | Ermi121
|6.Simera     Mamo        | NSR/893/16 |Simera661
# File Management System

This C++ console application allows users to manage a list of files. Users can display the list of files, search for specific files, and sort the files in either ascending or descending order.

## Features
 
  **Display Files**
  
Shows the current list of file names with numbering.
If no files exist, it displays a message accordingly.

**Search for a File**

Allows users to search for a file name.
The search is case-insensitive for better user experience.
Displays whether the file was found.

  **Sort Files**
  
Offers two sorting options:
Ascending order (A-Z)
Descending order (Z-A)
Automatically displays the sorted list.

**Add a New File**

Users can add a new file name to the list.
The system prevents duplicate entries (case-insensitive check).
Ensures that the total number of files does not exceed a predefined maximum (MAX_FILES = 100).

**Delete a File**

Users can remove a file by entering its name.
Deletion is case-insensitive.
Automatically shifts remaining files to keep the list compact.

**File Type Summary**
Analyzes the file list and counts how many files of each extension exist.
For example: .txt, .xls, .pptx
Output is presented as a summary report.

**Exit**

Terminates the program gracefully


## Usage

1. Clone the repository.
2. Compile the code using a C++ compiler.
3. Run the executable and follow the on-screen menu to manage files.

## Example Files

- Mudaxs.txt
- Simeras.xls
- Umers.pptx
- Samson.txt
- Christina.txt
- Ermiyas.xls
