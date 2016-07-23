/*
In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower. 
The puzzle starts with disks sorted in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one). You have the following constraints:

Only one disk can be moved at a time.
A disk is slid off the top of one rod onto the next rod.
A disk can only be placed on top of a larger disk.

Write a program to move the disks from the first rod to the last using Stacks
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

class Hanoi
{
public:
	Hanoi();

	void Hanoi_dump();

	void Hanoi_run();

private:
	void hanoi(int n, cstack* src, cstack* bri, cstack* dst);

	static const unsigned int disk_num = 7;

	cstack stack[3];
};

Hanoi::Hanoi()
{
	cstack* s = &stack[0];

	for (int i = disk_num; i > 0; i--)
	{
		s->push(i);
	}

	cout << "Initialize Hanoi Tower" << endl;
}

void Hanoi::Hanoi_dump()
{
	cout << "------ Hanoi Dump------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "stack [" << i << "]: ";
		stack[i].dump_stack();
	}
	cout << "-----------------------" << endl << endl;;
}


void Hanoi::hanoi(int n, cstack* src, cstack* bri, cstack* dst)
{
	int d;

	if (n == 1)
	{
		src->pop(&d);
		dst->push(d);
		cout << "Move disk " << d << " from " << (unsigned int)src << " to " << (unsigned int)dst << endl;

		Hanoi_dump();
	}
	else
	{
		hanoi(n - 1, src, dst, bri);

		src->pop(&d);
		dst->push(d);
		cout << "Move disk " << d << " from " << (unsigned int)src << " to " << (unsigned int)dst << endl;
		Hanoi_dump();

		hanoi(n - 1, bri, src, dst);
	}
}

void Hanoi::Hanoi_run()
{
	hanoi(disk_num, &stack[0], &stack[1], &stack[2]);
}

int main()
{
	Hanoi h;

	h.Hanoi_dump();

	h.Hanoi_run();

	return 0;
}