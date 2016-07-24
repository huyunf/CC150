/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j. 
Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).
EXAMPLE:

Input: N = 10000000000, M = 10101, i = 2, j = 6

Output: N = 10001010100
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

int update_bits(int dst, int src, int l, int h)
{
	int value = src << l;

	unsigned int mask;

	print_binary(value);

#if 0
	for (int i = 6; i >= 2; i--)
	{
		mask = ~(1 << i);

		print_binary(mask);

		dst &= mask;
	}
#else
	mask = ~0;

	print_binary(mask);

	unsigned int left = mask - ((1 << h+1) - 1);
	unsigned int right = (1 << l) - 1;

	print_binary(left);
	print_binary(right);

	mask = left | right;

	print_binary(mask);

	dst &= mask;

#endif

	return dst | value;
}

int main() 
{
	int n = 1 << 10, m = 21;

	int ans = update_bits(n, m, 2, 6);

	print_binary(n);
	print_binary(m);
	print_binary(ans);

	return 0;
}