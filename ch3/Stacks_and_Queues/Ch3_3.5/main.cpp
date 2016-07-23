/*
Implement a MyQueue class which implements a queue using two stacks.
*/

#include <iostream>
using namespace std;

class cstack
{
public:
	cstack() :stack_ptr(-1) {};
	bool push(int d);
	bool pop(int *d);
	void dump_stack();
private:
	static const int stack_size = 65536;

	int stack_array[stack_size];
	int stack_ptr;
};

bool cstack::push(int d)
{
	if (stack_ptr >= stack_size)
	{
		cout << "Stack Full" << endl;
		return false;
	}
	else
	{
		stack_ptr++;
		stack_array[stack_ptr] = d;
	}

	return true;
}

bool cstack::pop(int* d)
{
	if (stack_ptr < 0)
	{
		cout << "Stack Empty" << endl;
		return false;
	}
	else
	{
		*d = stack_array[stack_ptr--];
	}

	return true;
}

void cstack::dump_stack()
{
	if (stack_ptr >= 0)
	{
		for (int i = 0; i <= stack_ptr; i++)
		{
			cout << stack_array[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "EMPTY" << endl;
	}
}

class MyQueue
{
public:
	MyQueue();
	~MyQueue();
	bool push(int d);
	bool pop(int *d);
	void dump();
private:
	cstack* stk_main;
	cstack* stk_assistant;
};

MyQueue::MyQueue()
{
	stk_main = new cstack;
	stk_assistant = new cstack;
}

MyQueue::~MyQueue()
{
	if (stk_main) delete stk_main;
	if (stk_assistant) delete stk_assistant;
}

bool MyQueue::push(int d)
{
	return stk_main->push(d);
}

bool MyQueue::pop(int *d)
{
	bool r;
	int data;

	if (stk_assistant->pop(&data))
	{
		*d = data;
	}
	else
	{
		while (stk_main->pop(&data))
		{
			r = stk_assistant->push(data);
		}

		if (stk_assistant->pop(&data))
		{
			*d = data;
		}
		else
		{
			return false;
		}
	}

	cout << "Pop data: " << *d << endl;

	return true;
}

void MyQueue::dump()
{
	cout << "stack main:" << endl;
	stk_main->dump_stack();

	cout << "stack assistant: " << endl;
	stk_assistant->dump_stack();
}

int main()
{
	int d;
	int a[] = { 0,1,2,3,4,5,6,7 };

	MyQueue* q = new MyQueue;

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		q->push(i);
	}

	q->dump();

	q->pop(&d);
	q->push(1);
	q->push(3);
	q->push(4);
	q->push(5);
	q->pop(&d);

	q->dump();

	q->pop(&d);
	q->pop(&d);
	q->pop(&d);
	q->pop(&d);
	q->pop(&d);
	q->pop(&d);
	q->pop(&d);

	q->dump();

	if (q) delete q;

	return 0;
}