#include <iostream>
#include <cstdlib>
#include "rbtree.h"

using namespace std;

rbtree::rbtree() {
	this->numberOfNode = 0;
	this->root = NULL;
}

node* rbtree::search(int inputValue) {
	struct node* temp = this->root;
	while (temp != NULL) {
		if (temp->value > inputValue && temp->left != NULL)
			temp = temp->left;
		else if (temp->value < inputValue && temp->right != NULL)
			temp = temp->right;
		else if (temp->value == inputValue)
			return temp;
		else
			return NULL;
	}
	return NULL;
}

node* rbtree::search(int inputId, int inputValue) {
	struct node* temp = this->root;
	while (temp != NULL) {
		if (temp->value > inputValue && temp->left != NULL)
			temp = temp->left;
		else if (temp->value < inputValue && temp->right != NULL)
			temp = temp->right;
		else if (temp->value == inputValue)
			break;
		else
			temp = NULL;
	}

	while (temp != NULL) {
		if (temp->id == inputId)
			break;
		else if (temp->id != inputId && temp->rear != NULL)
			temp = temp->rear;
		else
			temp = NULL;
	}

	return temp;
}

node * rbtree::grandparent(node * n) {
	if ((n != NULL) && (n->parent != NULL))
		return n->parent->parent;
	else
		return NULL;
}

node * rbtree::uncle(node * n) {
	struct node * g = this->grandparent(n);
	if (g == NULL)
		return NULL;
	
	if (n->parent == g->left)
		return g->right;
	else
		return g->left;
}

node * rbtree::sibling(node * n) {
	if (n == n->parent->left)
		return n->parent->right;
	else
		return n->parent->left;
}

node* rbtree::makeNewNode(int inputId, int inputValue){
	node* temp = new node;
	temp->id = inputId;
	temp->value = inputValue;
	temp->color = red;
	temp->parent = NULL;
	temp->left = NULL;
	temp->right = NULL;
	temp->rear = NULL;

	return temp;
}

node * rbtree::attach(node* target) {

	struct node* rootNode = this->root;
	if (rootNode == NULL) {
		this->root = target;
		return target;
	}
	while (true) {
		if (rootNode->value > target->value) {
			if (rootNode->left == NULL) {
				rootNode->left = target;
				target->parent = rootNode;
				return target;
			}
			else
				rootNode = rootNode->left;
		}
		else if (rootNode->value < target->value) {
			if (rootNode->right == NULL) {
				rootNode->right = target;
				target->parent = rootNode;
				return target;
			}
			else
				rootNode = rootNode->right;
		}
		else if (rootNode->value == target->value) {
			if (rootNode->rear != NULL)
				rootNode = rootNode->rear;
			else
				rootNode->rear = target;
			return NULL;
		}
	}
}

void rbtree::insert_case1(node * n) {
	if (n->parent == NULL)
		n->color = black;
	else
		insert_case2(n);
}

void rbtree::insert_case2(node * n) {
	if (n->parent->color == black)
		return;
	else
		insert_case3(n);
}

void rbtree::insert_case3(node * n) {
	node * u = this->uncle(n), *g;

	if ((u != NULL) && (u->color == red)) {
		n->parent->color = black;
		u->color = black;
		g = this->grandparent(n);
		g->color = red;
		this->insert_case1(g);
	}
	else {
		this->insert_case4(n);
	}
}

void rbtree::insert_case4(node * n) {
	node * g = this->grandparent(n);

	if ((n == n->parent->right) && (n->parent == g->left)) {
		this->rotate_left(n->parent);
		n = n->left;
	}
	else if ((n == n->parent->left) && (n->parent == g->right)) {
		this->rotate_right(n->parent);
		n = n->right;
	}
	this->insert_case5(n);
}

void rbtree::rotate_left(node * n) {
	node* y = n->right;
	n->right = y->left;
	
	if (y->left != NULL)
		y->left->parent = n;
	y->parent = n->parent;

	if (n->parent == NULL) {
		this->root = y;
	}
	else if (n == n->parent->left) {
		n->parent->left = y;
	}
	else {
		n->parent->right = y;
	}

	y->left = n;
	n->parent = y;

}

void rbtree::rotate_right(node * n) {
	node* y = n->left;
	n->left = y->right;

	if (y->right != NULL)
		y->right->parent = n;
	y->parent = n->parent;

	if (n->parent == NULL) {
		this->root = y;
	}
	else if (n == n->parent->right) {
		n->parent->right = y;
	}
	else {
		n->parent->left = y;
	}

	y->right = n;
	n->parent = y;

}

void rbtree::insert_case5(node * n) {
	struct node * g = this->grandparent(n);

	n->parent->color = black;
	g->color = red;

	if (n == n->parent->left)
		this->rotate_right(g);
	else
		this->rotate_left(g);
}

node* rbtree::insertNode(int inputId, int inputValue) {
	struct node* temp=NULL;

	temp = this->makeNewNode(inputId, inputValue);
	temp = this->attach(temp);
	this->numberOfNode++;
	if (temp != NULL) {
		this->insert_case1(temp);
	}

	return temp;
}

bool is_leaf(node* n) {
	if (n->left == NULL && n->right == NULL)
		return true;
	else
		return false;
}

void rbtree::delete_case1(node * n) {
	if (n->parent != NULL)
		this->delete_case2(n);
}

void rbtree::delete_case2(node* n) {
	node* s = this->sibling(n);

	if (s->color == red) {
		n->parent->color = red;
		s->color = black;
		if (n == n->parent->left)
			this->rotate_left(n->parent);
		else
			this->rotate_right(n->parent);
	}
	delete_case3(n);
}

void rbtree::delete_case3(node * n) {
	node* s = sibling(n);

	if ((n->parent->color == black) && (s->color == black)
		&& (s->left->color == black) && (s->right->color == black)) {
		s->color = red;
		this->delete_case1(n->parent);
	}
	else {
		this->delete_case4(n);
	}
}

void rbtree::delete_case4(node * n) {
	node * s = this->sibling(n);
	if (s == NULL)
		return;
	/*
	if ((n->parent->color == red) && (s->color == black)
	&& ((s->left->color == black)||(s->left == NULL)) && ((s->right->color == black)||(s->right==NULL))) {
	s->color = red;
	n->parent->color = black;
	}*/
	if (n->parent->color == red){
		if (s->color == black) {
			if (s->left == NULL) {
				if (s->right == NULL){
					s->color = red;
					n->parent->color = black;
				}
				else if (s->right->color == black) {
					s->color = red;
					n->parent->color = black;
				}
			}
			else if (s->left->color == black) {
				if (s->right == NULL){
					s->color = red;
					n->parent->color = black;
				}
				else if (s->right->color == black) {
					s->color = red;
					n->parent->color = black;
				}
			}
		}
	}
	else {
		this->delete_case5(n);
	}
}

void rbtree::delete_case5(node * n) {
	struct node * s = this->sibling(n);

	if (s->color == black) {
		if ((n == n->parent->left) && (s->right->color == black)
			&& (s->left->color == red)) {
			s->color = red;
			s->left->color = black;
			this->rotate_right(s);
		}
		else if ((n == n->parent->right) && (s->left->color == black)
			&& (s->right->color == red)) {
			s->color = red;
			s->right->color = black;
			this->rotate_left(s);
		}
	}
	this->delete_case6(n);
}

void rbtree::delete_case6(node* n) {
	node * s = this->sibling(n);

	s->color = n->parent->color;
	n->parent->color = black;

	if (n == n->parent->left) {
		s->right->color = black;
		this->rotate_left(n->parent);
	}
	else {
		s->left->color = black;
		this->rotate_right(n->parent);
	}
}

void node::DFT(node* n) {  
	if (n != NULL) {
		this->printNode(n);
		n->DFT(n->left);
		n->DFT(n->right);
	}
}

void node::BFT(node* n) {
	if (n != NULL) {
		n->BFT(n->left);
		this->printNode(n);
		n->BFT(n->right);
	}
}

node * rbtree::deleteNode(int inputValue) {
	node * z = this->search(inputValue);
	node * y;
	node * x;

	if (z == NULL)
		return NULL;
	
	if (z->left == NULL || z->right == NULL)
		y = z;
	else {
		y = z->right;
		while (y->left!=NULL) {
			y = y->left;
		}
	}

	if (y->left != NULL)
		x = y->left;
	else
		x = y->right;
	if (x != NULL) {
		x->parent = y->parent;

		if (y->parent == NULL)
			this->root = x;
		else if (y == y->parent->left) {
			y->parent->left = x;
		}
		else
			y->parent->right = x;

		if (y != z) {
			z->value = y->value;
			z->id = y->id;
		}
		if (y->color == black)
			this->delete_case1(x);
		delete y;
	}
	else {
		if (y->parent == NULL)
			this->root = x;
		else if (y == y->parent->left) {
			y->parent->left = x;
		}
		else if (y == y->parent->right)
			y->parent->right = x;

		if (y != z) {
			z->value = y->value;
			z->id = y->id;
		}

		delete y;
	}

	return x;
}

node * rbtree::deleteNode(int inputId, int inputValue) {
	node * z = this->search(inputValue);
	node * y;
	node * x;
	node * zf=z;

	if (z == NULL)
		return NULL;

	while (inputId != z->id && z->rear != NULL) {
		zf = z;
		z = z->rear;
	}

	if (z->id != inputId)
		return NULL;
	else if (z->id == inputId) {
    if(z->rear != NULL)
    {
		z->rear->parent = z->parent;
		z->rear->left = z->left;
		z->rear->right = z->right;
		z->rear->color = z->color;
		if (z->parent != NULL && z== z->parent->left)
			z->parent->left = z->rear;
		else if (z->parent != NULL && z == z->parent->right)
			z->parent->right = z->rear;
		if (z->left != NULL)
			z->left->parent = z->rear;
		if (z->right != NULL)
			z->right->parent = z->rear;

    }
    else
    {
      zf->rear = NULL;
    }
		delete z;
		this->numberOfNode--;
		return z->rear;
	}
	else if (zf != z) {
		if (z->rear != NULL)
			zf->rear = z->rear;
		else
			zf->rear = NULL;
		delete z;
		this->numberOfNode--;
		return zf;
	}

	if (z == NULL)
		return NULL;

	if (z->left == NULL || z->right == NULL)
		y = z;
	else {
		y = z->right;
		while (y->left != NULL) {
			y = y->left;
		}
	}

	if (y->left != NULL)
		x = y->left;
	else
		x = y->right;
	if (x != NULL) {
		x->parent = y->parent;

		if (y->parent == NULL)
			this->root = x;
		else if (y == y->parent->left) {
			y->parent->left = x;
		}
		else
			y->parent->right = x;

		if (y != z) {
			z->value = y->value;
			z->id = y->id;
		}
		if (y->color == black)
			this->delete_case1(x);
		this->numberOfNode--;
		delete y;
	}
	else {
		if (y->parent == NULL)
			this->root = x;
		else if (y == y->parent->left) {
			y->parent->left = x;
		}
		else if (y == y->parent->right)
			y->parent->right = x;

		if (y != z) {
			z->value = y->value;
			z->id = y->id;
		}
		this->numberOfNode--;
		delete y;
	}
	return x;
}

node * rbtree::smallest(node* n) {
	struct node* temp = NULL;
	if (n == NULL) {
		return NULL;
	}
	else {
		temp = n;
	}
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

node * rbtree::smallest() {
	struct node* temp = this->root;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

node* rbtree::biggest(node* n) {
	struct node* temp = n;
	if (n == NULL) {
		return NULL;
	}

	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

void rbtree::show_all() {
	if (this->root != NULL) {
		this->root->BFT(this->root);
	}
}

node* rbtree::biggest() {
	struct node* temp = this->root;
	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

void node::printNode(node* n) {
  /*
	cout << "colorn: ";
	if (n->color == red)
		cout << "red";
	else
		cout << "black";
	cout << "\tid: " << n->id;
	cout << "\tvalue: " << n->value << endl;
*/
  db.AllStudent[n->id].Print();

	if (n->rear != NULL)
		n->printNode(n->rear);
}

int rbtree::getNumberOfNode() {
	return this->numberOfNode;
}

int rbtree::getBh() {
	int counter = 0;
	node * temp = this->root;
	while (temp != NULL) {
		counter++;
		temp = temp->left;
	}
	return counter;
}

int rbtree::getBh(node * n) {
	int counter = 0;
	node * temp = this->root;
	while (temp != NULL) {
		counter++;
		temp = temp->left;
	}

	return counter;
}

int rbtree::getHeight(node * n){
	int counter=0;
	int counter1 = 0;

	if (n == NULL)
		return 1;
	else {
		counter = getHeight(n->left)+1;
		counter1 = getHeight(n->right)+1;
		if (counter < counter1)
			return counter1;
	}

	return counter;
}

int rbtree::getHeight() {
	if (this->root != NULL)
		return this->getHeight(this->root);
	else
		return 0;
}

/*
int main() {
	rbtree* rbtreeTest = new rbtree();
	int i;

	for (i = 0; i < 10; i++) {
		rbtreeTest->insertNode(i, rand());
	}

	rbtreeTest->insertNode(i, 41);

	rbtreeTest->show_all();

	cout << rbtreeTest->getBh() << endl;

	rbtreeTest->deleteNode(0,41);
	
	rbtreeTest->deleteNode(153);
	rbtreeTest->deleteNode(7711);
	rbtreeTest->deleteNode(16827);
	rbtreeTest->deleteNode(11478);
	rbtreeTest->deleteNode(19912);
	

	rbtreeTest->show_all();
	cout << rbtreeTest->getBh() << endl;

	getchar();
}
*/