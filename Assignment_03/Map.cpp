#include "Map.h"

#include <stdlib.h>

#include "MapIterator.h"


// Time complexity: Θ(n)
Map::Map() {
    this->capacity = 100;
    this->elems = new TElem[this->capacity];
    this->next = new int[this->capacity];
    this->head = NULL_TVALUE;
    this->firstEmpty = 0;
    for (int i = 0; i < this->capacity; i++) {
        this->next[i] = i + 1;
        this->elems[i] = NULL_TELEM;
    }
    this->next[capacity - 1] = NULL_TVALUE;
    this->count = 0;
}

// Time complexity: Θ(n)
void Map::resize() {
    this->capacity *= 2;
    this->firstEmpty = capacity / 2;
    TElem *newElems = new TElem[this->capacity];
    int *newNext = new int[this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        newNext[i] = i + 1;
        newElems[i] = NULL_TELEM;
    }
    newNext[capacity - 1] = NULL_TVALUE;
    for (int i = 0; i < this->capacity / 2; i++) {
        newNext[i] = this->next[i];
        newElems[i] = this->elems[i];
    }
    this->elems = newElems;
    this->next = newNext;
}

// Best case: Θ(1)
// Worst case: Θ(n)
// Average case: O(n)
TValue Map::add(TKey c, TValue v) {
    if (this->count == this->capacity) {
        resize();
    }
    if (this->head == NULL_TVALUE) {
        this->head = this->firstEmpty;
        this->firstEmpty = this->next[this->firstEmpty];
        this->next[this->head] = NULL_TVALUE;
        this->elems[this->head] = TElem(c, v);
        this->count++;
        return NULL_TVALUE;
    }

    int current = this->head;
    while (this->next[current] != NULL_TVALUE) {
        if (this->elems[current].first == c) {
            TValue temp = this->elems[current].second;
            this->elems[current].second = v;
            return temp;
        }
        current = this->next[current];
    }
    if (this->elems[current].first == c) {
        TValue temp = this->elems[current].second;
        this->elems[current].second = v;
        return temp;
    }
    this->next[current] = this->firstEmpty;
    this->elems[this->firstEmpty] = TElem(c, v);
    int tempFirstEmpty = this->next[this->firstEmpty];
    this->next[this->firstEmpty] = NULL_TVALUE;
    this->firstEmpty = tempFirstEmpty;
    this->count++;
    return NULL_TVALUE;
}

// Best case: Θ(1)
// Worst case: Θ(n)
// Average case: O(n)
TValue Map::search(TKey c) const {
    if (this->head == NULL_TVALUE) {
        return NULL_TVALUE;
    }
    int current = this->head;
    while (this->next[current] != NULL_TVALUE) {
        if (this->elems[current].first == c) {
            return this->elems[current].second;
        }
        current = this->next[current];
    }
    if (this->elems[current].first == c) {
        return this->elems[current].second;
    }

    return NULL_TVALUE;
}

// Best case: Θ(1)
// Worst case: Θ(n)
// Average case: O(n)
TValue Map::remove(TKey c) {
    if (this->head == NULL_TVALUE) {
        return NULL_TVALUE;
    }
    if (this->count == 1) {
        if (this->elems[this->head].first == c) {
            TValue temp = this->elems[this->head].second;
            this->elems[this->head] = NULL_TELEM;
            this->next[this->head] = this->firstEmpty;
            this->firstEmpty = this->head;
            this->head = NULL_TVALUE;
            this->count--;
            return temp;
        }
    }

    if (this->elems[this->head].first == c) {
        int tempFirstEmpty = this->firstEmpty;
        TValue tempValue = this->elems[this->head].second;
        this->elems[this->head] = NULL_TELEM;
        this->firstEmpty = this->head;
        this->head = this->next[this->head];
        this->next[this->firstEmpty] = tempFirstEmpty;
        this->count--;
        return tempValue;
    }

    int current = this->head;
    int prev = -1;
    while (this->next[current] != NULL_TVALUE) {
        if (this->elems[current].first == c) {
            TValue temp = this->elems[current].second;
            this->elems[current] = NULL_TELEM;
            this->next[prev] = this->next[current];
            this->next[current] = this->firstEmpty;
            this->firstEmpty = current;
            this->count--;
            return temp;
        }
        prev = current;
        current = this->next[current];
    }
    if (this->elems[current].first == c) {
        TValue temp = this->elems[current].second;
        this->elems[current] = NULL_TELEM;
        this->next[prev] = this->next[current];
        this->next[current] = this->firstEmpty;
        this->firstEmpty = current;
        this->count--;
        return temp;
    }

    return NULL_TVALUE;
}

// Time complexity: Θ(1)
int Map::size() const {
    return count;
}

// Time complexity: Θ(1)
bool Map::isEmpty() const {
    if (this->count == 0) {
        return true;
    }
    return false;
}

// Time complexity: Θ(1)
MapIterator Map::iterator() {
    return MapIterator(*this);
}
