//
// Created by Laptop_HP on 13.6.2022 г..
//

#include "FileManager.h"
#include<fstream>

void FileManager::copy(const FileManager &other) {
    this->fileName = other.fileName;
    this->queue = other.queue;
}

void FileManager::clean() {
    delete &this->fileName;

    for(int i = 0; i < this->count; ++i){
        delete &this->queue[i];
    }

    delete this->queue;
}

FileManager::FileManager() {
    this->fileName = nullptr;
    this->count = 0;
    this->capacity = 8;
    this->queue = new Queue[this->capacity];
}

FileManager::FileManager(MyString fileName) {
    this->fileName = fileName;
    this->count = 0;
    this->capacity = 8;
    this->queue = new Queue[this->capacity];
}

FileManager::FileManager(const FileManager &other) {
    this->copy(other);
}

FileManager &FileManager::operator=(const FileManager &other) {
    if(this != &other){
        this->clean();
        this->copy(other);
    }

    return *this;
}

FileManager::~FileManager() {
    this->clean();
}

MyString FileManager::getFileName() const {
    return this->fileName;
}

void FileManager::save() {
    this->saveAs(this->fileName);
}

void FileManager::saveAs(MyString newFileName) {
    std::ofstream out;
    out.open(newFileName.toString());
    if(out){
        for(int row = 0; row < this->count; ++row){
            for(int col = 0; col < this->queue[row].getSize(); ++col){
                out << this->queue[row].getQueue()[col].getData().toString() << '|';
            }
            out << '\n';
        }
    }
    out.close();
}

void FileManager::print() {
    for(int i = 0; i < this->count; ++i){
        this->queue[i].print();
    }
}

bool FileManager::edit(unsigned row, unsigned col, MyString newData) {
    if(this->queue->getSize() < row && this->queue[row - 1].getSize() < col){
        return false;
    }

    delete &this->queue[row - 1].getQueue()[col - 1];

    char* string = newData.toString();

    if(string[0] == '='){
        this->queue[row - 1].getQueue()[col - 1] = Data(newData, MyString("Formula"));
    }
    else if (string[0] == '\"'){
        this->queue[row - 1].getQueue()[col - 1] = Data(newData, MyString("CharArray"));
    }
    else{
        bool isDouble = false;
        for(int i = 0; !isDouble && string[i] != '\0'; ++i){
            if(string[i] == '.'){
                isDouble = true;
            }
        }

        if(isDouble){
            this->queue[row - 1].getQueue()[col - 1] = Data(newData, MyString("Double"));
        }
        else{
            this->queue[row - 1].getQueue()[col - 1] = Data(newData, MyString("Integer"));
        }
    }

    return true;
}

void FileManager::read() {
    std::ifstream in;
    in.open(this->fileName.toString());
    if(in){
        while(!in.eof()) {
            char *input;
            in >> input;
            unsigned cols = 0;

            for(int i = 0; input[i] != '\0'; ++i){
                if(input[i] == ','){
                    cols++;
                }
            }

            Data *temp = new Data[cols];
            cols = 0;
            bool startQuоte = true;
            char* string = new char[strlen(input)];
            unsigned symbolsCount = 0;
            unsigned type = 0;

            for(int i = 0; input[i] != '\0'; ++i){
                if(input[i] == ' ' && !startQuоte){
                    string[symbolsCount++] = input[i];
                }
                else if(input[i] == '\"'){
                    if(startQuоte){
                        startQuоte = false;
                        type = 1;
                    }
                    else{
                        startQuоte = true;
                    }
                    string[symbolsCount++] = input[i];
                }
                else if(input[i] >= '0' && input[i] <= '9'){
                    string[symbolsCount++] = input[i];
                    type = 2;
                }
                else if(input[i] == '.'){
                    string[symbolsCount++] = input[i];
                    type = 3;
                }
                else if(input[i] == '='){
                    string[symbolsCount++] = input[i];
                    type = 4;
                }
                else if(input[i] == ','){
                    strcpy_s(string, symbolsCount, string);
                    MyString data(string);
                    MyString typeData;
                    switch (type) {
                        case 1:
                            typeData.add("CharArray");
                            break;

                        case 2:
                            typeData.add("Integer");
                            break;

                        case 3:
                            typeData.add("Double");
                            break;

                        case 4:
                            typeData.add("Formula");
                            break;
                    }

                    temp[cols++] = Data(data, typeData);
                    delete[] string;
                    string = nullptr;
                    type = 0;
                    symbolsCount = 0;
                }
                else if(input[i] != ' '){
                    string[symbolsCount++] = input[i];
                }
            }

            if(this->count == this->capacity){
                this->resize();
            }

            this->queue[this->count++] = Queue(temp, cols);
        }
    }
    in.close();
}

void FileManager::resize() {
    this->capacity *= 2;
    Queue* temp = new Queue[this->capacity];

    for(int i = 0; i < this->count; ++i){
        temp[i] = this->queue[i];
    }

    for(int i = 0; i < this->count; ++i){
        delete &this->queue[i];
    }
    delete this->queue;

    this->queue = temp;
}
