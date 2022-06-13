//
// Created by Laptop_HP on 12.6.2022 г..
//

#include "MyString.h"
#include<iostream>

void MyString::copy(const MyString &other) {
    this->str = new char[other.getSize()];

    for(int i = 0; other.str[i] != '\0'; ++i){
        this->str[i] = other.str[i];
    }
    this->str[other.getSize() - 1] = '\0';
}

void MyString::clean() {
    delete[] this->str;
}

MyString::MyString() {
    this->str = new char[1];
    this->str[0] = '\0';
}

MyString::MyString(const char *str) {
    for(int i = 0; str[i] != '\0'; ++i){
        this->str[i] = str[i];
    }
    this->str[strlen(str) - 1] = '\0';
}

MyString::MyString(const MyString &other) {
    if(this != &other){
        this->clean();
        this->copy(other);
    }
}

MyString::~MyString() {
    this->clean();
}

unsigned MyString::getSize() const {
    return strlen(this->str);
}

void MyString::print() const {
    std::cout << this->str;
}

void MyString::add(const char *str) {
    unsigned tempSize = this->getSize() + strlen(str) + 1;
    char* temp = new char[tempSize];
    strcpy_s(temp, tempSize, this->str);
    strcat_s(temp, tempSize, str);

    this->clean();

    this->str = temp;
}

MyString MyString::operator+(const MyString &other) {
    this->add(other.str);

    return *this;
}

std::istream &operator>>(std::istream &in, const MyString &str) {
    in >> str.str;
    return in;
}

std::ostream &operator<<(std::ostream out, const MyString &str) {
    out << str.str;
    return out;
}
