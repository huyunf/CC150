/*
5) Programming test: Write a function that will operate on a C-string and
convert all instances of "AB" to "C" without using a second string for
temporary storage.

Use the following function signature:

void translate(char *str)

So for example:

char astring[] = "helloABworld";

translate(astring);

// Now astring holds "helloCworld";

Your function should handle strings of arbitrary length. If you have any
questions about the problem, make reasonable assumptions and state your
assumptions in your reply.  
*/

#include <iostream>
#include <string>
using namespace std;

void translate(string &str)
{
	int ptr_w = 0;
	int ptr_r = 0;

	while (ptr_r < str.size())
	{
		if (str[ptr_r] != 'A')
		{
			str[ptr_w++] = str[ptr_r++];
		}
		else
		{
			if ( (ptr_r+1 < str.size()) && (str[ptr_r + 1] == 'B')) // find 'AB'
			{
				ptr_r = ptr_r + 2;
				str[ptr_w++] = 'C';
			}
			else
			{
				str[ptr_w++] = str[ptr_r++];
			}
		}
	}

	while (ptr_r - ptr_w) {
		str.pop_back(); 
		ptr_w++;
	}

}

int main()
{
	string istr = "helloABwoArldABABABccA";

	cout << "Before translate: " << istr << endl;

	translate(istr);

	cout << "After translate: " << istr << endl;
}
