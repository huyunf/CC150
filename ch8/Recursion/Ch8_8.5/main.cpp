/*
Implement an algorithm to print all valid (e.g., properly opened and closed) combinations of n-pairs of parentheses.

EXAMPLE:

input: 3 (e.g., 3 pairs of parentheses)

output: ((())), (()()), (())(), ()(()), ()()()
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


void all_case(vector<string> &s, char set[2], int set_num)
{
	if (set_num == 0) return;

	int case_size = s.size();

	if (case_size == 0)
	{
		string tmp1;
		tmp1.push_back(set[0]);
		tmp1.push_back(set[1]);
		s.push_back(tmp1);

		string tmp2;
		tmp2.push_back(set[1]);
		tmp2.push_back(set[0]);
		s.push_back(tmp2);
	}
	else
	{
		for (int i = 0; i < case_size; i++)
		{
			string* tmp1 = &s[i];
			string tmp2 = s[i];

			tmp1->insert(tmp1->begin(), set[0]);
			tmp1->push_back(set[1]);

			tmp2.insert(tmp2.begin(), set[1]);
			tmp2.push_back(set[0]);
			s.push_back(tmp2);
		}
	}

	all_case(s, set, set_num-1);
}

int main()
{
	char set[2] = { '(', ')' };

	cout << set[0] << " " << set[1] << endl;

	int set_num = 3;

	vector<string> s;

	all_case(s, set, set_num);


	return 0;

}