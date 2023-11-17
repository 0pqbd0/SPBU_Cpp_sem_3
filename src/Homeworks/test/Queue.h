#ifndef TEST_QUEUE_H
#define TEST_QUEUE_H

#include <iostream>
#include <sstream>
#include "list.h"

template<typename T>
class Queue: public List<T> {
public:
/*    class const_iterator;
    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = List<T>::Node;
        using pointer = value_type *;
        using reference = value_type &;

        iterator(pointer p = nullptr) : ptr(p) {}

        T& operator*() const {
            return (*ptr).value;
        }

        pointer operator->() const {
            return ptr;
        }

        iterator &operator++() {
            ptr = ptr->next;
            return *this;
        }

        iterator &operator++(T value) {
            iterator tmp = *this;
            ++ptr;
            return tmp;
        }

        bool operator==(const iterator &iter) const {
            return ptr == iter.ptr;
        }

        bool operator!=(const iterator &iter) const {
            return ptr != iter.ptr;
        }

        friend const_iterator;

    private:
        pointer ptr;
    };

    class const_iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = const List<T>::Node;
        using pointer = const value_type *;
        using reference = const value_type &;

        const_iterator(pointer p = nullptr) : ptr(p) {}

        const_iterator(const iterator &iter) : ptr(iter.ptr) {}

        const T& operator*() const {
            return (*ptr).value;
        }

        pointer operator->() const {
            return ptr;
        }

        const_iterator &operator++() {
            ptr = ptr->next;
            return *this;
        }

        const_iterator &operator++(T value) {
            const_iterator tmp = *this;
            ++ptr;
            return tmp;
        }

        bool operator==(const const_iterator &iter) const {
            return ptr == iter.ptr;
        }

        bool operator!=(const const_iterator &iter) const {
            return ptr != iter.ptr;
        }

        friend iterator;

    private:
            pointer ptr;

    };*/

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
    void print(std::ostream& output) const override;

    template<class U>
    friend std::ostream& operator << (std::ostream& output, const Queue<U>& queue);
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
std::ostream& operator << (std::ostream& output, const Queue<T>& list) {
    list.print(output);
    return output;
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

template<typename T>
void Queue<T>::print(std::ostream& output) const {
    typename List<T>::Node* current = head;
    while (current != nullptr) {
        output << current->value << "->";
        current = current->next;
    }
    output << "nullptr";
}

#endif //TEST_QUEUE_H
