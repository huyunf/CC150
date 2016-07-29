/*
Given a matrix in which each row and each column is sorted, write a method to find an element in it.
*/

#include <iostream>
#include <vector>
using namespace std;

#define N 5

bool search(int a[N][N], int n, const int target, vector<pair<int, int>> &v)
{
	bool ret;
	int min = a[0][0];
	int max = a[N - 1][N - 1];

	if (target<min || target >max)
	{
		cout << "target exceed the range of maxtrix" << endl;
		ret = false;
	}
	else
	{
		for (int j = 0; j < N; j++)
		{
			if (a[j][N - 1] < target)
			{
				continue;
			}
			if (a[j][0] > target)
			{
				break;
			}
			for (int i = 0; i < N; i++)
			{
				if (a[j][i] == target)
				{
					v.push_back(make_pair(j, i));
					ret = true;
					break;
				}
			}
		}
	}

	return ret;
}

int main()
{
	int a[N][N] = {
		
		{1, 2, 3, 4, 5},
		{3, 7, 8, 9, 11},
		{5, 9, 10, 17, 18 },
		{7, 12, 15, 19, 23 },
		{9, 13, 16, 20, 25 }
	};

	const int target = 7;
	vector<pair<int, int>> v;

	bool r = search(a, N, target, v);

	cout << "Find Target? " << (r == true ? "Yes" : "No") << endl;
	if (r == true)
	{
		for (vector<pair<int, int>>::iterator iter = v.begin(); iter != v.end(); iter++)
		{
			cout << "Position: " << "x=" << iter->second << ", y=" << iter->first << endl;
		}
	}

	return 0;
}