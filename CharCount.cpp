#include "stdafx.h"
#include "CharCount.h"
#include <fstream>

CharCount::CharCount()
{
	for (int i = 0; i < 256; i++)
	{
		symbolFrequency[i] = 0;
	}
	this->totalCharNumber = 0;
}
CharCount::CharCount(string fileName)
{
	this->fileName = fileName;
	for (int i = 0; i < 256; i++)
	{
		symbolFrequency[i] = 0;
	}
	this->totalCharNumber = 0;
}

int CharCount::getCharCount(unsigned char ch)
{
	return symbolFrequency[ch];
}

int CharCount::getTotalCharNumber()
{
	totalCharNumber = 0;
	for (int i = 0; i < 256; i++)
	{
		totalCharNumber += symbolFrequency[i];
	}
	return totalCharNumber;
}


CharCount::~CharCount()
{
}

void CharCount::CountChars()
{
	unsigned char *ch = new unsigned char;
	ifstream inputFileStream(fileName, ios::in|ios::binary);
	while (inputFileStream.read((char*)ch, 1))
	{
		symbolFrequency[*ch]++;
	}
	delete ch;
	inputFileStream.close();
	//for (int i = 0; i < 256; i++)
	//{
	//	cout<< (unsigned char)i <<":"<<symbolFrequency[i]<<endl;
	//}
}

void CharCount::WriteToFile(ostream *myFile)
{
	for (int i = 0; i < 256; i++)
	{
		*myFile << symbolFrequency[i] << endl;
	}
    this->totalCharNumber = 0;
	for (int i = 0; i < 256; i++)
	{
		this->totalCharNumber += symbolFrequency[i];
	}
	*myFile << this->totalCharNumber << endl;
}

void CharCount::ReadFromFile(istream &myFile)
{
	for (int i = 0; i < 256; i++)
	{
		//unsigned short frequency = 0;
		// myFile.read((char*)&frequency, sizeof(unsigned short
		string line;
		getline(myFile, line);
		this->symbolFrequency[i] = stoi(line);
	}
	//myFile.read(reinterpret_cast<char *>(&this->totalCharNumber), sizeof(this->totalCharNumber));
	string line;
	getline(myFile, line);
	this->totalCharNumber = stoi(line);
}
