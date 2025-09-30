#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include <stdexcept>

using namespace std;

// Constructor: O(1) for all cases
SortedBagIterator::SortedBagIterator(const SortedBag &b) : bag(b) {
    this->currentIndex = 0;
    this->currentFrequency = 1;
}

// getCurrent: Best O(1), Worst O(1), Average O(1)
TComp SortedBagIterator::getCurrent() {
    if (this->valid()) {
        return this->bag.array[this->currentIndex][0];
    }
    throw runtime_error("No such item");
}

// valid: Best O(1), Worst O(1), Average O(1)
bool SortedBagIterator::valid() {
    return this->currentIndex < this->bag.arrsize;
}

// next: Best O(1), Worst O(1), Average O(1)
void SortedBagIterator::next() {
    if (!this->valid()) {
        throw runtime_error("No such item");
    }

    if (this->currentFrequency < this->bag.array[this->currentIndex][1]) {
        this->currentFrequency++;
    } else {
        this->currentIndex++;
        this->currentFrequency = 1;
    }
}

// first: O(1) for all cases
void SortedBagIterator::first() {
    this->currentIndex = 0;
    this->currentFrequency = 1;
}
