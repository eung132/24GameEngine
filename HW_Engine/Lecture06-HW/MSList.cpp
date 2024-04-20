#include "MSList.h"

MSList::MSList() : head(nullptr), size(0) {}

MSList::~MSList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void MSList::insert(const Star& star) {
    Node* newNode = new Node(star);
    newNode->next = head;
    head = newNode;
    size++;
}

int MSList::getSize() const {
    return size;
}

MSList::iterator MSList::begin() const {
    return iterator(head);
}

MSList::iterator MSList::end() const {
    return iterator(nullptr);
}
