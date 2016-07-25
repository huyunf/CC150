/*
Write a program to swap odd and even bits in an integer with as few instructions as possible
(e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).

	a = a^b
	b = a^b = (a^b)^b = a
	a = a^b = (a^b)^a = b
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

int swap_bits(int x) 
{
	return ((x & 0x55555555) << 1) | ((x >> 1) & 0x55555555);
}

int main()
{
	int a	= 0x123456;
	int a_ = swap_bits(a);

	print_binary(a);
	print_binary(a_);
}