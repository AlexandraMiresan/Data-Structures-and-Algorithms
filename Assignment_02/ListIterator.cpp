#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>
#include <stdexcept>

// Best Case: Θ(1)
// Worst Case: Θ(1)
// Average Case: Θ(1)
ListIterator::ListIterator(const IndexedList& list) : list(list){
    this->head = reinterpret_cast<PNode>(this->list.head);
    this->current = this->head;

}

// Best Case: Θ(1)
// Worst Case: Θ(1)
// Average Case: Θ(1)
void ListIterator::first(){
    this->head = reinterpret_cast<PNode>(this->list.head);
    this->current = this->head;
}

// Best Case: Θ(1)
// Worst Case: Θ(1)
// Average Case: Θ(1)
void ListIterator::next(){
    if(this->valid()) {
        this->current = this->current->next;
    }else {
        throw std::exception();
    }
}

// Best Case: Θ(1)
// Worst Case: Θ(1)
// Average Case: Θ(1)
bool ListIterator::valid() const{
    if(this->head == nullptr) {
        return false;
    }
    if(this->current == nullptr) {
        return false;
    }
	return true;
}

void ListIterator::jumpForward(int k) {
    if (!valid() || k <= 0)
        throw std::exception();

    for (int i = 0; i < k; i++) {
        if (this->current == nullptr) {
            break;
        }
        this->current = this->current->next;
    }
}

// Best Case: Θ(1)
// Worst Case: Θ(1)
// Average Case: Θ(1)
TElem ListIterator::getCurrent() const{
   if(valid()) {
       return this->current->data;
   }else {
       throw std::exception();

   }
	return NULL_TELEM;
}