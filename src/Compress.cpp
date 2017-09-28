// Compress.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HuffTree.h"
#include "PriorityQueue.h"
#include "Heap.h"
#include "Node.h"
#include "CharCount.h"
#include "BitWriter.h"
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

	CharCount chCounter(fileName);
	chCounter.CountChars();
	string compressedFileName = fileName + ".huf";
	ofstream outputFile;
	outputFile.open(compressedFileName, ios::out|ios::binary);
	chCounter.WriteToFile(&outputFile);

	PriorityQueue<HuffTree> pq;

	for (int i = 0; i < 256; i++)
	{
		unsigned char ch = (unsigned char)i;
		int a = chCounter.getCharCount(ch);
		if (a!= 0)
		{
			HuffTree tree(ch, a);
			pq.Insert(tree);
		}				
	}
	//HuffTree t1('a', 8);
	//HuffTree t2('b', 1);
	//HuffTree t3('c', 2);
	//HuffTree t4('d', 5);
	//HuffTree t5('e', 1);
	//HuffTree t6('f', 9);

	//pq.Insert(t1);
	//pq.Insert(t2);
	//pq.Insert(t3);
	//pq.Insert(t4);
	//pq.Insert(t5);
	//pq.Insert(t6);

	while (pq.Size() > 1)
	{
		HuffTree h1 = pq.Remove();
		HuffTree h2 = pq.Remove();
		HuffTree h3(h1,h2);
		pq.Insert(h3);
	}
	HuffTree finalTree = pq.Remove();
	
	finalTree.Traverse();

	int numberofBitsWrite = 0;
	BitWriter bitW(&outputFile);
	unsigned char *ch = new unsigned char;
	fstream inputStream(fileName, ios::in|ios::binary);
	while (inputStream.read((char*)ch, 1))
	{
		int bitsNum = finalTree.GetEncodingBitsNum(*ch);
		bitW.WriteBits(finalTree.GetEncoding(*ch), bitsNum);
		numberofBitsWrite += bitsNum;
	}
	bitW.Flush();
	delete ch;
	inputStream.close();
	outputFile.flush();
	outputFile.close();
    return 0;
}

