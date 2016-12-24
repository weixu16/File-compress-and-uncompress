#pragma once
#ifndef HEAP_H
#define HEAP_H
#include<iostream>
#include<vector>
#include <string>
using namespace std;

template<class ItemType>
class Heap
{
	template<class friendItemType>
	friend ostream& operator<<(ostream &outStream, const Heap<friendItemType> &myHeap);

public:
	Heap();
	Heap(vector<ItemType> input);
	~Heap();
	void Add(ItemType anItem);
	bool Peek(ItemType &anItem) const;
	bool Remove(ItemType &anItem);
	int getCount() const;

private:
	vector<ItemType> aHeap;
	int count=0;
	void percolateDown(int position);
	void heapify();
};

#include"Heap.cpp"
#endif