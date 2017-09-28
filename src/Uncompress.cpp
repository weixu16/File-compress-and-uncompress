// Uncompress.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HuffTree.h"
#include "PriorityQueue.h"
#include "Heap.h"
#include "Node.h"
#include "CharCount.h"
#include "BitReader.h"
#include <fstream>
#include <iostream>


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: fileName" << endl;
		return -1;
	}
	
	string fileName = string(argv[1]);
	ifstream inputStream(fileName, ios::in|ios::binary);
	CharCount chReader;
	chReader.ReadFromFile(inputStream);

	PriorityQueue<HuffTree> pq;

	for (int i = 0; i < 256; i++)
	{
		unsigned char ch = (unsigned char)i;
		int a = chReader.getCharCount(ch);
		if (a != 0)
		{
			HuffTree tree(ch, a);
			pq.Insert(tree);
		}
	}

	while (pq.Size() > 1)
	{
		HuffTree h1 = pq.Remove();
		HuffTree h2 = pq.Remove();
		HuffTree h3(h1, h2);
		pq.Insert(h3);
	}
	HuffTree finalTree = pq.Remove();

	finalTree.Traverse();

	int numberOfSymbols = chReader.getTotalCharNumber();

	BitReader bitReader(&inputStream);

	int currentNumOfSymbols = 0; 
	finalTree.ResetCurrentNode();

	int numberOfBitsRead = 0;
	string compressedFileName = fileName + ".puf";
	ofstream outputFile;
	outputFile.open(compressedFileName, ios::out|ios::binary);
	while (currentNumOfSymbols < numberOfSymbols)
	{
		numberOfBitsRead++;
		unsigned int bit = bitReader.ReadBit();
		unsigned char currentChar;
		if (finalTree.TryGetChar(bit, currentChar))
		{
			outputFile.write((char*)&currentChar, sizeof(char));
			//cout << currentChar;
			currentNumOfSymbols++;
		}
	}

    return 0;
}

