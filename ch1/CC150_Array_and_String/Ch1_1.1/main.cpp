/*
Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
*/

#include <iostream>
#include <string>
using namespace std;


bool is_unique0(string &str)
{
	unsigned char char_bit[32] = { 0 };

	for (int i = 0; i < str.size(); i++) {
		int byte_pos = str[i] / 8;
		int bit_pos = str[i] % 8;
		unsigned char mask = (1 << bit_pos);

		if (char_bit[byte_pos] & mask) {
			cout << str[i] << endl;
			return false;
		}
		else {
			char_bit[byte_pos] |= mask;
		}
	}

	return true;
}

int main()
{
	string istr;// = "abcdefghiklalllfjkjfkd";

	cout << "Input string: " << endl;
	cin >> istr;

	cout <<"Is unique? "<< (is_unique0(istr) ? "Yes" : "No") << endl;
}
