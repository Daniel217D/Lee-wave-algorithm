#pragma once

template<class Type>
class Node {
private:
    Type value;

    Node<Type> *next;

    template<typename> friend
    class Deque;

public:
    Node(Type _value, Node *_next = nullptr) : value(_value), next(_next) {
    }

    ~Node() {
        delete next;
    }

    Node *get_next() {
        return next;
    }

    Type get_value() {
        return value;
    }
};

template<class Type>
class Deque {
private:
    Node<Type> *node = nullptr;

public:
    ~Deque() {
        delete node;
    }

    bool IsEmpty() {
        return node == nullptr;
    }

    void PushBack(Type value) {
        if (IsEmpty()) {
            PushFront(value);
        } else {
            Node<Type> *current = node;

            while (current->next) {
                current = current->next;
            }

            current->next = new Node<Type>(value);
        }
    }

    Type PopBack() {
        Type value;

        if (node->next == nullptr) {
            value = node->value;

            node = nullptr;
            delete node;
        } else {
            Node<Type> *current = node;

            while (current->next->next) {
                current = current->next;
            }

            value = current->next->value;

            delete current->next;
            current->next = nullptr;
        }

        return value;
    }

    void PushFront(Type value) {
        node = new Node<Type>(value, node);
    }

    Type PopFront() {
        Type value = node->value;
        Node<Type> *temp = node;

        node = node->next;
        temp->next = nullptr;
        delete temp;

        return value;
    }

    Type Top() {
        return node->value;
    }
};
