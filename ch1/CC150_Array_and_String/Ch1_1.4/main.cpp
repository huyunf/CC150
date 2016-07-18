/*
	Write a method to decide if two strings are anagrams or not.

	变位词(anagrams)指的是组成两个单词的字符相同，但位置不同的单词。比如说， abbcd和abcdb就是一对变位词。
*/

#include <iostream>
#include <string>
using namespace std;

bool is_anagrams(string &str1, string &str2)
{
	unsigned char hash1[256] = { 0 };
	unsigned char hash2[256] = { 0 };

	if (str1.size() != str2.size()) return false;

	for (int i = 0; i < str1.size(); i++) 
	{
		hash1[str1[i]] ++;
		hash2[str2[i]] ++;
	}

	for (int i = 0; i < 256; i++) 
	{
		if (hash1[i] != hash2[i]) return false;
	}

	return true;
}

int main()
{
	string istr1 = "abbcdedtr4";
	string istr2 = "abcedb4rtd";

	bool ret = is_anagrams(istr1, istr2);

	cout << "Is Anagrams? " << (ret ? "Yes":"No") << endl;
}