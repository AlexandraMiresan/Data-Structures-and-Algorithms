#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111
#define DELETED -222222
typedef int TElem;
class SetIterator;

class Set {
    //DO NOT CHANGE THIS PART
    friend class SetIterator;

private:
    TElem *elems;
    int tableSize;
    int currentSize;
    int prime;

    //Time complexity: Θ(1)
    int hash1(int value) {
        int h = value % tableSize;
        return h < 0 ? h + tableSize : h;
    }

    //Time complexity: Θ(1)
    int hash2(int value) {
        int h = prime - (value % prime);
        return h < 0 ? h + prime : h;
    }

    //Time complexity: Θ(1)
    int probe(int key, int i) {
        return (hash1(key) + i * hash2(key)) % tableSize;
    }

    //Time complexity: Θ(1)
    bool isAlmostFull() {
        return (float)currentSize / tableSize > 0.7f;
    }

    //Best case: Θ(1)
    //Worst case: Θ(n)
    //Average case: O(n)
    int findPrime() {
        for (int i = tableSize - 1; i >= 2; i--) {
            if (isPrime(i)) {
                return i;
            }
        }
        return 2;
    }

    //Best case: Θ(1)
    //Worst case: Θ(sqrt(n))
    //Average case: O(sqrt(n))
    bool isPrime(int value) {
        if (value < 2) return false;
        for (int i = 2; i * i <= value; ++i)
            if (value % i == 0) return false;
        return true;
    }


    int nextPrime(int start) {
        while(!isPrime(start)) {
            start++;
        }
        return start;
    }

public:
    //implicit constructor
    Set();

    //adds an element to the set
    //returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
    bool add(TElem e);

    //removes an element from the set
    //returns true if e was removed, false otherwise
    bool remove(TElem e);

    //checks whether an element belongs to the set or not
    bool search(TElem elem);

    //returns the number of elements;
    int size() const;

    //check whether the set is empty or not;
    bool isEmpty() const;

    //return an iterator for the set
    SetIterator iterator() const;

    // destructor
    ~Set();

    void resize();

    void intersection(Set& s);
};
