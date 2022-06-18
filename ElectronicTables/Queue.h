//
// Created by Laptop_HP on 13.6.2022 г..
//

#include "Data.h"

#ifndef ELECTRONICTABLES_QUEUE_H
#define ELECTRONICTABLES_QUEUE_H

#endif //ELECTRONICTABLES_QUEUE_H

class Queue{
    private:
        Data* queue;
        unsigned size;
        unsigned capacity;
        void copy(const Queue& other);
        void clean();
        void resize();

    public:
        Queue();
        Queue(Data* queue, unsigned size);
        Queue(const Queue& other);
        Queue& operator = (const Queue& other);
        ~Queue();

        void push(Data data);
        void pop();
        Data peek();
        unsigned getSize();
        Data* getQueue();
        void print();

};
