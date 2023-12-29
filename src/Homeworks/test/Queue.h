#ifndef TEST_QUEUE_H
#define TEST_QUEUE_H

#include <iostream>
#include <sstream>
#include "List.h"

template<typename T>
class Queue: public List<T> {
public:

    List<T>::iterator begin() override{ return typename List<T>::iterator(head); }

    List<T>::iterator end() override { return typename List<T>::iterator(nullptr); }

    List<T>::const_iterator begin() const override { return typename List<T>::const_iterator(head); }

    List<T>::const_iterator end() const override { return typename List<T>::const_iterator(nullptr); }

    List<T>::const_iterator cbegin() const override { return typename List<T>::const_iterator(head); }

    List<T>::const_iterator cend() const override { return typename List<T>::const_iterator(nullptr); }

    Queue();
    Queue(const Queue<T>& first);
    Queue(Queue<T>&& copy);
    ~Queue();

    Queue& operator = (Queue<T>&& queue);
    Queue& operator = (const Queue<T>& first);

    T pop() override;
    void push(const T& value) override;
    T get_front() const override;
    T get_tail() const;
    bool is_empty() const override;
    size_t size() const override;

    template<class U>
    friend std::istream& operator >> (std::istream& input, Queue<U>& queue);

private:
    typename List<T>::Node* head;
    typename List<T>::Node* tail;
};


template<typename T>
Queue<T>::Queue(): head(nullptr), tail(nullptr) {};

template<typename T>
Queue<T>::Queue(const Queue<T>& first): head(nullptr), tail(nullptr) {
    typename List<T>::Node* current = first.head;
    while (current != nullptr) {
        push(current->value);
        current = current->next;
    }
};

template<typename T>
Queue<T>::Queue(Queue<T>&& copy) {
    this->head = copy.head;
    copy.head = nullptr;
}

template<typename T>
Queue<T>::~Queue() {
    while (head != nullptr) {
        typename List<T>::Node* current = head;
        head = head->next;
        delete current;
    }
};

template<typename T>
Queue<T>& Queue<T>::operator = (const Queue<T>& first) {
    if (this != (&first)) {
        while (head != nullptr) {
            typename List<T>::Node* current = head;
            head = head->next;
            delete current;
        }
        tail = nullptr;

        typename List<T>::Node *current = first.head;
        while (current != nullptr) {
            push(current->value);
            current = current->next;
        }
    }
    return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator = (Queue<T>&& queue) {
    if (&queue != this) {
        while (this->head != nullptr) {
            typename List<T>::Node *current = this->head;
            this->head = this->head->next;
            delete current;
        }
        this->head = queue.head;
        queue.head = nullptr;
    }
    return *this;
}

template<typename T>
void Queue<T>::push(const T& value) {
    typename List<T>::Node* node = new typename List<T>::Node(value);
    if (this->head == nullptr) {
        this->head = node;
        tail = node;
    }
    else {
        tail->next = node;
        node->next = nullptr;
        tail = node;
    }
}

template<typename T>
T Queue<T>::pop() {
    int n = head->value;
    typename List<T>::Node* current = head;
    head = head->next;
    delete current;
    return n;
}

template<typename T>
T Queue<T>::get_front() const {
    return head->value;
}

template<typename T>
T Queue<T>::get_tail() const {
    return tail->value;
}

template<typename T>
bool Queue<T>::is_empty() const {
    return head == nullptr;
}

template<typename T>
size_t Queue<T>::size() const {
    size_t n = 0;
    typename List<T>::Node* current = head;
    while (current != nullptr) {
        ++n;
        current = current->next;
    }
    return n;
}

template<typename T>
std::istream& operator >> (std::istream& input, Queue<T>& list) {
    std::string value;
    T element;
    std::cout << "Enter Queue elements: ";
    std::getline(input, value);
    std::stringstream ss(value);
    while (ss >> element) {
        list.push(element);
    }
    return input;
}


#endif //TEST_QUEUE_H