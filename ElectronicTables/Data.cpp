//
// Created by Laptop_HP on 13.6.2022 г..
//

#include "Data.h"


void Data::copy(const Data &other) {
    this->data = other.data;
    this->type = other.type;
}

void Data::clean() {
    delete &this->type, &this->data;
    this->type = nullptr;
    this->data = nullptr;
}

Data::Data() {
    this->data = nullptr;
    this->type = nullptr;
}

Data::Data(MyString data, MyString type) {
    this->data = data;
    this->type = type;
}

Data::Data(const Data &other) {
    this->copy(other);
}

Data &Data::operator=(const Data &other){
    if(this != &other){
        this->clean();
        this->copy(other);
    }

    return *this;
}

Data::~Data() {
    this->clean();
}
