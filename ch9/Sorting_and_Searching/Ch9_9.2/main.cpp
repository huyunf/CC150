/*
Write a method to sort an array of strings so that all the anagrams are next to each other.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string s1, string s2) 
{
	sort(&s1[0], &s1[0] + s1.length());
	sort(&s2[0], &s2[0] + s2.length());
	return s1 < s2;
}

bool cmp1(string s1, string s2)
{
	return s1 < s2;
}

int main()
{
	string s[] = 
	{
		"axyz", "abc", "yzax", "bac", "zyxa", "fg", "gf"
	};

	sort(s, s + 7, cmp);

	for (int i = 0; i < 7; ++i)
		cout << s[i] << endl;

	return 0;
}
