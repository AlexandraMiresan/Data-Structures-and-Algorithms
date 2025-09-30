#pragma once
#include "IndexedList.h"


class ListIterator{
    //DO NOT CHANGE THIS PART
	friend class IndexedList;
private:
	const IndexedList& list;
	struct SLLNode;
	typedef SLLNode* PNode;
	struct SLLNode {
		TElem data;
		PNode next;
		SLLNode(TElem e, PNode n);
	};
	PNode head;
	PNode current;
		
    ListIterator(const IndexedList& list);
public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;
	void jumpForward(int k);

};

