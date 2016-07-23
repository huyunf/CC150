/*
Write a program to sort a stack in ascending order. 
You should not make any assumptions about how the stack is implemented. 
The following are the only functions that should be used to write this program: push | pop | peek | isEmpty.
*/

#include <iostream>
#include <ctime>
using namespace std;

class cstack
{
public:
	cstack() :stack_ptr(-1) {};
	bool push(int d);
	bool pop(int *d);
	bool peek(int *d);
	bool isEmpty();
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

bool cstack::peek(int *d)
{
	bool r;

	if (stack_ptr < 0) 
	{
		r = false;
	}
	else
	{
		*d = stack_array[stack_ptr];
		r = true;
	}

	return r;
}

bool cstack::isEmpty()
{
	return stack_ptr < 0 ? true : false;
}

void cstack::dump_stack()
{
	if (stack_ptr >= 0)
	{
		for (int i = 0; i <= stack_ptr; i++)
		{
			if (i != 0 && i % 10 == 0) cout << endl;

			cout << stack_array[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "EMPTY" << endl;
	}
}


void stack_sort(cstack* stk_m, cstack* s)
{
	int d;

	while (stk_m->pop(&d))
	{
		int top;

		while (1)
		{
			bool r = s->peek(&top);
			if (r == false)
			{
				s->push(d); 
				break;
			}
			else
			{
				if (d < top)
				{
					s->pop(&top);
					stk_m->push(top);
				}
				else
				{
					s->push(d);
					break;
				}
			}
		}
	}

	s->dump_stack();

	while (s->pop(&d))
	{
		stk_m->push(d);
	}
}

int main()
{
	cstack* stk_main = new cstack;
	cstack* sta_assi = new cstack;

	srand(time(NULL)); 

	for (int i = 0; i < 100; i++)
	{
		int d = rand() % 1000;
		stk_main->push(d);
	}

	stk_main->dump_stack();
	
	stack_sort(stk_main, sta_assi);

	stk_main->dump_stack();

	if (stk_main) delete stk_main;
	if (sta_assi) delete sta_assi;

	return 0;
}

