//
// Created by Laptop_HP on 13.6.2022 г..
//

#include <iostream>
#include "Queue.h"

Queue::Queue() {
    this->size = 0;
    this->capacity = 8;
    this->queue = new Data[this->capacity];
}

Queue::Queue(Data *queue, unsigned size) {
    this->queue = queue;
    this->size = size;
    this->capacity = 8;

    while(this->size > this->capacity){
        this->resize();
    }
}

Queue::Queue(const Queue &other) {
    this->copy(other);
}

Queue &Queue::operator=(const Queue &other) {
    if(this != &other){
        this->clean();
        this->copy(other);
    }

    return *this;
}

Queue::~Queue() {
    this->clean();
}

void Queue::push(Data data) {
    if(this->size == this->capacity){
        this->resize();
    }

    this->queue[this->size++] = data;
}

void Queue::pop() {
    if(this->size > 0) {
        Data temp = this->queue[0];

        for (int i = 0; i < this->size - 1; ++i) {
            this->queue[i] = this->queue[i + 1];
        }

        delete &temp;
        --this->size;
    }
}

Data Queue::peek() {
    return this->queue[0];
}

void Queue::copy(const Queue &other) {
    this->capacity = other.capacity;
    this->size = other.size;
    this->queue = new Data[this->capacity];

    for(int i = 0; i < this->size; ++i){
        this->queue[i] = other.queue[i];
    }
}

void Queue::clean() {
    for(int i = 0; i < this->size; ++i){
        delete &this->queue[i];
    }
    delete &this->queue;
}

void Queue::resize() {
    this->capacity *= 2;
    Data* temp = new Data[this->capacity];

    for(int i = 0; i < this->size; ++i){
        temp[i] = this->queue[i];
    }

    delete this->queue;

    this->queue = temp;
}

unsigned Queue::getSize() {
    return this->size;
}

Data *Queue::getQueue() {
    return this->queue;
}

void Queue::print() {
    for(int i = 0; i < this->size; ++i){
        std::cout << this->queue[i].getData().toString() << '|';
    }
    std::cout << '\n';
}

