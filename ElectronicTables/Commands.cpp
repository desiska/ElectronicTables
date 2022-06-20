//
// Created by Laptop_HP on 7.6.2022 г..
//

#include "Commands.h"
#include<iostream>
#include<fstream>

//private method to copy 'other' object property
void Commands::copy(const Commands &other) {
    this->manager = other.manager;
}

//private method to delete the allocated memory
void Commands::clean() {
    this->manager.~FileManager();
}

//default constructor
Commands::Commands() {

}

//copy constructor
Commands::Commands(const Commands &other) {
    this->copy(other);
}

//redefining operator '='
//copy the 'other' object if it is not the same object
Commands &Commands::operator=(const Commands &other) {
    if(this != &other){
        this->clean();
        this->copy(other);
    }

    return *this;
}

//destructor
//invoke private method 'clean'
Commands::~Commands() {
    this->clean();
}

//infoke a read method from FileManager class to read a file and save datas in the application
void Commands::open(MyString fileName) {
    FileManager newManager = FileManager(fileName);
    this->manager = newManager;

    this->manager.read();
}

//invoke save method from FileManager class to save the datas with the updates in the open file
void Commands::save() {
    this->manager.save();
}

//invoke saveAs method from FileManager class to save the datas with the updates in the 'newFileName'
void Commands::saveAs(MyString newFileName) {
    this->manager.saveAs(newFileName);
}

//print on the console list of application function and information for them
void Commands::help() {
    std::cout <<"\n\t                           ------HELP------\n\n"
         << "********************************************************************************\n"
         << "********************************************************************************\n"
         << "***  Open <file>           opens <file>                                      ***\n"
         << "***  Close                 closes currently opened file                      ***\n"
         << "***  Save                  saves the currently open file                     ***\n"
         << "***  Save As               saves the currently open file in <file>           ***\n"
         << "***  Help                  prints this information                           ***\n"
         << "***  Edit                  edit a cell of the table                          ***\n"
         << "***  Print                 print the table                                   ***\n"
         << "***  Exit                  exits the program                                 ***\n"
         << "********************************************************************************\n"
         << "********************************************************************************\n";

}

//invoke method print from FileManager class to print all datas
void Commands::print() {
    this->manager.print();
}

//invoke method edit from FileManager class to update data
bool Commands::edit(unsigned int row, unsigned int col, MyString newData) {
    bool result = this->manager.edit(row, col, newData);
    if(!result){
        std::cout << "There is an error with the data you submitted!\n";
    }

    return result;
}

//method to start the application
void Commands::startProgram() {
    int choose = 8;
    bool canExit = true;
    MyString fileName;

    do {
        std::cout << "\n\t      ------WELCOME TO DATABASE MANAGEMENT SYSTEM------\n\n"
                  << "********************************************************************************\n"
                  << "********************************************************************************\n"
                  << "***  1- Open Database                                                        ***\n"
                  << "***  2- Edit Data                                                            ***\n"
                  << "***  3- Save Data                                                            ***\n"
                  << "***  4- SaveAs on Data                                                       ***\n"
                  << "***  5- Print Data                                                           ***\n"
                  << "***  6- Help                                                                 ***\n"
                  << "***  7- Close                                                                ***\n"
                  << "***  8- Exit                                                                 ***\n"
                  << "********************************************************************************\n"
                  << "********************************************************************************\n";

        std::cout << "  Enter your choice: \n";
        std::cin >> choose;

        if(choose == 1){
            if(fileName.isEmpty()) {
                std::cout << "Enter an URL of Table: ";
                std::cin >> fileName;
                this->open(fileName);
            }
            else{
                std::cout << "There is a open file! Please close first this file!\n";
            }
        }

        if (fileName.isEmpty()) {
            std::cout << "There is not a open file! Please first open file!\n";
        }
        else {
            switch (choose) {
                case 2:
                {
                    std::cout << "Enter a <row> <col> <new value>: ";
                    int row, col;
                    MyString input;
                    std::cin >> row >> col >> input;
                    canExit = !this->edit(row, col, input);
                }
                    break;

                case 3:
                    this->save();
                    canExit = true;
                    break;

                case 4:
                {
                    std::cout << "Enter a file URL: ";
                    MyString input;
                    std::cin >> input;
                    this->saveAs(input);
                    canExit = true;
                }
                    break;

                case 5:
                    this->print();
                    break;

                case 6:
                    this->help();
                    break;

                case 7:
                    this->clean();
                    break;

                case 8:
                    if(!canExit) {
                        std::cout << "You have an open file with unsaved changes, please select close or save first!\n";
                    }
                    break;
            }
        }
    } while (choose != 8 || !canExit);
}
