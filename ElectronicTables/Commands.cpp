//
// Created by Laptop_HP on 7.6.2022 г..
//

#include "Commands.h"
#include<iostream>
#include<fstream>


void Commands::copy(const Commands &other) {
    this->manager = other.manager;
}

void Commands::clean() {
    delete &this->manager;
}

Commands::Commands() {

}

Commands::Commands(const Commands &other) {
    this->copy(other);
}

Commands &Commands::operator=(const Commands &other) {
    if(this != &other){
        this->clean();
        this->copy(other);
    }

    return *this;
}

Commands::~Commands() {
    this->clean();
}

void Commands::open(MyString fileName) {
    this->manager = FileManager(fileName);

    std::ofstream out;
    out.open(fileName.toString());

    if(!out){
        std::cout << "There is a mistake with URL of table!\n";
    }
    out.close();
}

void Commands::close() {
    if(this->manager.getFileName().toString() != nullptr){
        delete &manager;
    }
}

void Commands::save() {
    this->manager.save();
}

void Commands::saveAs(MyString newFileName) {
    this->manager.saveAs(newFileName);
}

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

void Commands::exit() {

}

void Commands::print() {
    this->manager.print();
}

void Commands::edit(unsigned int row, unsigned int col, MyString newData) {
    if(!this->manager.edit(row, col, newData)){
        std::cout << "There is an error with the data you submitted!\n";
    }
}

void Commands::program() {
    std::cout <<"\n\t      ------WELCOME TO DATABASE MANAGEMENT SYSTEM------\n\n"
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

    std:: cout << "  Enter your choice: \n";
    int choose;
    std::cin >> choose;

    switch (choose) {
        case 1:

            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;
    }



}

void Commands::startProgram() {
    std::cout <<"\n\t      ------WELCOME TO DATABASE MANAGEMENT SYSTEM------                           \n\n"
        << "Enter a URL Table: ";

    MyString fileName;
    std::cin >> fileName;

    this->open(fileName);
    this->program();
}
