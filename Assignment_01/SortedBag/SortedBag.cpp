#include "SortedBag.h"
#include "SortedBagIterator.h"

// Constructor: O(1) for all cases
SortedBag::SortedBag(Relation r) {
    this->r = r;
    this->arrsize = 0;
    this->capacity = 100;
    this->array = new TElem *[this->capacity];
    for (int i = 0; i < capacity; i++)
        this->array[i] = new TElem[2];
}

// Resize: Best O(n), Worst O(n), Average O(n)
void SortedBag::resize() {
    TElem **newarray = new TElem *[this->capacity*2];
    for (int i = 0; i < this->capacity*2; i++) {
        newarray[i] = new TElem[2];
    }
    for (int i = 0; i < this->capacity; i++) {
        newarray[i][0] = this->array[i][0];
        newarray[i][1] = this->array[i][1];
    }

    for (int i = 0; i < this->capacity; i++) {
        delete[] this->array[i];
    }
    delete[] this->array;

    this->array = newarray;
    this->capacity *= 2;
}

// Add: Best O(1), Worst O(n), Average O(n)
void SortedBag::add(TComp e) {
    if (this->arrsize == this->capacity) {
        resize();
    }
    if (this->arrsize == 0) {
        this->array[0][0] = e;
        this->array[0][1] = 1;
        this->arrsize++;
    } else {
        for (int i = 0; i < this->arrsize; i++)
            if (e == this->array[i][0]) {
                this->array[i][1]++;
                return;
            }
        int i = 0;
        for (i = 0; i < this->arrsize; i++)
            if (r(e, this->array[i][0]))
                break;
        for (int j = this->arrsize - 1; j >= i; j--) {
            this->array[j + 1][0] = this->array[j][0];
            this->array[j + 1][1] = this->array[j][1];
        }
        this->array[i][0] = e;
        this->array[i][1] = 1;
        this->arrsize++;
    }
}

// Remove: Best O(1), Worst O(n), Average O(n)
bool SortedBag::remove(TComp e) {
    int pos = 0;
    bool found = false;
    for (int i = 0; i < this->arrsize; i++) {
        if (e == this->array[i][0]) {
            pos = i;
            found = true;
            break;
        }
    }
    if (!found) {
        return false;
    }
    if (this->array[pos][1] > 1) {
        this->array[pos][1]--;
        return true;
    }
    for (int j = pos; j < this->arrsize - 1; j++) {
        this->array[j][0] = this->array[j + 1][0];
        this->array[j][1] = this->array[j + 1][1];
    }

    this->array[this->arrsize - 1][0] = 0;
    this->array[this->arrsize - 1][1] = 0;
    this->arrsize--;

    return true;
}

// Search: Best O(1), Worst O(n), Average O(n)
bool SortedBag::search(TComp elem) const {
    for(int i = 0; i < this->arrsize; i++) {
        if (elem == this->array[i][0])
            return true;
    }
    return false;
}

// Number of Occurrences: Best O(1), Worst O(n), Average O(n)
int SortedBag::nrOccurrences(TComp elem) const {
    for (int i = 0; i < this->arrsize; i++) {
        if (elem == this->array[i][0])
            return this->array[i][1];
    }
    return 0;
}

// Size: Best O(n), Worst O(n), Average O(n)
int SortedBag::size() const {
    int sum_of_freq = 0;
    for(int i = 0; i < this->arrsize; i++) {
        sum_of_freq += this->array[i][1];
    }
    return sum_of_freq;
}

// isEmpty: O(1) for all cases
bool SortedBag::isEmpty() const {
    return this->arrsize == 0;
}

// Iterator: O(1) for all cases
SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}

// Destructor: Best O(n), Worst O(n), Average O(n)
SortedBag::~SortedBag() {
    for(int i = 0; i < this->capacity; i++)
        delete[] this->array[i];
    delete[] this->array;
}

//removes all elements from the SortedBag
// Empty: O(n) for all cases
void SortedBag::empty() {
    this->arrsize = 0;
    for(int i = 0; i < this->capacity; i++) {
        this->array[i][0] = 0;
        this->array[i][1] = 0;
    }
}