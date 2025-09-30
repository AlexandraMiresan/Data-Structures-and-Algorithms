#include "SetIterator.h"

#include <exception>
#include <iterator>

#include "Set.h"

// Time complexity: Θ(1)
SetIterator::SetIterator(const Set &m) : set(m) {
    this->current = 0;
    advanceToNextValid();
}

// Time complexity: Θ(1)
void SetIterator::first() {
    this->current = 0;
    advanceToNextValid();
}

// Time complexity: Θ(1)
void SetIterator::next() {
    if (valid()) {
        current++;
        advanceToNextValid();
    } else {
        throw std::exception();
    }
}

// Best case: Θ(1)
// Worst case: Θ(n)
// Average case: O(n)
void SetIterator::advanceToNextValid() {
    while (this->current < this->set.tableSize &&
           this->set.elems[current] == NULL_TELEM || this->set.elems[current] == DELETED) {
        current++;
    }
}


// Time complexity: Θ(1)
TElem SetIterator::getCurrent() {
    if (valid()) {
        return this->set.elems[this->current];
    }
    else {
        throw std::exception();
    }
}

// Time complexity: Θ(1)
bool SetIterator::valid() const {
    if (this->set.isEmpty()) {
        return false;
    }
    if (this->current < this->set.tableSize) {
        return true;
    }
    return false;
}
