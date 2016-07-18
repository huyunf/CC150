/*
Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.

FOLLOW UP

Write the test cases for this method.
*/

#include <iostream>
#include <string>
using namespace std;

void remove_dup_str(string& str)
{
	unsigned char char_bit[32] = { 0 };

	size_t ptr_w, ptr_r;

	for (ptr_w = 0, ptr_r = 0; ptr_r < str.size(); ptr_r++) 
	{
		int byte_pos		= str[ptr_r] / 8;
		int bit_pos			= str[ptr_r] % 8;
		unsigned char mask	= (1 << bit_pos);

		if (!(char_bit[byte_pos] & mask)) {
			char_bit[byte_pos] |= mask;

			if (ptr_r != ptr_w){
				str[ptr_w] = str[ptr_r];
			}
			ptr_w++;
		}
	}
	
	while (ptr_w != ptr_r) {
		str.pop_back();
		ptr_w++;
	}
	
}

int main()
{
	string istr;// = "abcdefghiklalllfjkjfkd";

	cout << "Input string: " << endl;
	cin >> istr;

	remove_dup_str(istr);

	cout << istr << endl;
}

