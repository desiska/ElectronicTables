//
// Created by Laptop_HP on 12.6.2022 г..
//

#include "MyString.h"
#include<iostream>

//private method to copy another MyString
void MyString::copy(const MyString &other) {
    this->str = new char[other.getSize() + 1];

    for(int i = 0; other.str[i] != '\0'; ++i){
        this->str[i] = other.str[i];
    }
    this->str[other.getSize()] = '\0';
}

//private method to delete the allocated memory
void MyString::clean() {
    delete[] this->str;
    this->str = nullptr;
}

//default constructor
MyString::MyString() {
    this->str = new char[1];
    this->str[0] = '\0';
}

//default constructor with const char array argument
MyString::MyString(const char *str) {
    this->str = new char[strlen(str) + 1];
    for(int i = 0; str[i] != '\0'; ++i){
        this->str[i] = str[i];
    }
    this->str[strlen(str)] = '\0';
}

//copy constructor
MyString::MyString(const MyString &other) {
    this->copy(other);
}

//destructor
MyString::~MyString() {
    this->clean();
}

//return the size of property char array 'str'
unsigned MyString::getSize() const {
    return strlen(this->str);
}

//printing property 'str'
void MyString::print() const {
    std::cout << this->str;
}

//add characters to the end of the array
void MyString::add(const char *str) {
    unsigned tempSize = this->getSize() + strlen(str) + 1;
    char* temp = new char[tempSize];
    strcpy_s(temp, tempSize, this->str);
    strcat_s(temp, tempSize, str);

    this->clean();

    this->str = temp;
}

//operator to add characters to the end of the array
//invoke 'add' method
//return new MyString
MyString& MyString::operator+(const MyString &other) {
    this->add(other.str);

    return *this;
}

//redefining operator '>>'
std::istream &operator>>(std::istream &in, const MyString &str) {
    in >> str.str;
    return in;
}

//redefining operator '<<'
std::ostream &operator<<(std::ostream out, const MyString &str) {
    out << str.str;
    return out;
}

//redefining operator '='
//copy the 'other' object if it is not the same object
MyString &MyString::operator=(const MyString &other) {
    if(this != &other){
        this->clean();
        this->copy(other);
    }

    return *this;
}

//return char array 'str'
char *MyString::toString() {
    return this->str;
}

//checks if the 'str' is an empty char array
bool MyString::isEmpty() const {
    return this->getSize() == 0;
}

