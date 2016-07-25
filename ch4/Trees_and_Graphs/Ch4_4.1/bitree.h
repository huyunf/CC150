#include <iostream>
#include <list>
using namespace std;

class Node {
public:
	Node(int v, Node* l, Node* r, int h) :left(l), right(r), value(v), height(h) {}
	Node(int v);
	Node();
	~Node() {}

	bool setLeft(Node* l);
	bool setRight(Node* r);
	bool setValue(int v) { value = v; return true; }
	bool setHeight(int h) { height = h; return true; }

	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	int getValue() { return value; }
	int getHeight() { return height; }

private:
	Node* left;
	Node* right;
	int	  value;
	int   height;
};

bool Node::setLeft(Node* l)
{
	left = l;
	return true;
}

bool Node::setRight(Node* r)
{
	right = r;
	return true;
}

Node::Node()
{
	value = 0;
	left = NULL;
	right = NULL;
	height = 0;	// no value, no height
}

Node::Node(int v) :value(v)
{
	left = NULL;
	right = NULL;
	height = 1;
}

class BiTree
{
public:
	BiTree() :head(NULL) {}
	BiTree(Node* h):head(h){}

	Node* get_head() { return head; }

	int minDepth();

	// https://en.wikipedia.org/wiki/Tree_traversal
	void Preorder_Traversal();	// cur, left, right
	void Inorder_Traversal();	// left, cur, right
	void Postorder_Traversal();	// left, right, cur

	void insert(Node* n);
	void balance_insert(Node* n);

private:

	void recur_insert(Node* cur, Node* n);
	Node* recur_balance_insert(Node* cur, Node* n);
	void recur_inorder(Node* n);
	void recur_postorder(Node* n);

	Node* head;
};

// cur, left, right
void BiTree::Preorder_Traversal()
{
	if (NULL == head)
	{
		cout << "Empty Tree" << endl;
		return;
	}

	cout << "Preorder_Traversal" << endl;

	list<Node*> *l = new list<Node*>;

	l->push_back(head);

	while (l->size())
	{
		Node* cur = l->back();
		l->pop_back();

		cout << "v: " << cur->getValue() << " height: " << cur->getHeight() << endl;

		Node* right = cur->getRight();
		if (NULL != right) l->push_back(right);
		
		Node* left = cur->getLeft();
		if (NULL != left) l->push_back(left);
	}

	cout << "Preorder_Traversal" << endl << endl;
}

// left, cur, right
void BiTree::recur_inorder(Node* n)
{
	if (NULL == n)
	{
		return;
	}
	else
	{
		recur_inorder(n->getLeft());

		cout << "v: " << n->getValue() << " height: " << n->getHeight() << endl;

		recur_inorder(n->getRight());
	}
}

void BiTree::Inorder_Traversal()
{
	if (NULL == head)
	{
		cout << "Empty Tree" << endl;
		return;
	}

	cout << "Inorder_Traversal" << endl;

	Node* cur = head;

#if 0
	recur_inorder(cur);
#else
	list<Node*> *l = new list<Node*>;

	while (l->size()!=0 || cur!=NULL)
	{
		if(cur!=NULL)
		{
			l->push_back(cur);
			cur = cur->getLeft();
		}
		else
		{
			cur = l->back();
			l->pop_back();

			cout << "v: " << cur->getValue() << " height: " << cur->getHeight() << endl;

			cur = cur->getRight();
		}
	}
#endif
	cout << "Inorder_Traversal" << endl << endl;
	
}

// left, right, cur
void BiTree::recur_postorder(Node* n)
{
	if (NULL == n)
	{
		return;
	}
	else
	{
		recur_postorder(n->getLeft());

		recur_postorder(n->getRight());

		cout << "v: " << n->getValue() << " height: " << n->getHeight() << endl;
	}
}

void BiTree::Postorder_Traversal()
{
	if (NULL == head)
	{
		cout << "Empty Tree" << endl;
		return;
	}

	cout << "Postorder_Traversal" << endl;

	Node* cur = head;

	recur_postorder(cur);

	cout << "Postorder_Traversal" << endl << endl;
}

// min Depth
int mindep(Node* cur)
{
	if (cur == NULL)
		return 0;
	else
	{
		int ldp = mindep(cur->getLeft());
		int rdp = mindep(cur->getRight());

		return 1 + (ldp < rdp ? ldp : rdp);
	}
}

int BiTree::minDepth()
{
	return mindep(head);
}

// insert
void BiTree::recur_insert(Node* cur, Node* n)
{
	if (cur->getValue() > n->getValue()) // go left
	{
		if (cur->getLeft()) {
			recur_insert(cur->getLeft(), n);
		}
		else{
			cur->setLeft(n);
		}
	}
	else // go right
	{
		if (cur->getRight()) {
			recur_insert(cur->getRight(), n);
		}
		else {
			cur->setRight(n);
		}
	}

	// update height
	int lh = (cur->getLeft() != NULL) ? cur->getLeft()->getHeight() : 0;
	int rh = (cur->getRight() != NULL) ? cur->getRight()->getHeight() : 0;

	cur->setHeight((lh > rh ? lh : rh) + 1);
}

void BiTree::insert(Node* n)
{
	if (head == NULL)
	{
		head = n;
		head->setHeight(1);
		head->setLeft(NULL);
		head->setRight(NULL);
	}
	else
	{
		Node* cur = head;

		recur_insert(cur, n);
	}
}

// balance insert

// rotate right
/*
			n
		B	   T1
	C	  T2
D
*/
Node* rotate_right(Node* n)
{
	Node* B = n->getLeft();
	Node* T1 = n->getRight();
	Node* C = B == NULL ? NULL : B->getLeft();
	Node* T2 = B == NULL ? NULL : B->getRight();
	
	n->setLeft(T2);
	int lh = (T2 == NULL) ? 0 : T2->getHeight();
	int rh = (T1 == NULL) ? 0 : T1->getHeight();
	n->setHeight(lh > rh ? lh + 1 : rh + 1);

	B->setRight(n);
	lh = (C == NULL) ? 0 : C->getHeight();
	rh = (n == NULL) ? 0 : n->getHeight();
	n->setHeight(lh > rh ? lh + 1 : rh + 1);

	return B;
}

// rotate left

/*
		n
	T1		B	   
		T2		C	  
					D
*/
Node* rotate_left(Node* n)
{
	Node* B = n->getRight();
	Node* T1 = n->getLeft();
	Node* C = B == NULL ? NULL : B->getRight();
	Node* T2 = B == NULL ? NULL : B->getLeft();

	n->setRight(T2);
	int lh = (T1 == NULL) ? 0 : T1->getHeight();
	int rh = (T2 == NULL) ? 0 : T2->getHeight();
	n->setHeight(lh > rh ? lh + 1 : rh + 1);

	B->setLeft(n);
	lh = (n == NULL) ? 0 : n->getHeight();
	rh = (C == NULL) ? 0 : C->getHeight();
	n->setHeight(lh > rh ? lh + 1 : rh + 1);

	return B;
}

Node* BiTree::recur_balance_insert(Node* cur, Node* n)
{
	if (cur->getValue() > n->getValue()) // go left
	{
		if (cur->getLeft()) {
			cur->setLeft(recur_balance_insert(cur->getLeft(), n));
		}
		else {
			cur->setLeft(n);
		}
	}
	else // go right
	{
		if (cur->getRight()) {
			cur->setRight(recur_balance_insert(cur->getRight(), n));
		}
		else {
			cur->setRight(n);
		}
	}

	// update height
	int lh = (cur->getLeft() != NULL) ? cur->getLeft()->getHeight() : 0;
	int rh = (cur->getRight() != NULL) ? cur->getRight()->getHeight() : 0;

	cur->setHeight((lh > rh ? lh : rh) + 1);

	// need rotate?
	int balance = lh - rh;

	// decide rotate pattern
	// LL
	if (balance > 1 && cur->getLeft() && n->getValue() < cur->getLeft()->getValue())
	{
		return rotate_right(cur);
	}

	// LR
	if (balance > 1 && cur->getLeft() && n->getValue() >= cur->getLeft()->getValue())
	{
		cur->setLeft(rotate_left(cur->getLeft()));
		return rotate_right(cur);
	}

	// RR
	if (balance < -1 && cur->getRight() && n->getValue() >= cur->getRight()->getValue())
	{
		return rotate_left(cur);
	}

	// RL
	if (balance < -1 && cur->getRight() && n->getValue() < cur->getRight()->getValue())
	{
		cur->setRight(rotate_right(cur->getRight()));
		return rotate_left(cur);
	}

	return cur;
}

void BiTree::balance_insert(Node* n)
{
	if (head == NULL)
	{
		head = n;
		head->setHeight(1);
		head->setLeft(NULL);
		head->setRight(NULL);
	}
	else
	{
		Node* cur = head;

		head = recur_balance_insert(cur, n);
	}
}

