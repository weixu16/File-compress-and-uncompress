#include "stdafx.h"
#ifndef HEAP_CPP
#define HEAP_CPP
#include "Heap.h"
#include <string>

template<class ItemType>
Heap<ItemType>::Heap()
{
	ItemType anItem;
	aHeap.push_back(anItem);
}

template<class ItemType>
Heap<ItemType>::Heap(vector<ItemType> input)
{
	aHeap.push_back(-1000);
	for (int i = 0; i < input.size(); i++)
	{
		aHeap.push_back(input[i]);
	}
	count = input.size();
	heapify();
}

template<class ItemType>
void Heap<ItemType>::heapify()
{
	for (int i = count / 2; i > 0; i--)
	{
		percolateDown(i);
	}
}

template<class ItemType>
Heap<ItemType>::~Heap()
{
}

template<class ItemType>
void Heap<ItemType>::Add(ItemType anItem)
{
	aHeap[0] = anItem;
	aHeap.push_back(anItem);
	count++;
	int position = count;
	while (aHeap[position / 2] > anItem)
	{
		swap(aHeap[position / 2], aHeap[position]);
		position = position / 2;
	}
}

template<class ItemType>
bool Heap<ItemType>::Peek(ItemType &anItem) const
{
	if (count == 0)
	{
		return false;
	}
	anItem = aHeap[1];
	return true;
}

template<class ItemType>
bool Heap<ItemType>::Remove(ItemType &anItem)
{
	if (count == 0)
	{
		return false;
	}
	anItem = aHeap[1];
	aHeap[1] = aHeap[count];
	aHeap.pop_back();
	count--;
	percolateDown(1);
	return true;
}

template<class ItemType>
void Heap<ItemType>::percolateDown(int position)
{
	int child = position * 2;
	if (child > count)
	{
		return;
	}
	if ((count != child) && (aHeap[child] > aHeap[child + 1]))
	{
		child++;
	}
	if (aHeap[position] > aHeap[child])
	{
		swap(aHeap[position], aHeap[child]);
		percolateDown(child);
	}
}

template<class ItemType>
int Heap<ItemType>::getCount() const
{
	return this->count;
}

template<class friendItemType>
ostream& operator<<(ostream &outStream, const Heap<friendItemType> &myHeap)
{
	for (int i = 1; i <= myHeap.count; i++)
	{
		outStream << "[" << i << "]: " << myHeap.aHeap[i] << endl;
	}
	return outStream;
}
#endif