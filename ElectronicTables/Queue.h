//
// Created by Laptop_HP on 13.6.2022 г..
//

#ifndef ELECTRONICTABLES_QUEUE_H
#define ELECTRONICTABLES_QUEUE_H

#endif //ELECTRONICTABLES_QUEUE_H

template<typename T>
struct Node{
    T data;
    Node* next;

    Node(T data){
        this->data = data;
        this->next = nullptr;
    }
};

template<typename T>
class Queue{
    private:
        Node<T>* prev;
        Node<T>* next;
        void copy(const Queue<T>& other);
        void clean();

    public:
        Queue();
        Queue(const Queue<T>& other);
        Queue<T>& operator = (const Queue<T>& other);
        ~Queue();

        void push(T data);
        void pop();
};
