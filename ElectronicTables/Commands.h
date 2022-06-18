//
// Created by Laptop_HP on 12.6.2022 г..
//

#include "FileManager.h"

#ifndef ELECTRONICTABLES_COMMANDS_H
#define ELECTRONICTABLES_COMMANDS_H

#endif //ELECTRONICTABLES_COMMANDS_H

class Commands{
    private:
        FileManager manager;

        void copy(const Commands& other);
        void clean();

    public:
        Commands();
        Commands(const Commands& other);
        Commands& operator = (const Commands& other);
        ~Commands();

        void open(MyString fileName);
        void close();
        void save();
        void saveAs(MyString newFileName);
        void help();
        void exit();
        void print();
        void edit(unsigned row, unsigned col, MyString newData);
        void startProgram();
        void program();
};