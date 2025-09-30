#include "Set.h"

#include <cstddef>
#include <stdexcept>

#include "SetITerator.h"

//Time complexity: Θ(n)
Set::Set() {
	this->tableSize = 117;
	this->currentSize = 0;
	this->elems = new TElem[this->tableSize];
	this->prime = this->findPrime();
	for(int i = 0; i < this->tableSize; i++) {
		this->elems[i] = NULL_TELEM;
	}
}

//Time complexity: Θ(n)
void Set::resize() {
	int oldSize = this->tableSize;
	TElem *oldTable = this->elems;

	this->tableSize *= 2;
	this->tableSize = nextPrime(this->tableSize);

	this->prime = this->findPrime();
	this->elems = new TElem[this->tableSize];
	this->currentSize = 0;

	for(int i = 0; i < this->tableSize; i++) {
		this->elems[i] = NULL_TELEM;
	}

	for(int i = 0; i < oldSize; i++) {
		if(oldTable[i] != NULL_TELEM && oldTable[i] != DELETED) {
			this->add(oldTable[i]);
		}
	}

	delete[] oldTable;
}

// Best case: Θ(1)
// Worst case: Θ(n)
// Average case: O(n)
bool Set::add(TElem elem) {
	if(isAlmostFull()) {
		resize();
	}
	if(search(elem)) {
		return false;
	}
	for(int i = 0; i < this->tableSize; i++) {
		int index = this->probe(elem, i);
		if(elems[index] == NULL_TELEM || elems[index] == DELETED) {
			this->elems[index] = elem;
			this->currentSize++;
			return true;
		}
	}
	return false;
}

// Best case: Θ(1)
// Worst case: Θ(n)
// Average case: O(n)
bool Set::remove(TElem elem) {

	for(int i = 0; i < this->tableSize; i++) {
		int index = this->probe(elem, i);
		if(index < 0 || index >= this->tableSize) {
			return false;
		}
		if(elems[index] == NULL_TELEM) {
			return false;
		}
		if(elems[index] == elem) {
			elems[index] = DELETED;
			this->currentSize--;
			return true;
		}
	}
	return false;
}

// Best case: Θ(1)
// Worst case: Θ(n)
// Average case: O(n)
bool Set::search(TElem elem) {
	for(int i = 0; i < this->tableSize; i++) {
		int index = this->probe(elem,i);
		if(elems[index] == NULL_TELEM) {
			return false;
		}
		if(elems[index] == elem) {
			return true;
		}
	}
	return false;
}

// Time complexity: Θ(1)
int Set::size() const {
	return this->currentSize;
}

// Time complexity: Θ(1)
bool Set::isEmpty() const {
	if(this->currentSize == 0) {
		return true;
	}
	return false;
}

// Time complexity: Θ(1)
Set::~Set() {
	delete[] this->elems;
}

// Time complexity: Θ(1)
SetIterator Set::iterator() const {
	return SetIterator(*this);
}


// Best case: Θ(n)
// Worst case: Θ(n^2)
// Average case: O(n)
void Set::intersection(Set &s) {
	SetIterator it = s.iterator();
	while(it.valid()) {
		TElem currentElem = it.getCurrent();
		it.next();
		if(!s.search(currentElem)) {
			this->remove(currentElem);
		}
	}
}


