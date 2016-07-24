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

	void Preorder_Traversal();	// cur, left, right
	void Inorder_Traversal();	// left, cur, right
	void Postorder_Traversal();	// left, right, cur

	void insert(Node* n);
	void balance_insert(Node* n);

private:

	void recur_insert(Node* cur, Node* n);
	void recur_balance_insert(Node* cur, Node* n);
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

	recur_inorder(cur);

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


void BiTree::recur_balance_insert(Node* cur, Node* n)
{
	if (cur->getValue() > n->getValue()) // go left
	{
		if (cur->getLeft()) {
			recur_balance_insert(cur->getLeft(), n);
		}
		else {
			cur->setLeft(n);
		}
	}
	else // go right
	{
		if (cur->getRight()) {
			recur_balance_insert(cur->getRight(), n);
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

		recur_balance_insert(cur, n);
	}
}

