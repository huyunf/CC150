/*
Given an integer, print the next smallest and next largest number that have the same number of 1 bits in their binary representation.
*/

#include <iostream>
using namespace std;

void print_binary(int v)
{
	for (int i = 31; i >= 0; i--)
	{
		unsigned int mask = 1 << i;

		cout << (v&mask ? "1" : "0");
	}

	cout << endl;
}

int main()
{
	unsigned int x = 12345;
	unsigned int bit1_num = 0;

	print_binary(x);

	for (int i = 0; i < 32; i++)
	{
		unsigned int mask = 1 << i;

		if (x & mask) bit1_num++;
	}

	unsigned int max_with_samebit1, min_with_samebit1;

	min_with_samebit1 = (1 << bit1_num) - 1;

	cout << min_with_samebit1 << endl;

	print_binary(min_with_samebit1);

	max_with_samebit1 = min_with_samebit1 << (32 - bit1_num);

	cout << max_with_samebit1 << endl;

	print_binary(max_with_samebit1);
}
