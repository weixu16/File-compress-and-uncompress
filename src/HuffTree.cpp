#include "stdafx.h"
#include "HuffTree.h"
#include<string>

HuffTree::HuffTree()
{
	root = NULL;
	for (int i = 0; i < 256; i++)
	{
		encoding[i] = 0;
	}
	for (int i = 0; i < 256; i++)
	{
		encodingBitsNum[i] = 0;
	}
}

HuffTree::HuffTree(const HuffTree& aTree)
{
	this->root = NULL;
	*this = aTree;
	for (int i = 0; i < 256; i++)
	{
		encoding[i] = 0;
	}
	for (int i = 0; i < 256; i++)
	{
		encodingBitsNum[i] = 0;
	}
}

HuffTree& HuffTree::operator=(const HuffTree &aTree)
{
	if (this == &aTree)
	{
		return *this;
	}
	this->ClearTree();
	this->root = nullptr;
	root = copyTree(aTree.root);
	return *this;
}

Node* HuffTree::copyTree(const Node* treePtr) const
{
	Node* newTreePtr = nullptr;
	if (treePtr != nullptr)
	{
		newTreePtr = new Node();
		newTreePtr->setCh(treePtr->getCh());
		newTreePtr->setFre(treePtr->getFre());
		newTreePtr->right = copyTree(treePtr->right);
		newTreePtr->left = copyTree(treePtr->left);
	}
	return newTreePtr;
}

HuffTree::HuffTree(char ch, int freq)
{
	this->root= new Node(ch, freq);
}

HuffTree::HuffTree(HuffTree& leftTree, HuffTree& rightTree)
{
	int freOfLeftNode = leftTree.root->getFre();
	int freOfRightNode = rightTree.root->getFre();
	Node* newNode = new Node('\0',freOfLeftNode+freOfRightNode);
	this->root = newNode;
	newNode->left=this->copyTree(leftTree.root);
	newNode->right=this->copyTree(rightTree.root);
}

bool HuffTree::operator>(const HuffTree& aTree)
{
	return (this->root->getFre() > aTree.root->getFre());
}

void HuffTree::traverse(Node* &pNode, string bit)
{
	if ((pNode->left == NULL)&&(pNode->right == NULL))
	{
		int bitToInt = 0;
		for (unsigned int i = 0; i < bit.size(); i++)
		{
			if (bit[i] != '0')
			{
				bitToInt += (int) pow(2, bit.size()-i-1);
			}
		}
		encoding[pNode->getCh()] = bitToInt;
		encodingBitsNum[pNode->getCh()] =(unsigned short) bit.size();
		//cout << pNode->getCh() << '\t' << bitToInt << '\t' << bit << '\t'<< encodingBitsNum[pNode->getCh()]<<endl;
	}
	else
	{
		if (pNode->left != NULL)
		{
			traverse(pNode->left, bit + "0");
		}
		if (pNode->right != NULL)
		{
			traverse(pNode->right, bit + "1");
		}
	}
}

void HuffTree::Traverse()
{
	this->traverse(root, "");
}

unsigned int HuffTree::GetEncoding(unsigned char ch) const
{
	return this->encoding[ch];
}

unsigned int HuffTree::GetEncodingBitsNum(unsigned char ch) const
{
	return this->encodingBitsNum[ch];
}

void HuffTree::ResetCurrentNode()
{
	this->currentNode = this->root;
}

void HuffTree::deleteNode(Node* &pNode)
{
	if (pNode == nullptr)
	{
		return;
	}
	if (pNode->left!= nullptr)
	{
		deleteNode(pNode->left);
	}
	if (pNode->right != nullptr)
	{
		deleteNode(pNode->right);
	}
	delete pNode;
	pNode = nullptr;
}

void HuffTree::ClearTree()
{
	this->deleteNode(root);
}

HuffTree::~HuffTree()
{
	this->ClearTree();
}

bool HuffTree::TryGetChar(unsigned int bit, unsigned char &result)
{
	if (bit == 0)
	{
		this->currentNode = this->currentNode->left;
	}
	else
	{
		this->currentNode = this->currentNode->right;
	}

	// check wheter it is leaf node
	if (this->currentNode->left == nullptr && this->currentNode->right == nullptr)
	{
		result = this->currentNode->getCh();

		// reset the current node
		this->currentNode = this->root;
		return true;
	}

	// otherwise return falses
	return false;
}


