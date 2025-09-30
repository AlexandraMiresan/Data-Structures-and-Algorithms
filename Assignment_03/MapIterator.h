#pragma once
#include "Map.h"
class MapIterator
{
	//DO NOT CHANGE THIS PART
	friend class Map;
private:
	Map& map;
	int head;
	int current;

	MapIterator(Map& m);
public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
	TElem remove();
};


