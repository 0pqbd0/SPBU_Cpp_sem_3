#ifndef LIST_TEMPLATES_LIST_H
#define LIST_TEMPLATES_LIST_H
#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>
#include <sstream>

template<typename T>
class List {
public:
    List() : head(nullptr), size(0) {};

    List(const List<T> &first) : size(0), head(nullptr) {
        Node *current = first.head;
        push(current->value);
        current = current->next;
        Node *old_head = head;
        Node *new_head = head;
        while (current != nullptr) {
            push(current->value);
            old_head->next = head;
            head->next = nullptr;
            head = new_head;
            old_head = old_head->next;
            current = current->next;
        }
    }

    ~List() {
        while (head != nullptr) {
            Node *current = head;
            head = head->next;
            delete current;
        }
    }

    List<T> &operator=(const List &first) {
        if (this != (&first)) {
            while (head != nullptr) {
                Node *current = head;
                head = head->next;
                delete current;
            }

            Node *current = first.head;
            push(current->value);
            current = current->next;
            Node *old_head = head;
            Node *new_head = head;
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

    virtual void push(const T& value) {
        Node *new_elem = new Node(value);
        if (!size) {
            head = new_elem;
        } else {
            new_elem->next = head;
            head = new_elem;
        }
        size += 1;
    }

    T pop() {
        T n = head->value;
        Node *current = head;
        head = head->next;
        delete current;
        size -= 1;
        return n;
    }

    int get_front() const {
        return head->value;
    }

    bool is_empty() const {
        return head == nullptr;
    }

    size_t size_() const {
        return size;
    }

    friend std::ostream &operator<<(std::ostream &output, const List<T> &list) {
        list.print(output);
        return output;
    }

    friend std::istream &operator>>(std::istream &input, List<T> &list) {
        std::string value;
        T element;
        std::cout << "Enter List elements: ";
        std::getline(input, value);
        std::stringstream ss(value);
        while (ss >> element) {
            list.push(element);
        }
        return input;
    }
protected:
    size_t size;

    struct Node {
        T value;
        Node *next;

        Node(const T& n) : value(n), next(nullptr) {};
    };

    void print(std::ostream &output) const {
        Node *current = head;
        while (current) {
            output << current->value << " -> ";
            current = current->next;
        }
        output << "nullptr" << std::endl;
    }

    Node *head;
};





#endif //LIST_LIST_H

#endif //LIST_TEMPLATES_LIST_H
