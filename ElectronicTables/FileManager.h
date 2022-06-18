//
// Created by Laptop_HP on 13.6.2022 г..
//

#include "MyString.h"
#include "Queue.h"
#include "Data.h"

#ifndef ELECTRONICTABLES_FILEMANAGER_H
#define ELECTRONICTABLES_FILEMANAGER_H


class FileManager{
    private:
        MyString fileName;
        Queue* queue;
        unsigned count;
        unsigned capacity;

        void copy(const FileManager& other);
        void clean();
        void resize();

    public:
        FileManager();
        FileManager(MyString fileName);
        FileManager(const FileManager& other);
        FileManager& operator = (const FileManager& other);
        ~FileManager();

        MyString getFileName() const;
        void save();
        void saveAs(MyString newFileName);
        void print();
        bool edit(unsigned row, unsigned col, MyString newData);
        void read();
};

#endif //ELECTRONICTABLES_FILEMANAGER_H