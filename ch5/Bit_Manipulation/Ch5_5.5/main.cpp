/*
Write a function to determine the number of bits required to convert integer A to integer B.

Input: 31, 14

Output: 2
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
	int a = 31;
	int b = 14;

	int r = a ^ b;

	int bit1_num = 0;

	for (int i = 0; i < 32; i++)
	{
		unsigned int mask = 1 << i;

		if (r & mask) bit1_num++;
	}

	print_binary(a);

	print_binary(b);

	cout << bit1_num << endl;
}

