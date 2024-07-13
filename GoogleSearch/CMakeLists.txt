cmake_minimum_required(VERSION 3.28)
project(Assignment_03_Code)

set(CMAKE_CXX_STANDARD 14)

# TicTacToe executable
add_executable(TicTacToe Assignment-03_PA_TicTacToe.cpp)

# Credit Card Number Validation executable
add_executable(CCNumberValidation Assignment-03_PB_CCNumberValidation.cpp)

# Dictionary executable
add_executable(Dictionary
        Assignment-03_PC_Dictionary.cpp
        Assignment-03_PC_Dictionary_Data_Loader.cpp
        Assignment-03_PC_Dictionary_Data_Loader.h
        Assignment-03_PC_Dictionary_User_Interface.h
        Assignment-03_PC_Dictionary_User_Interface.cpp
        Assignment-03_PC_Dictionary_Print_Output.h
        Assignment-03_PC_Dictionary_Print_Output.cpp
        Assignment-03_PC_Dictionary_Interaction.h
        Assignment-03_PC_Dictionary_Interaction.cpp
)