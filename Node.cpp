#include "stdafx.h"
#include "Node.h"


Node::Node()
{
}

Node::Node(unsigned char ch, int freq)
{
	this->ch = ch;
	this->freq = freq;
	this->left = NULL;
	this->right = NULL;
}

Node::~Node()
{
}

int Node::getFre() const
{
	return this->freq;
}

unsigned char Node::getCh() const
{
	return this->ch;
}

void Node::setFre(int freq)
{
	this->freq = freq;
}

void Node::setCh(unsigned char ch)
{
	this->ch = ch;
}

bool Node::operator>(const Node* pNode) const
{
	return this->freq > pNode->freq;
}