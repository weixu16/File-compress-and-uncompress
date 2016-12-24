#pragma once
#include <iostream>
using namespace std;
class BitReader
{
public:
	BitReader();
	BitReader(istream *inStream);
	~BitReader();
	int getCount() const;
	void setStream(istream *inStream);
	unsigned int ReadBit();

private:
	istream *inStream;
	int count;
	unsigned char buf;
	int totalRead = 0;
};

