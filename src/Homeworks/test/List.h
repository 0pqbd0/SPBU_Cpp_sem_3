#ifndef TEST_LIST_H
#define TEST_LIST_H

#include <iostream>

template<typename T>
class List {
protected:
    struct Node;
public:
    class const_iterator;

    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = Node;
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

        /*reference*/
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

    };

    virtual iterator begin() = 0;

    virtual iterator end() = 0;

    virtual const_iterator begin() const = 0;

    virtual const_iterator end() const = 0;

    virtual const_iterator cbegin() const = 0;

    virtual const_iterator cend() const  = 0;

    List() = default;
    virtual ~List() = default;
    virtual void push(const T& n) = 0;
    virtual T pop() = 0;
    virtual T get_front() const = 0;
    virtual bool is_empty() const = 0;
    virtual size_t size() const = 0;
protected:
    struct Node {
        T value;
        Node* next;
        Node(const T& n);
    };
    virtual void print(std::ostream& output) const = 0;
};

template<typename T>
List<T>::Node::Node(const T& n) : value(n), next(nullptr) {};

#endif //TEST_LIST_H