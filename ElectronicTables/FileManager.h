//
// Created by Laptop_HP on 13.6.2022 г..
//

#include "MyString.h"
#include "Queue.h"

#ifndef ELECTRONICTABLES_FILEMANAGER_H
#define ELECTRONICTABLES_FILEMANAGER_H

#endif //ELECTRONICTABLES_FILEMANAGER_H

class FileManager{
    private:
        MyString fileName;

        void copy(const FileManager& other);
        void clean();

    public:
        FileManager();
        FileManager(MyString fileName);
        FileManager(const FileManager& other);
        FileManager& operator = (const FileManager& other);
        ~FileManager();
};