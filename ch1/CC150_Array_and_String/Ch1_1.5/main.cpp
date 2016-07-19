/*
Write a method to replace all spaces in a string with ‘%20’.

i am hawstein
i%20am%20hawstein
*/

#include <iostream>
#include <string>
using namespace std;

#define ARRAY_SIZE 128

bool replace(unsigned char* str, unsigned int ary_sz)
{
	unsigned int orig_sz = 0;
	unsigned int tran_sz = 0;
	unsigned int space_num = 0;
	unsigned char* tmp_ptr = str;

	while (*tmp_ptr != '\0') 
	{
		orig_sz++;
		if (*tmp_ptr == ' ') space_num++;
		tmp_ptr++;
	}

	tran_sz = orig_sz + (space_num << 1) + 1; // 1 for '\0'

	cout << "original size = " << orig_sz << "; space number = " << space_num << "; trans size = " << tran_sz << endl;

	if (tran_sz > ary_sz) return false;

	int ptr_w = tran_sz - 1;
	int ptr_r = orig_sz - 1;

	str[ptr_w--] = '\0';

	while (ptr_r >= 0)
	{
		if (str[ptr_r] != ' ')
		{
			str[ptr_w--] = str[ptr_r--];
		}
		else
		{
			str[ptr_w--] = '0';
			str[ptr_w--] = '2';
			str[ptr_w--] = '%';
			ptr_r--;
		}
	}

	return true;
}

int main()
{
	unsigned char istr[ARRAY_SIZE] = "This is a wonderful world! Thanks Lord!";

	cout << "Before replace: " << istr << endl;

	replace(istr, ARRAY_SIZE);

	cout << "After replace: " << istr << endl;
}










