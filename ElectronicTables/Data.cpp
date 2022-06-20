//
// Created by Laptop_HP on 13.6.2022 г..
//

#include "Data.h"

//private method to copy the property from 'other'
void Data::copy(const Data &other) {
    this->data = other.data;
    this->type = other.type;
}

//private method to delete allocated memory
void Data::clean() {
    this->data.~MyString();
    this->type.~MyString();
}

//default constructor
Data::Data() {

}

//constructor with two arguments with type MyString
Data::Data(MyString data, MyString type) {
    this->data = data;
    this->type = type;
}

//copy constructor
//invoke private method 'clean'
Data::Data(const Data &other) {
    this->copy(other);
}

//redefining operator '='
//copy the 'other' object if it is not the same object
//invoke private methods 'clean' and 'copy'
Data &Data::operator=(const Data &other){
    if(this != &other){
        this->clean();
        this->copy(other);
    }

    return *this;
}

//destructor
Data::~Data() {
    this->clean();
}

//return 'data'(MyString)
MyString& Data::getData() {
    return this->data;
}

//return 'type'(MyString)
MyString& Data::getType() {
    return this->type;
}

//setter for data
void Data::setData(MyString data) {
    this->data = data;
}

//setter for type
void Data::setType(MyString type) {
    this->type = type;
}
