//
// Created by Laptop_HP on 13.6.2022 г..
//

#include "FileManager.h"
#include<fstream>

//private method to copy 'other' property
void FileManager::copy(const FileManager &other) {
    this->fileName = other.fileName;
    this->queue = other.queue;
}

//private method to delete the allocated memory
void FileManager::clean() {
    this->fileName.~MyString();

    for(int i = 0; i < this->capacity; ++i){
        this->queue[i].~Queue();
    }

    this->queue->~Queue();
}

//default constructor
FileManager::FileManager() {
    this->count = 0;
    this->capacity = 8;
    this->queue = new Queue[this->capacity];
}

//constructor with one property(MyString)
FileManager::FileManager(MyString& fileName) {
    this->fileName = fileName;
    this->count = 0;
    this->capacity = 8;
    this->queue = new Queue[this->capacity];
}

//copy constructor
FileManager::FileManager(const FileManager &other) {
    this->copy(other);
}

//redefining operator '='
//copy the 'other' object if it is not the same object
FileManager &FileManager::operator=(const FileManager &other) {
    if(this != &other){
        this->clean();
        this->copy(other);
    }

    return *this;
}

//destructor
FileManager::~FileManager() {
    this->clean();
}

//return 'fileName'(MyString)
MyString FileManager::getFileName() const {
    return this->fileName;
}

//save the datas with the updates in the open file
//invoke method saveAs
void FileManager::save() {
    this->saveAs(this->fileName);
}

//argument newFileName is the URL of the file where has to save datas
//save the datas with the updates in the 'newFileName'
void FileManager::saveAs(MyString& newFileName) {
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

//print on the console data
void FileManager::print() {
    for(int i = 0; i < this->count; ++i){
        this->queue[i].print();
    }
}

//update datas
bool FileManager::edit(unsigned row, unsigned col, MyString& newData) {
    if(this->queue->getSize() < row && this->queue[row - 1].getSize() < col){
        return false;
    }

    this->queue[row - 1].getQueue()[col - 1].~Data();

    if(newData.toString()[0] == '='){
        Data data(newData, MyString("Formula"));
        this->queue[row - 1].getQueue()[col - 1] = data;
        data.~Data();
    }
    else if (newData.toString()[0] == '\"'){
        Data data(newData, MyString("CharArray"));
        this->queue[row - 1].getQueue()[col - 1] = data;
        data.~Data();
    }
    else{
        bool isDouble = false;
        for(int i = 0; !isDouble && newData.toString()[i] != '\0'; ++i){
            if(newData.toString()[i] == '.'){
                isDouble = true;
            }
        }

        if(isDouble){
            Data data(newData, MyString("Double"));
            this->queue[row - 1].getQueue()[col - 1] = data;
            data.~Data();
        }
        else{
            Data data(newData, MyString("Integer"));
            this->queue[row - 1].getQueue()[col - 1] = data;
            data.~Data();
        }
    }

    return true;
}

//read the information from file and save them in the application
void FileManager::read() {
    std::ifstream in;
    in.open(this->fileName.toString());
    if (in) {
        while (!in.eof()) {
            char input[2048];
            in.getline(input, 2048);
            unsigned cols = 1;

            for (int i = 0; input[i] != '\0'; ++i) {
                if (input[i] == ',') {
                    cols++;
                }
            }

            Data *temp = new Data[cols];
            cols = 0;
            unsigned symbolsCount = 0;
            unsigned type = 0;

            for (int i = 0; input[i] != '\0'; ++i) {
                char string[2048];

                if (type == 0) {
                    if (input[i] == '\"') {
                        type = 1;
                    } else if (input[i] >= '0' && input[i] <= '9') {
                        type = 2;
                    } else if (input[i] == '=') {
                        type = 4;
                    }
                }

                if (input[i] != ' ') {
                    if (input[i] == '.' && type == 2) {
                        type = 3;
                        string[symbolsCount++] = input[i];
                    }
                    else if (input[i] == ',' || input[i + 1] == '\0') {
                        if(input[i + 1] == '\0'){
                            string[symbolsCount++] = input[i];
                        }

                        char *newString = new char[symbolsCount + 1];

                        for (int s = 0; s < symbolsCount; ++s) {
                            newString[s] = string[s];
                        }
                        newString[symbolsCount] = '\0';

                        MyString data(newString);
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

                        Data newData(data, typeData);
                        temp[cols++] = newData;
                        type = 0;
                        symbolsCount = 0;
                    }
                    else{
                        string[symbolsCount++] = input[i];
                    }
                }
                if (this->count == this->capacity) {
                    this->resize();
                }
            }
            Queue newQueue(temp, cols);

            this->queue[this->count++] = newQueue;
        }
    }
    in.close();
}

//resized queue(Queue array)
void FileManager::resize() {
    this->capacity *= 2;
    Queue* temp = new Queue[this->capacity];

    for(int i = 0; i < this->count; ++i){
        temp[i] = this->queue[i];
    }

    for(int i = 0; i < this->count; ++i){
        this->queue[i].~Queue();
    }
    this->queue->~Queue();

    this->queue = temp;
}
