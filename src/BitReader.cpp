#include "stdafx.h"
#include "BitReader.h"


BitReader::BitReader()
{
	this->count = 0;
}


BitReader::~BitReader()
{
}

BitReader::BitReader(istream *inStream)
{
	this->inStream = inStream;
	this->count = 0;
}

int BitReader::getCount() const
{
	return count;
}
void BitReader::setStream(istream *inStream)
{
	this->inStream = inStream;
}

unsigned int BitReader::ReadBit()
{
	if (count == 8 || count == 0)
	{
		this->inStream->read((char*)(&buf), 1);
		//*(this->inStream) >> buf;
		totalRead += 8;
		count = 0;
	}
	unsigned mask = (unsigned)pow(2, 7);
	unsigned int result = 0;

	if (mask & buf)
	{
		result = 1;
	}
	buf = buf << 1;
	count++;
	return result;
}
