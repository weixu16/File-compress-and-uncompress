#pragma once
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Heap.h"
#include <iostream>
#include <exception>
using namespace std;

template<class ItemType>
class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();
	void Insert(ItemType anItem);
	bool isEmpty() const;
	ItemType Remove() throw (exception);
	int Size();

private:
	Heap<ItemType> pq;
};

#include "PriorityQueue.cpp"
#endif