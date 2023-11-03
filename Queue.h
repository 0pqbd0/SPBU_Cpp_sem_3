#ifndef LIST_TEMPLATES_QUEUE_H
#define LIST_TEMPLATES_QUEUE_H
#include"List.h"

template<typename T>
class Queue: public List<T>{
public:
    Queue() : List<T>(), tail(nullptr) {}

    Queue(const Queue &copy) :  tail(nullptr) {
        typename List<T>::Node* new_node = copy.head;
        while (new_node) {
            push(new_node->value);
            new_node = new_node->next;
        }
    }

    Queue(Queue<T>&& copy) {
        this->size = copy.size_(); //???
        copy.size = 0;
        this->head = copy.head;
        copy.head = nullptr;
    }

    ~Queue() = default;

    Queue<T> &operator=(const Queue<T> &queue) {
        if (&queue != this) {
            clear();
            typename List<T>::Node *new_node = queue.head;
            while (new_node) {
                push(new_node->value);
                new_node = new_node->next;
            }
        }
        return *this;
    }

    Queue<T> &operator=(Queue<T> &&queue) {
        if (&queue != this) {
            clear();
            this->head = queue.head;//???
            this->size = queue.size;
            queue.head = nullptr;
            queue.size = 0;
        }
        return *this;
    }

    void push(const T& value) override{
        typename List<T>::Node *new_elem = new typename List<T>::Node(value);
        if (!this->size) {
            this->head = new_elem;
            tail = new_elem;
        } else {
            tail->next = new_elem;
            tail = tail->next;
        }
        this->size += 1;
    }

    int get_tail() const {
        return tail->value;
    }

    void clear() {
        while (this->size != 0) {
            this->pop();
            this->size -= 1;
        }
    }
private:
    typename List<T>::Node *tail;
};
#endif //LIST_TEMPLATES_QUEUE_H
