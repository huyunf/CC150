/*
How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? 
Push, pop and min should all operate in O(1) time.
*/

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class cstack
{
public:
	cstack();
	bool push(int d);
	bool pop(int* d);
private:
	static const unsigned int stack_size = 65536;
	int stack_array[stack_size];
	int stack_ptr;
	vector<int> min;
};

cstack::cstack()
{
	memset(stack_array, 0, sizeof(stack_array));

	stack_ptr = 0;

	min.clear();

	cout << "min size = " << min.size() << endl;

	min.push_back(~(1 << 31));
	vector<int>::iterator e = min.end()-1;

	cout << "min size = " << min.size() << " min value = " << *e << endl;
}

bool cstack::push(int d)
{
	vector<int>::iterator e = min.end() - 1;

	cout << "@push>> Push Data: " << d << endl;

	if (stack_ptr > stack_size)
	{
		cout << "@push>> Stack Full!" << endl;
		return false;
	}

	if (d < *e)
	{
		min.push_back(d);
		e = min.end() - 1;
		cout << "@push>> min size = " << min.size() << " min value = " << *e << endl;
	}

	stack_array[stack_ptr++] = d;

	return true;
}

bool cstack::pop(int* d)
{
	if (stack_ptr < 0)
	{
		cout << "@pop>> Stack Empty!" << endl;
		return false;
	}

	*d = stack_array[stack_ptr--];
	vector<int>::iterator e = min.end() - 1;

	cout << "@pop>> Pop Data: " << *d << endl;

	if (*d == *e)
	{
		min.pop_back();
		e = min.end() - 1;
		cout << "@pop>> min size = " << min.size() << " min value = " << *e << endl;
	}

	return true;
}

int main()
{
	cstack s; 

	srand(time(NULL));
	for (int i = 0; i < 50; i++)
	{
		int data = rand() % 10000;

		s.push(data);
	}

	int tmp;
	for (int j = 0; j < 20; j++)
	{
		s.pop(&tmp);
	}

	return 0;
}