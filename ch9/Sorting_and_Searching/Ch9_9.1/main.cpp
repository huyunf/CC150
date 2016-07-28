/*
You are given two sorted arrays, A and B, and A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.
*/

#include <iostream>
using namespace std;

#define ARRAY1_SIZE 30
#define ARRAY2_SIZE 12


void dump_array(int* a, int size)
{
	cout << "\n=======================================\n";
	for (int i = 0; i < size; i++)
	{
		if (i != 0 && i % 10 == 0) cout << endl;

		cout << a[i] << " ";
	}

	cout << "\n=======================================\n"<<endl;

}

void merge_array(int *a1, int size1, int *a2, int size2)
{
	int cur;
	int result_size = size1 + size2;

	for (int i = result_size - 1, ptr1 = size1 - 1, ptr2 = size2 - 1; i >= 0; i--)
	{
		if (ptr1 < 0)
			cur = a2[ptr2--];
		else if (ptr2 < 0)
			cur = a1[ptr1--];
		else
		{
			if (a1[ptr1] >= a2[ptr2])
				cur = a1[ptr1--];
			else 
				cur = a2[ptr2--];
		}

		a1[i] = cur;
	}
}

int main()
{
	int* a1 = new int[ARRAY1_SIZE*2];
	int* a2 = new int[ARRAY2_SIZE];

	for (int i = 0; i < ARRAY1_SIZE; i++)
	{
		a1[i] = i * 2;
	}

	for (int i = 0; i < ARRAY2_SIZE; i++)
	{
		a2[i] = i * 2 + 1;
	}

	dump_array(a1, ARRAY1_SIZE);
	dump_array(a2, ARRAY2_SIZE);

	merge_array(a1, ARRAY1_SIZE, a2, ARRAY2_SIZE);

	dump_array(a1, ARRAY1_SIZE+ARRAY2_SIZE);

	return 0;
}