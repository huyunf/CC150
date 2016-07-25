/*
Write a method to compute all permutations of a string

intput: abc
output: abc, acb, bac, bca, cab, cba
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

void permuation1_str(string& str, vector<string>& v)
{
#define re_cur
#ifdef  re_cur

	for (int i = 0; i < str.size(); i++)
	{
		string cur = str.substr(i, 1);

		if (v.empty())
		{
			v.push_back(cur);
		}
		else
		{

			int size = v.size();

			for (int j = 0; j<size; j++)
			{
				string tmp = v[j];

				for (int i = 0; i <= tmp.size(); i++)
				{
					string s(tmp);

					s.insert(i, cur);

					v.push_back(s);
				}
			}

			v.erase(v.begin(), v.begin() + size);
		}

	}

#else

	if (str.empty()) return;

	string cur = str.substr(0, 1);

	if (v.empty())
	{
		v.push_back(cur);
	}
	else
	{

		int size = v.size();

		for (int j=0; j<size; j++)
		{
			string tmp = v[j];

			for (int i = 0; i <= tmp.size(); i++)
			{
				string s(tmp);

				s.insert(i, cur);

				v.push_back(s);
			}
		}

		v.erase(v.begin(), v.begin()+size);
	}

	str.erase(0, 1);

	permuation_str(str, v);

#endif
}

void permuation2_str(string& prev, string& str)
{
	if (str.size() == 1)
	{
		cout << prev + str << endl;
		return;
	}

	for (int i = 0; i < str.size(); i++)
	{
		string cur = str.substr(i, 1);
		
		str.erase(i, 1);

		prev.insert(0, cur);

		permuation2_str(prev, str);

		prev.erase(0, 1);

		str.insert(i, cur);
	}
}

int main()
{
	string str = "abc";
	string prev = "";

	vector<string> v;
/*
	permuation1_str(str, v);

	for (vector<string>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}
*/

	permuation2_str(prev, str);



	return 0;
}


