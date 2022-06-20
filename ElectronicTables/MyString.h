//
// Created by Laptop_HP on 12.6.2022 г..
//

#include <istream>

#ifndef ELECTRONICTABLES_MYSTRING_H
#define ELECTRONICTABLES_MYSTRING_H

class MyString {
    private:
        char* str;
        void copy(const MyString& other);
        void clean();

    public:
        MyString();
        MyString(const char* str);
        MyString(const MyString& other);
        MyString& operator = (const MyString& other);
        ~MyString();

        unsigned getSize() const;
        void print() const;
        void add(const char* str);
        MyString& operator + (const MyString& other);
        char* toString();
        bool isEmpty()const;

        friend std::istream& operator >> (std::istream& in, const MyString& str);
        friend std::ostream& operator << (std::ostream out, const MyString& str);
};

#endif //ELECTRONICTABLES_MYSTRING_H