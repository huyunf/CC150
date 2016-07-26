/*
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent), write code to calculate the number of ways of representing n cents.
*/

#include <iostream>
#include <vector>
using namespace std;

void dump_vec(vector<int> *v)
{
	for (vector<int>::iterator iter = v->begin(); iter != v->end(); iter++)
	{
		cout << *iter << " ";
	}

	cout << endl;
}

// next index is the key for no dumplicated case
void collect_total(int coin[4], int next_idx, const int total, vector<int>* v)
{
	int sum = 0;

	for (vector<int>::iterator iter = v->begin(); iter != v->end(); iter++)
	{
		sum += *iter;
	}

	for (int i = next_idx; i < 4; i++)
	{
		sum += coin[i];
		v->push_back(coin[i]);

		if (sum == total)
		{
			dump_vec(v);
		}
		else if (sum < total)
		{
			collect_total(coin, i, total, v);
		}

		sum -= coin[i];
		v->pop_back();
	}
}

int main()
{

	int coin[4] = { 25, 10, 5, 1 };

	const int total = 51;

	vector<int> *v = new vector<int>;

	collect_total(coin, 0, total, v);

}
