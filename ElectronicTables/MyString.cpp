//
// Created by Laptop_HP on 12.6.2022 г..
//

#include "MyString.h"
#include<iostream>

void MyString::copy(const MyString &other) {
    this->str = new char[other.getSize() + 1];

    for(int i = 0; other.str[i] != '\0'; ++i){
        this->str[i] = other.str[i];
    }
    this->str[other.getSize()] = '\0';
}

void MyString::clean() {
    delete[] this->str;
    this->str = nullptr;
}

MyString::MyString() {
    this->str = new char[1];
    this->str[0] = '\0';
}

MyString::MyString(const char *str) {
    this->str = new char[strlen(str) + 1];
    for(int i = 0; str[i] != '\0'; ++i){
        this->str[i] = str[i];
    }
    this->str[strlen(str)] = '\0';
}

MyString::MyString(const MyString &other) {
    this->copy(other);
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

MyString &MyString::operator=(const MyString &other) {
    if(this != &other){
        this->clean();
        this->copy(other);
    }

    return *this;
}

char *MyString::toString() {
    return this->str;
}

bool MyString::isEmpty() const {
    return this->getSize() == 0;
}

