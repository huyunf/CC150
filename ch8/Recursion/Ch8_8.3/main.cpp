/*
Write a method that returns all subsets of a set.
*/

#include <iostream>
#include <vector>
using namespace std;

void dump_set(vector<int>* v)
{
	for (vector<int>::iterator iter = v->begin(); iter != v->end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void subset(vector<int>* v)
{
	if(!v->empty()) dump_set(v);

	for (int i = 0; i < v->size(); i++)
	{
		int value = v->at(i);
		
		v->erase(v->begin() + i);

		subset(v);

		v->insert(v->begin() + i, value);
	}
}

void dumpset1(vector<vector<int>*> sub)
{
	for (int j = 0; j < sub.size(); j++)
	{
		vector<int>* cur = sub.at(j);

		for (int i = 0; i < cur->size(); i++)
		{
			cout << cur->at(i) << " ";
		}

		cout << endl;
	}
}

void subset1(int* a, int size, vector<vector<int>*> &s)
{
	for (int i = 0; i < size; i++)
	{
		vector<int>* cur = new vector<int>;
		cur->push_back(a[i]); // the single one

		if (!s.empty())
		{
			int cur_size = s.size();

			for (int j = 0; j < cur_size; j++)
			{
				vector<int>* ss = s.at(j);
				vector<int>* new_s = new vector<int>;

				for (int k = 0; k < ss->size(); k++)
				{
					new_s->push_back(ss->at(k));
				}

				new_s->push_back(a[i]);
				s.push_back(new_s);
			}
		}
		
		s.push_back(cur);
	}
}

void subset2(int* a, int size, vector<vector<int>*> &s)
{
	if (size == 0) return ;

	vector<int>* cur = new vector<int>;
	cur->push_back(a[0]); // the single one

	subset2(a + 1, size - 1, s);

	if (!s.empty())
	{
		int cur_size = s.size();

		for (int j = 0; j < cur_size; j++)
		{
			vector<int>* ss = s.at(j);
			vector<int>* new_s = new vector<int>;

			for (int k = 0; k < ss->size(); k++)
			{
				new_s->push_back(ss->at(k));
			}

			new_s->push_back(a[0]);
			s.push_back(new_s);
		}
	}

	s.push_back(cur);
}

int main()
{
	int a[] = { 0, 1, 2, 3, 4, 5};
	

#if 0
	vector<int>* v = new vector<int>;

	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		v->push_back(a[i]);
	}

	subset(v);

	if (v) delete v;
#endif

	/*
	vector<vector<int>*> sub1;

	subset1(a, sizeof(a) / sizeof(a[0]), sub1);

	dumpset1(sub1);

	*/

	vector<vector<int>*> sub2;

	subset2(a, sizeof(a) / sizeof(a[0]), sub2);

	dumpset1(sub2);

	return 0;
}
