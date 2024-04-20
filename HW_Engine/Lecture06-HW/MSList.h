#ifndef MSLIST_H
#define MSLIST_H

#include "Star.hpp"

class MSList {
private:
    struct Node {
        Star data;
        Node* next;
        Node(const Star& star) : data(star), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    class iterator {
    private:
        Node* current;

    public:
        iterator(Node* node) : current(node) {}

        Star& operator*() const {
            return current->data;
        }

        iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
    };

    MSList();
    ~MSList();

    void insert(const Star& star);
    int getSize() const;
    iterator begin() const;
    iterator end() const;
};

#endif // MSLIST_H
