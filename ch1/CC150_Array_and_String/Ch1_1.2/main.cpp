/*
Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)
*/

#include <iostream>
#include <string>
using namespace std;

void reverse_str(string& str) 
{
	if (str.size() <= 1) return;

	int fwd_ptr = 0;
	int bwd_ptr = str.size() - 1;

	while (1) 
	{
		str[fwd_ptr] = str[fwd_ptr] ^ str[bwd_ptr];
		str[bwd_ptr] = str[fwd_ptr] ^ str[bwd_ptr];
		str[fwd_ptr] = str[fwd_ptr] ^ str[bwd_ptr];

		if ((fwd_ptr == bwd_ptr - 1) || (fwd_ptr + 1 == bwd_ptr - 1)) break;

		fwd_ptr++;
		bwd_ptr--;
	}
}

int main()
{
	string istr;// = "abcdefghiklalllfjkjfkd";

	cout << "Input string: " << endl;
	cin >> istr;

	reverse_str(istr);

	cout << istr.size() << endl;

	cout << istr << endl;
}


