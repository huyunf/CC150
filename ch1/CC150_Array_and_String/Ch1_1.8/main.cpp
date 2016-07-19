/*
Assume you have a method isSubstring which checks if one word is a substring of another.
Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring ( i.e., “waterbottle” is a rotation of “erbottlewat”).
*/

#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string s1, string s2) 
{
	if (s1.find(s2) != string::npos) return true;
	else return false;
}

bool isRotation(string s1, string s2) 
{
	if (s1.length() != s2.length() || s1.length() <= 0)
		return false;
	return isSubstring(s1 + s1, s2);
}

int main()
{
	string s1 = "waterbottle";
	string s2 = "erbottlewat";

	cout << "String 1: " << s1 << endl;
	cout << "String 2: " << s2 << endl;
	cout << "Is Rotation ? " << (isRotation(s1, s2) ? "Yes" : "No") << endl;
	
	return 0;
}