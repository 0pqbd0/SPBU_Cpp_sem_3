#ifndef LIST_TEMPLATES_STACK_H
#define LIST_TEMPLATES_STACK_H

#include "List.h"

template<typename T>
class Stack : public List<T> {
public:
    Stack() : List<T>() {};

    Stack(const Stack<T> &first) : List<T>(first) {};

    ~Stack() = default;

    Stack(Stack<T> &&copy) {
        this->size = copy.size;
        copy.size = 0;
        this->head = copy.head;
        copy.head = nullptr;
    }

    Stack& operator = (Stack&& stack) {
        if (&stack != this) {
            while (this->head != nullptr) {
                typename List<T>::Node *current = this->head;
                this->head = this->head->next;
                delete current;
            }
            this->head = stack.head;
            stack.head = nullptr;
        }
        return *this;
    }

    /*    Stack& operator = (List& list) {
        Stack stack = dynamic_cast<Stack&> (list);
        if (&list != this) {
            while (head != nullptr) {
                Node *current = head;
                head = head->next;
                delete current;
            }
            head = list.get_front();
            list.head = nullptr;
        }
        return *this;
    }*/

    Stack &operator=(const Stack &first) {   //using List::operator=; ???
        List<T>::operator=(first);
        return *this;
        /*        if (this != (&first)) {
            while (head != nullptr) {
                Node *current = head;
                head = head->next;
                delete current;
            }
            Node* current = first.head;
            push(current->value);
            current = current->next;
            Node* old_head = head;
            Node* new_head = head;
            while (current != nullptr) {
                push(current->value);
                old_head->next = head;
                head->next = nullptr;
                head = new_head;
                old_head = old_head->next;
                current = current->next;
            }
        }*/
    }
};
#endif //LIST_TEMPLATES_STACK_H
