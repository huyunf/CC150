/*
Write a method to generate the nth Fibonacci number.

f(1) = f(2) = 1;
f(n) = f(n-1) + f(n-2);

1 1 2 3 5 8 13 21 34 55 ...
*/

#include <iostream>
using namespace std;

long long fn(long long n)
{
	if (n == 1 || n == 2) 
		return 1;
	else
	{
		return fn(n - 1) + fn(n - 2);
	}
}

long long fn_nonrecur(long long n)
{
	long long fn_1, fn_2;
	long long fn;
	
	if (n <= 0) return -1;

	if (n == 1 || n == 2)
		return 1;

	fn_1 = fn_2 = 1;

	for (int i = 3; i <= n; i++)
	{
		if (i > 3)
		{
			fn_2 = fn_1;
			fn_1 = fn;
		}

		fn = fn_1 + fn_2;
	}

	return fn;
}

int main()
{
	long long n = 94;

	for (long long i = 0; i < n; i++)
		cout << fn_nonrecur(i) << endl;

	return 0;
}

