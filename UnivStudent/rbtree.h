#ifndef _RBTREE_H
#define _RBTREE_H

#include "DB.hpp"

extern DB db;

enum coloring {
	red,
	black
};

struct node {
	int id;
	int value;
	enum coloring color;
	node * parent;
	node * left;
	node * right;
	node * rear;
	void DFT(node * n);
	void BFT(node * n);
	void printNode(node * n);
};

class rbtree
{
private:
	node * root;
	int numberOfNode;
	node * makeNewNode(int inputId, int inputValue);
	node * attach(node * target);
	void insert_case1(node * n);
	void insert_case2(node * n);
	void insert_case3(node * n);
	void insert_case4(node * n);
	void rotate_left(node * n);
	void rotate_right(node * n);
	void insert_case5(node * n);
	void delete_case1(node * n);
	void delete_case2(node * n);
	void delete_case3(node * n);
	void delete_case4(node * n);
	void delete_case5(node * n);
	void delete_case6(node * n);
	node * grandparent(node * n);
	node * uncle(node * n);
	node * sibling(node * n);
	
public:
	rbtree();
	node * search(int inputValue);
	node * search(int inputId, int inputValue);
	node * insertNode(int inputId, int inputValue);
	node * deleteNode(int inputValue);
	node * deleteNode(int inputId, int inputValue);
	node * smallest(node * n);
	node * smallest();
	node * biggest(node * n);
	void show_all();
	node * biggest();
	int getNumberOfNode();
	int getBh();
	int getBh(node * n);
	int getHeight();
	int getHeight(node * n);
};
#endif