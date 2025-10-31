//============================================================================
// Name        : BST.cpp
// Author      : MEE
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstddef>
#include <iostream>
using namespace std;

// Create node
class Node{
public:
	int val;
	Node *left;
	Node *right;

	Node(int var) {
		val = var;
		left = right = nullptr;
	}
};

class BST {

public:
	Node *head;
	BST();
	Node * insert(int var, Node *node);
	Node* createNode(int var);
	bool search(int var, Node *node);
};

BST::BST(){head = nullptr;}

Node *BST::insert(int var, Node *node){
	//insert a node to the tree
	if (node == nullptr) { return new Node(var);} 

	//check if val is less than head -> go left
	if(var < node->val){
		 if (node->left) insert(var,node->left);
		 else node->left = new Node(var);
	}
	//if val greater -> go right
	else {
		if (node->right) insert(var,node->right); 
		else node->right = new Node(var);
	}
}

Node* BST::createNode(int var){
	Node *node = new Node(var);
	return node;
}

bool BST::search(int var, Node *node){
	//traverse tree from node
	if(node == nullptr) return false;

	if(node->val == var) return true;
	//look till no more children
	if ( search(var,node->left) ) return true;
	//compare val to var
	if ( search(var,node->right) ) return true;

	return false;
}

int main() {
	BST *bst = new BST();
	bst->head = bst->insert(10,bst->head);
	bst->insert(13,bst->head);
	bst->insert(20,bst->head);
	bst->insert(17,bst->head);
	bst->insert(2,bst->head);
	cout << bst->head->right->right->left->val << endl;

	cout << bst->search(17,bst->head);
	//bst->insert(10,bst->head);
	//cout << "Here?" << bst->head;
	return 0;
}
