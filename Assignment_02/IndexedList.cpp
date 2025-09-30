#include <exception>

#include "IndexedList.h"

#include <stdexcept>

#include "ListIterator.h"


IndexedList::IndexedList() {
    this->head = nullptr;
}

// Time Complexity: Θ(1)
int IndexedList::size() const {
    return countElem;
}

// Time Complexity: Θ(1)
bool IndexedList::isEmpty() const {
    if(this->head == nullptr)
        return true;

    return false;
}


// Best Case: Θ(1), when pos == 0
// Worst Case: Θ(n)
// Overall : O(n)
TElem IndexedList::getElement(int pos) const {
    if(pos < 0 || pos >= this->size())
        throw std::exception();
    PNode p = this->head;
    for(int i = 0; i < this->size(); i++) {
        if(pos == i)
            return p->data;
        p = p->next;
    }

}

// Best Case: Θ(1), when pos == 0
// Worst Case: Θ(n)
// Overall: O(n)
TElem IndexedList::setElement(int pos, TElem e) {
    if(pos < 0 || pos >= this->size())
        throw std::exception();
    PNode p = this->head;
    for(int i = 0; i < this->size(); i++) {
        if(pos == i) {
            p->data = e;
            return i;
        }

        p = p->next;
    }

}

// Best Case: Θ(1), when the list is empty
// Worst Case: Θ(n), when traversing to the end
// Overall: O(n)
void IndexedList::addToEnd(TElem e) {
    if(this->head == nullptr) {
        PNode p = new SLLNode(e, nullptr);
        this->head = p;
        countElem++;
        return;
    }
    PNode p = this->head;
    for(int i = 0; i < this->size() - 1; i++) {
        p = p->next;
    }
    PNode p2 = new SLLNode(e, nullptr);
    p->next = p2;
    countElem++;
}

// Best Case: Θ(pos), when pos is the first in list
// Worst Case: Θ(pos), when inserting near the end
// Overall: Θ(pos)
void IndexedList::addToPosition(int pos, TElem e) {
    if (pos < 0 || pos >= this->size())
        throw std::exception();

    PNode h = this->head;
    if(pos == 0) {
        PNode p = new SLLNode(e, nullptr);
        p->next = h;
        this->head = p;
        countElem++;
        return;
    }
    for(int i = 0; i < this->size() - 1; i++) {
        if(pos == i + 1) {
            PNode p2 = new SLLNode(e, nullptr);
            p2->next = h->next;
            h->next = p2;
            countElem++;
            return;
        }

        h = h->next;
    }
    if(pos == this->size()) {
        addToEnd(e);
    }
}

// Best Case: Θ(1), when pos is the first in list
// Worst Case: Θ(n), when removing the last element
// Overall: O(n)
TElem IndexedList::remove(int pos) {
    if(pos < 0 || pos >= this->size())
        throw std::exception();
    PNode h = this->head;
    PNode p = nullptr;
    TElem copy;
    if(pos == 0) {
        copy = this->head->data;
        this->head = this->head->next;
        delete h;
        countElem--;
        return copy;
    }
    for(int i = 0; i < this->size() - 1; i++) {
        if(pos == i) {
            copy = h->data;
            p->next = h->next;
            delete h;
            countElem--;
            return copy;
        }
        p = h;
        h = h->next;
    }
    if(pos == this->size() - 1) {
        p->next = nullptr;
        copy = h->data;
        delete h;
        countElem--;
        return copy;
    }

    return NULL_TELEM;
}

// Best Case: Θ(1), when element is at head
// Worst Case: Θ(n)
// Overall: O(n)
int IndexedList::search(TElem e) const {
    PNode p = this->head;
    for(int i = 0; i < this->size(); i++) {
        if(p->data == e)
            return i;
        p = p->next;

    }
    return -1;
}

// Time Complexity: Θ(1)
ListIterator IndexedList::iterator() const {
    return ListIterator(*this);
}

// Time Complexity: Θ(n)
IndexedList::~IndexedList() {
    while(this->head != nullptr) {
        PNode p = this->head;
        head = this->head->next;
        delete p;
    }
}
