Dictionary Program
Overview
This C++ implementation of a dictionary program is an evolution from a previous Java version, focusing on improved data handling, modular code structure, and enhanced user interaction. The program reads dictionary data from a file, processes it, and allows users to search for definitions with various options.
Features

Efficient data handling using vectors and C++ structs
Modular code structure with separate Data Loader and User Interface components
Robust file path handling with user input for incorrect paths
Case-insensitive searching
Distinct definition filtering
Reverse search capability
Improved whitespace handling in user input

Structure
The program is divided into several key components:

Assignment-03_PC_Dictionary.cpp: Main entry point
Assignment-03_PC_Dictionary_Data_Loader.h/cpp: Handles file operations and data parsing
Assignment-03_PC_Dictionary_User_Interface.h/cpp: Manages user interactions and search functionalities

Key Functionalities

File reading and data parsing
User input processing with enhanced whitespace handling
Distinct definition filtering
Reverse search option
Case-insensitive searching

Future Improvements

Optimize sorting algorithm (currently uses bubble sort)
Enhance performance of distinct definition functionality

How to Use

Run the program
If prompted, provide the correct file path for the dictionary data file
Follow on-screen prompts to search for definitions
Use special commands for distinct and reverse searches

Notes

The program initially looks for the data file at C:\Users\MickeyMouse\AbsolutePath\DB\Data.CS.SFSU.txt
If not found, it will prompt for the correct file path
Whitespace-only inputs are properly handled to prevent crashes

Author
Anshaj Vats
Course Information

Course: CSC340.01
Assignment: Assignment-03
Due Date: 07-05-2024 at 11:55 PM

For more detailed information about the implementation and specific functionalities, please refer to the source code and comments within.
