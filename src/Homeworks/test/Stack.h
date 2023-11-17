#ifndef TEST_STACK_H
#define TEST_STACK_H

#include <iostream>
#include <sstream>
#include "list.h"

template<typename T>
class Stack : public List<T> {
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

        iterator& operator++() {
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
        pointer  ptr;

    };*/

    List<T>::iterator begin() override { return typename List<T>::iterator(head); }

    List<T>::iterator end() override { return typename List<T>::iterator(nullptr); }

    List<T>::const_iterator begin() const override { return typename List<T>::const_iterator(head); }

    List<T>::const_iterator end() const override { return typename List<T>::const_iterator(nullptr); }

    List<T>::const_iterator cbegin() const override { return typename List<T>::const_iterator(head); }

    List<T>::const_iterator cend() const override { return typename List<T>::const_iterator(nullptr); }

    Stack();

    Stack(const Stack<T> &first);

    Stack(Stack<T> &&copy);

    ~Stack();

    Stack &operator=(const Stack<T> &first);

    Stack &operator=(Stack<T> &&stack);

    T pop() override;

    void push(const T &n) override;

    T get_front() const override;

    bool is_empty() const override;

    size_t size() const override;

    void print(std::ostream &output) const override;

    template<class U>
    friend std::ostream &operator<<(std::ostream &output, const Stack<U> &stack);

    template<class U>
    friend std::istream &operator>>(std::istream &input, Stack<U> &stack);

private:
    typename List<T>::Node *head;
};

template<typename T>
Stack<T>::Stack(): head(nullptr) {};

template<typename T>
Stack<T>::Stack(const Stack<T> &first) {
    typename List<T>::Node *current = first.head;
    push(current->value);
    current = current->next;
    typename List<T>::Node *old_head = head;
    typename List<T>::Node *new_head = head;
    while (current != nullptr) {
        push(current->value);
        old_head->next = head;
        head->next = nullptr;
        head = new_head;
        old_head = old_head->next;
        current = current->next;
    }
}

template<typename T>
Stack<T>::Stack(Stack<T> &&copy) {
    this->head = copy.head;
    copy.head = nullptr;
}

template<typename T>
Stack<T>::~Stack() {
    while (head != nullptr) {
        typename List<T>::Node *current = head;
        head = head->next;
        delete current;
    }
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack &first) {
    if (this != (&first)) {
        while (head != nullptr) {
            typename List<T>::Node *current = head;
            head = head->next;
            delete current;
        }

        typename List<T>::Node *current = first.head;
        push(current->value);
        current = current->next;
        typename List<T>::Node *old_head = head;
        typename List<T>::Node *new_head = head;
        while (current != nullptr) {
            push(current->value);
            old_head->next = head;
            head->next = nullptr;
            head = new_head;
            old_head = old_head->next;
            current = current->next;
        }
    }
    return *this;
}

template<typename T>
Stack<T> &Stack<T>::operator=(Stack<T> &&stack) {
    if (&stack != this) {
        while (this->head != nullptr) {
            typename Stack<T>::Node *current = this->head;
            this->head = this->head->next;
            delete current;
        }
        this->head = stack.head;
        stack.head = nullptr;
    }
    return *this;
}

template<typename T>
void Stack<T>::push(const T &n) {
    typename List<T>::Node *node = new typename List<T>::Node(n);
    if (head == nullptr) {
        head = node;
        head->next = nullptr;
    } else {
        node->next = head;
        head = node;
    }
}

template<typename T>
T Stack<T>::pop() {
    int n = head->value;
    typename List<T>::Node *current = head;
    head = head->next;
    delete current;
    return n;
}

template<typename T>
T Stack<T>::get_front() const {
    return head->value;
}

template<typename T>
bool Stack<T>::is_empty() const {
    return head == nullptr;
}

template<typename T>
size_t Stack<T>::size() const {
    size_t n = 0;
    typename List<T>::Node *current = head;
    while (current != nullptr) {
        ++n;
        current = current->next;
    }
    return n;
}

template<typename T>
std::ostream &operator<<(std::ostream &output, const Stack<T> &stack) {
    stack.print(output);
    return output;
}

template<typename T>
std::istream &operator>>(std::istream &input, Stack<T> &stack) {
    std::string value;
    T element;
    std::cout << "Enter Stack elements: ";
    std::getline(input, value);
    std::stringstream ss(value);
    while (ss >> element) {
        stack.push(element);
    }
    return input;
}

template<typename T>
void Stack<T>::print(std::ostream &output) const {
    for (typename List<T>::const_iterator i = begin(); i != end(); ++i) {
        output << *i << "->";
    }
    output << "nullptr";
}

#endif //TEST_STACK_H
