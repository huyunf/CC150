/*
Given a sorted array of n integers that has been rotated an unknown number of times, give an O(log n) algorithm that finds an element in the array. 
You may assume that the array was originally sorted in increasing order.

EXAMPLE:

Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)

Output: 8 (the index of 5 in the array)
*/

#include <iostream>
using namespace std;

bool search(int* a, int l, int h, int target, int* index)
{
	bool r;

	if (l == h && a[l] != target)
	{
		r = false;
	}
	else
	{
		int mid = (l + h + 1)/ 2;

		if (a[mid] == target)
		{
			*index = mid;
			r = true;
		}
		else
		{
			if (a[mid] < target)
			{
				if (a[l] < target)
					r = search(a, l, mid-1, target, index);
				else
					r = search(a, mid+1, h, target, index);
			}
			else
			{
				if (a[l] > target)
					r = search(a, mid+1, h, target, index);
				else
					r = search(a, l, mid-1, target, index);
			}
		}
	}

	return r;
}

int main()
{
	int a[] = { 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 };
	//int a[] = { 16, 19, 20, 25, 26, 28, 29, 31, 33, 37, 1, 2, 3, 4, 5, 7, 10, 14, 15};

	int target = 6;

	int index;

	bool r = search(a, 0, (sizeof(a) / sizeof(a[0])) - 1, target, &index);

	cout << "Find the target ? " << (r == true ? "Yes" : "No") << endl;

	if (r) cout << "The target is the [" << index << "] data in the array!" << endl;

	return 0;
}