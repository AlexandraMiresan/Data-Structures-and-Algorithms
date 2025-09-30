#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;

// Time complexity: Θ(1)
MapIterator::MapIterator(Map& d) : map(d)
{
	this->head = this->map.head;
	this->current = this->head;
}

// Time complexity: Θ(1)
void MapIterator::first() {
	this->head = this->map.head;
	this->current = this->head;
}

// Time complexity: Θ(1)
void MapIterator::next() {
	if(this->valid()) {
		this->current = this->map.next[this->current];
	}else {
		throw std::exception();
	}
}

// Time complexity: Θ(1)
TElem MapIterator::getCurrent(){
	if(valid()) {
		return this->map.elems[this->current];
	}else {
		throw std::exception();

	}
}

// Time complexity: Θ(1)
bool MapIterator::valid() const {
	if(this->head == NULL_TVALUE)
		return false;
	if(this->current == NULL_TVALUE)
		return false;
	return true;
}


// Best case: Θ(1)
// Worst case: Θ(n)
// Average case: O(n)
TElem MapIterator::remove() {
	if(!this->valid()) {
		throw std::exception();
	}
	int currentTemp = this->head;
	int prev = -1;
	while(currentTemp != this->current) {
		prev = currentTemp;
		currentTemp = this->map.next[currentTemp];
	}
	if(prev != -1) {
		this->map.next[prev] = this->map.next[this->current];
	}
	TElem temp = this->map.elems[this->current];
	this->map.elems[this->current] = NULL_TELEM;
	this->current = this->map.next[this->current];
	this->map.next[this->current] = this->map.firstEmpty;
	this->map.firstEmpty = currentTemp;
	this->map.count--;

	return temp;
}



