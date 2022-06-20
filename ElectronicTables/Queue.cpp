//
// Created by Laptop_HP on 13.6.2022 г..
//

#include <iostream>
#include "Queue.h"

//default constructor
Queue::Queue() {
    this->size = 0;
    this->capacity = 8;
    this->queue = new Data[this->capacity];
}

//default constructor with two argument - Data and unsigned int
Queue::Queue(Data *queue, unsigned size) {
    this->queue = queue;
    this->size = size;
    this->capacity = 8;

    while(this->size > this->capacity){
        this->resize();
    }
}

//copy constructor
//invoke private method 'copy'
Queue::Queue(const Queue &other) {
    this->copy(other);
}

//redefining operator '='
//copy the 'other' object if it is not the same object
Queue &Queue::operator=(const Queue &other) {
    if(this != &other){
        this->clean();
        this->copy(other);
    }

    return *this;
}

//destructor
Queue::~Queue() {
    this->clean();
}

//add Data in the Data array
void Queue::push(Data& data) {
    if(this->size == this->capacity){
        this->resize();
    }

    this->queue[this->size++] = data;
}

//remove first element from Data array(the property queue)
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

//return the first element from Data array(property queue)
Data Queue::peek() {
    return this->queue[0];
}

//private method to copy the property from 'other' argument
void Queue::copy(const Queue &other) {
    this->capacity = other.capacity;
    this->size = other.size;
    this->queue = new Data[this->capacity];

    for(int i = 0; i < this->size; ++i){
        this->queue[i] = other.queue[i];
    }
}

//private method to delete the allocated memory
void Queue::clean() {
    for(int i = 0; i < this->size; ++i){
        this->queue[i].~Data();
    }

    this->queue->~Data();
}

//resized queue(Data array)
void Queue::resize() {
    this->capacity *= 2;
    Data* temp = new Data[this->capacity];

    for(int i = 0; i < this->size; ++i){
        temp[i] = this->queue[i];
    }

    for(int i = 0; i < this->size; ++i){
        this->queue[i].~Data();
    }
    this->queue->~Data();

    this->queue = temp;
}

//return count of the Data from queue(Data array)
unsigned Queue::getSize() {
    return this->size;
}

//return queue(Data array)
Data *Queue::getQueue() {
    return this->queue;
}

//print on the console queue(Data array)
void Queue::print() {
    for(int i = 0; i < this->size; ++i){
        std::cout << this->queue[i].getData().toString() << '|';
    }
    std::cout << '\n';
}

