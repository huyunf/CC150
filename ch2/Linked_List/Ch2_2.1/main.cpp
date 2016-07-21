/*
Write code to remove duplicates from an unsorted linked list.

FOLLOW UP

How would you solve this problem if a temporary buffer is not allowed?
*/

#include <iostream>
using namespace std;

class node
{
public:
	node(int d) :data(d),next(NULL) {}
	node() {}
	bool set_data(int d) { data = d; return true; }
	int get_data() { return data; }
	bool set_next(node* n) { next = n; return true; }
	node* get_next() { return next; }

private:
	int		data;
	node*	next;
};

class linked_list
{
public:
	linked_list() : head(NULL) , list_size(0) {};
	linked_list(int*a, int n);
	~linked_list();
	
	node* get_head() { return head; }
	int get_size() { return list_size; }
	bool insert_node(node* n);
	bool insert_node(int d);
	bool remove_node();	// remove the last node

	// Ch2_2.1
	// Write code to remove duplicates from an unsorted linked list.
	bool remove_duplicate();

	// Ch2_2.2
	// Implement an algorithm to find the nth to last element of a singly linked list.
	//-----------------------------------------------------
	// Solution:
		// 1. scan list 2 times
		// 2. since our linked list has size, it's easy
		// 3. using stack, first in last out
	//-----------------------------------------------------

	// Ch2_2.3
	/*
		Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
		EXAMPLE
		Input: the node ‘c’ from the linked list a->b->c->d->e Result: nothing is returned, but the new linked list looks like a->b->d->e
	*/
	node* get_node(int d);		// get a node with value d
	bool remove_node(node* n);	// remove specified node

	// Ch2_2.4
	/*
	You have two numbers represented by a linked list, where each node contains a single digit. 
	The digits are stored in reverse order, such that the 1’s digit is at the head of the list. 
	Write a function that adds the two numbers and returns the sum as a linked list.
	EXAMPLE
	513 + 295 = 808
	Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
	Output: 8 -> 0 -> 8
	*/
	friend linked_list* list_digits_add(linked_list* l1, linked_list* l2);

	// Ch2_2.5
	/*
	Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
	DEFINITION
	Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.
	EXAMPLE
	Input: A -> B -> C -> D -> E -> C [the same C as earlier]
	Output: C
	*/



private:
	node*	head;
	int		list_size;
};

linked_list::linked_list(int*a, int n)
{
	list_size = 0;

	if (n == 0)
	{
		head = NULL;
	}
	else
	{
		head = new node(a[0]);
		node* cur_node = head;
		list_size++;

		for (int i = 1; i < n; i++)
		{
			node* new_node = new node(a[i]);

			cur_node->set_next(new_node);
			list_size++;

			cur_node = new_node;
		}
	}
}

linked_list::~linked_list()
{
	if (head != NULL)
	{
		while (1)
		{
			node* next = head->get_next();
			if (NULL != next)
			{
				head->set_next(next->get_next());
				delete next;
			}
			else
				break;
		}
		delete head;

		head = NULL;
		list_size = 0;
	}
}

bool linked_list::insert_node(int d)
{
	if (head == NULL)
	{
		head = new node(d);
	}
	else
	{
		node* cur_node = head;

		while (NULL != cur_node->get_next())
		{
			cur_node = cur_node->get_next();
		}

		node* new_node = new node(d);
		cur_node->set_next(new_node);

		list_size++;
	}

	return true;
}

bool linked_list::insert_node(node* n)
{
	if (head == NULL)
	{
		head = n;
	}
	else
	{
		node* cur_node = head;

		while (NULL != cur_node->get_next())
		{
			cur_node = cur_node->get_next();
		}

		node* new_node = n;
		cur_node->set_next(new_node);

		list_size++;
	}

	return true;
}

bool linked_list::remove_node()
{
	if (head == NULL)
	{
		return false;
	}
	else
	{
		node* cur	= head;
		node* next	= cur->get_next();
		while (NULL != next->get_next())
		{
			cur		= next;
			next	= cur->get_next();
		}
		delete next;
		cur->set_next(NULL);
		list_size--;
	}

	return true;
}

// Ch2_2.1 ======================================
// Write code to remove duplicates from an unsorted linked list.
//--------------------------------------------------------------------------------
bool linked_list::remove_duplicate()
{
	node* pivot = head;
	
	if (pivot == NULL)
	{
		return false;
	}
	else
	{
		while (NULL != pivot->get_next())
		{
			int pivot_v = pivot->get_data();

			node* scan_prv = pivot;
			node* scan_cur = scan_prv->get_next();

			while (NULL != scan_cur)
			{
				if (scan_cur->get_data() == pivot_v)
				{
					scan_prv->set_next(scan_cur->get_next());
					delete scan_cur;
					list_size--;
				}
				else
				{
					scan_prv = scan_cur;
				}

				scan_cur = scan_prv->get_next();
			}

			pivot = pivot->get_next();
		}
	}

	return true;
}


// Ch2_2.3 ======================================
/*
Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
EXAMPLE
Input: the node ‘c’ from the linked list a->b->c->d->e Result: nothing is returned, but the new linked list looks like a->b->d->e
*/
//--------------------------------------------------------------------------------
node* linked_list::get_node(int d)
{
	node* n = head;

	while (n != NULL)
	{
		if (d == n->get_data())
			break;
		else
			n = n->get_next();
	}

	return n;
}

bool linked_list::remove_node(node* n)
{
	if (NULL == n) return false;

	node* next = n->get_next();

	if (next == NULL) 
	{
		remove_node();	// if the node is the last one, should scan the list.
	}
	else
	{
		n->set_data(next->get_data());
		n->set_next(next->get_next());
		delete next;
		list_size--;
	}

	return true;
}

// Ch2_2.4 ======================================
/*
You have two numbers represented by a linked list, where each node contains a single digit.
The digits are stored in reverse order, such that the 1’s digit is at the head of the list.
Write a function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
513 + 295 = 808
Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
Output: 8 -> 0 -> 8
*/
//--------------------------------------------------------------------------------
linked_list* list_digits_add(linked_list* l1, linked_list* l2)
{
	linked_list* result = new linked_list;

	node* n1 = l1->get_head();
	node* n2 = l2->get_head();
	
	int r = 0;
	int carry = 0;
	while (NULL != n1 && NULL != n2)
	{
		int d1 = n1->get_data();
		int d2 = n2->get_data();

		r = ((d1 + d2 + carry) >= 10) ? ((d1 + d2 + carry) - 10) : (d1 + d2 + carry);
		carry = ((d1 + d2 + carry) >= 10) ? 1 : 0;

		node* n = new node(r);
		result->insert_node(n);

		n1 = n1->get_next();
		n2 = n2->get_next();
	}

	node* remain;
	remain = (n1 != NULL) ? n1 : (n2 != NULL) ? n2 : NULL;

	while (NULL != remain)
	{
		int d = remain->get_data();

		r = ((d + carry) >= 10) ? ((d + carry) - 10) : (d + carry);
		carry = ((d + carry) >= 10) ? 1 : 0;

		node* n = new node(r);
		result->insert_node(n);

		remain = remain->get_next();
	}

	return result;
}

// Ch2_2.5
/*
Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C -> D -> E -> C [the same C as earlier]
Output: C
*/
/*
Solution Discussion:
	1. hash table to store the address of each node, until find certian node have value in hash table
	2. set slow pointer (1 step once) and fast pointer (2 step once)
		[0, 1, ..., n-1]
	   assuming the circle has n nodes. When slow pointer reach the start point s1=0,
	   suppose fast pointer at s2. 
	   We can prove after severl steps they will meet, after step:
	   p1 = s1 + step
	   p2 = s2 + 2xstep
	   the distance between fast & slow pointer is:
	   p2-p1 = (s2+2step)-(s1+step)=(s2-s1)+step=s2+step
	   thus when s2+step = n, fast pointer will reach the same position with slow pointer
		ex. 0 1 2 3 4	n=5
			1 3 0 2 4	s2=1 step=4
			4 1			s2=4 step=1
			2 4 1 3
		ex. 0 1 2 3 4 5	n=6
			1 3 5 1 3 5
			3 5 1 3
			2 4 0 2 4
	   The above prove that if there is a circle in linked list, using fast pointer &
	   slow pointer could confirm that

	   Find the start node of circle:
	   Suppose the structure is  k + n(circle)
	   when faster pointer meet slow pointer the total distance is
	   d1 = k + s1
	   d2 = 2(k+s1)
	   and stop the faster pointer continue the slow pointer could get the circle number n
	   (when slow pointer meet faster pointer again)

	   k+qn+x=m		(slow)
	   2m-m=m=pn	(fast-slow)
	   k+qn+x=pn
	   k+x = (p-q)n
	   The meet position distance away from head is multiple of n
	   put one pointer into head and move in same step, the meet again position is start of circle

	   x+s = n
	   k-s = (p-q-1)n
*/
//--------------------------------------------------------------------------------

int main()
{
	int a[] = { 0,1,1,2,3,3,4,5,1 };

	linked_list* list = new linked_list(a, sizeof(a)/sizeof(a[0]));

	cout << "List size = " << list->get_size() << endl;

	list->insert_node(6);

	cout << "List size = " << list->get_size() << endl;

	list->remove_node();

	cout << "List size = " << list->get_size() << endl;

	// ch2_2.1
	list->remove_duplicate();

	cout << "List size = " << list->get_size() << endl;

	// ch2_2.3
	node* n = list->get_node(5);
	list->remove_node(n);
	cout << "List size = " << list->get_size() << endl;

	// ch2_2.4
	int a1[] = { 4,1,5,3 };
	int a2[] = { 5,9,7 };
	linked_list* l1 = new linked_list(a1, sizeof(a1) / sizeof(a1[0]));
	linked_list* l2 = new linked_list(a2, sizeof(a2) / sizeof(a2[0]));
	linked_list* result = list_digits_add(l1, l2);

	// ------ end ------
	if(list) delete list;
	if (l1) delete l1;
	if (l2) delete l2;
	if (result) delete result;

	return 0;
}
