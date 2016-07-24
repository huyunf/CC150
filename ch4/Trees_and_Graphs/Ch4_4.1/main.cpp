/*
Implement a function to check if a tree is balanced. 
For the purposes of this question, a balanced tree is defined to be a tree such that no two leaf nodes differ in distance from the root by more than one.
*/

#include "bitree.h"

int main()
{
	BiTree* bT = new BiTree;

	int a[] = {
		5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12
	};

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		Node* n = new Node(a[i]);

		bT->insert(n);
	}

	bT->Preorder_Traversal();

	bT->Inorder_Traversal();

	bT->Postorder_Traversal();

	cout << "Min Depth: "<< bT->minDepth() << endl;

	return 0;
}