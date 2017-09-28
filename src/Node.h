#pragma once
#include <iostream>
using namespace std;
class Node
{
public:
	Node* left;
	Node* right;
	Node();
	Node(unsigned char ch, int freq);
	void setFre(int freq);
	void setCh(unsigned char ch);
	int getFre() const;
	unsigned char getCh() const;
	bool operator>(const Node* pNode) const;
	~Node();

private:
	int freq;
	unsigned char ch;
};

