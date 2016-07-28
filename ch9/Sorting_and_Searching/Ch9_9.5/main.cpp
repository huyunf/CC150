/*
Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.

Example: find “ball” in [“at”, “”, “”, “”, “ball”, “”, “”, “car”, “”,“”, “dad”, “”, “”] will return 4

Example: find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”, “dad”, “”, “”] will return -1
*/


#include <iostream>
using namespace std;

bool search(string* a, int l, int h, string target, int* index)
{
	bool r;

	if (l == h && a[l] != target)
	{
		r = false;
	}
	else
	{
		int mid = (l + h + 1) / 2;

		/*
		while (a[mid] == "" && mid<h) 
			mid++;
		*/

		if(a[mid] == "")	// find a valid one
		{
			int tmp_idx_bwd = mid;
			int tmp_idx_fwd = mid;
			// backward search
			while (a[tmp_idx_bwd] == "" && tmp_idx_bwd <= h)
				tmp_idx_bwd++;
			
			while (a[tmp_idx_fwd] == "" && tmp_idx_fwd >= l)
				tmp_idx_fwd--;

			mid = tmp_idx_bwd != (h+1) ? tmp_idx_bwd : tmp_idx_fwd != (l-1) ? tmp_idx_fwd : mid;

			if (a[mid] == "")
			{
				r = false;
			}
		}

		if (a[mid] != "")
		{
			if(a[mid]==target)
			{
				*index = mid;
				r = true;
			}
			else
			{
				if (a[mid] > target)
					r = search(a, l, mid-1, target, index);
				else
					r = search(a, mid+1, h, target, index);
			}
		}
	}

	return r;
}

int main()
{
	string a1[] = { "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "" };

	string target = "at";

	int index;

	bool r = search(a1, 0, sizeof(a1) / sizeof(a1[0]) - 1, target, &index);

	cout << "Find the target ? " << (r == true ? "Yes" : "No") << endl;

	if (r) cout << "The target is the [" << index << "] data in the array!" << endl;

	return 0;
}