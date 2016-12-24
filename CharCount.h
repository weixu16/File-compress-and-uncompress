#pragma once
#include <iostream>
#include <string>
using namespace std;
class CharCount
{
public:
	CharCount();
	CharCount(string fileName);
	~CharCount();
	void CountChars();
	int getCharCount(unsigned char ch);
	int getTotalCharNumber();
	void WriteToFile(ostream *myFile);
	void ReadFromFile(istream &myFile);
private:
	unsigned int symbolFrequency[256];
	string fileName;
	int totalCharNumber;
};

