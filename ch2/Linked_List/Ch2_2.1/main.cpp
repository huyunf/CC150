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
	linked_list(int*a, int n);
	~linked_list();
	
	node* get_head() { return head; }
	int get_size() { return list_size; }
	bool insert_node(node* n);
	bool insert_node(int d);
	bool remove_node();

	// Ch2_2.1
	// Write code to remove duplicates from an unsorted linked list.
	bool remove_duplicate();

	// Ch2_2.2
	// Implement an algorithm to find the nth to last element of a singly linked list.

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

// Ch2_2.1
// Write code to remove duplicates from an unsorted linked list.
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
}

int main()
{
	int a[] = { 0,1,1,2,3,3,4,5,1 };

	linked_list* list = new linked_list(a, sizeof(a)/sizeof(a[0]));

	cout << "List size = " << list->get_size() << endl;

	list->insert_node(6);

	cout << "List size = " << list->get_size() << endl;

	list->remove_node();

	cout << "List size = " << list->get_size() << endl;

	list->remove_duplicate();

	cout << "List size = " << list->get_size() << endl;

	delete list;

	return 0;
}
