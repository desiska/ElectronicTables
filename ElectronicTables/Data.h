//
// Created by Laptop_HP on 13.6.2022 г..
//

#include "MyString.h"
#include<fstream>

#ifndef ELECTRONICTABLES_HASHTABLE_H
#define ELECTRONICTABLES_HASHTABLE_H


class Data{
    private:
        MyString data;
        MyString type;
        void copy(const Data& other);
        void clean();

    public:
        Data();
        Data(MyString data, MyString type);
        Data(const Data& other);
        Data& operator = (const Data& other);
        ~Data();

        MyString getData();
        MyString getType();
        void setData(MyString data);
        void setType(MyString type);
};

#endif //ELECTRONICTABLES_HASHTABLE_H
