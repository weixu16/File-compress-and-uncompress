#include "stdafx.h"
#ifndef PRIORITYQUEUE_CPP
#define PRIORITYQUEUE_CPP
#include "PriorityQueue.h"

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
}

template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
}

template<class ItemType>
void PriorityQueue<ItemType>::Insert(ItemType anItem)
{
	pq.Add(anItem);
}

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const
{
	return (pq.getCount == 0);
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::Remove() throw (exception)
{
	if (pq.getCount() == 0)
	{
		throw exception();
	}
	ItemType anItem;
	pq.Remove(anItem);
	return anItem;
}
template<class ItemType>
int PriorityQueue<ItemType>::Size()
{
	return pq.getCount();
}
#endif