#pragma once
#include "Node.h"
class HuffTree
{

public:
	HuffTree();
	HuffTree(const HuffTree& aTree);
	HuffTree& operator=(const HuffTree &aTree);
	HuffTree(char ch, int freq);
	HuffTree(HuffTree& tree1, HuffTree& tree2);
	~HuffTree();
	bool operator>(const HuffTree& aTree);
	void Traverse();
	void ClearTree();
	unsigned int GetEncoding(unsigned char ch) const;
	unsigned int GetEncodingBitsNum(unsigned char ch) const;
	void ResetCurrentNode();
	bool TryGetChar(unsigned int bit, unsigned char &result);
private:
	Node* root = NULL;
	Node* currentNode = NULL;
	unsigned short encoding[256];
	unsigned short encodingBitsNum[256];
	void deleteNode(Node* &pNode);
	void traverse(Node* &pNode, string bit);
	Node* copyTree(const Node* treePtr) const;
};
