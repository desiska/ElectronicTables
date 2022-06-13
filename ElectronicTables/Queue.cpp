//
// Created by Laptop_HP on 13.6.2022 г..
//

#include "Queue.h"

template<typename T>
void Queue<T>::copy(const Queue<T> &other) {
    if(other.prev != nullptr){
        this->prev = new Queue<T>(other.prev->data);
        this->next = this->prev;
        Node<T>* curr = other.prev->next;
        while (curr){
            this->push(curr->data);
            curr = curr->next;
        }
    }
}

template<typename T>
void Queue<T>::clean() {
    while (this->prev){
        Node<T>* temp = this->prev;
        this->prev = prev->next;
        delete temp;
    }
}

template<typename T>
Queue<T>::Queue() {
    this->prev = nullptr;
    this->next = nullptr;
}

template<typename T>
Queue<T>::Queue(const Queue<T> &other) {
    this->copy(other);
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &other) {
    if(this != &other){
        this->clean();
        this->copy(other);
    }

    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    this->clean();
}

template<typename T>
void Queue<T>::push(T data) {
    Node<T>* temp = new Node<T>(data);

    if(this->next == nullptr){
        this->prev = this->next = temp;
    }
    else{
        this->next->next = temp;
        this->next = temp;
    }
}

template<typename T>
void Queue<T>::pop() {
    if(this->prev != nullptr){
        Node<T>* temp = this->prev;
        this->prev = this->prev->next;

        if(this->prev == nullptr){
            this->next = nullptr;
        }

        delete temp;
    }
}
