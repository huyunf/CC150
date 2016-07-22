/*
Describe how you could use a single array to implement three stacks.
*/

#include <iostream>
#include <vector>
using namespace std;

class stack_bundle 
{
public:
	stack_bundle(int mode);
	~stack_bundle();
	bool stack_push(int data, int stk_idx);
	bool stack_pop(int data, int stk_idx);

	static const unsigned int mode_normal = 0;
	static const unsigned int mode_saving = 1;

private:

	static const unsigned int stack_num = 3;
	static const unsigned int stack_size = 65536;	

	int mode;
	int	stk_ptr[stack_num];
	int stack_array[stack_size];
	int m1_ptr;
};

stack_bundle::stack_bundle(int mode=0):mode(mode)
{
	if (mode == mode_normal)
	{
		for (int i = 0; i < stack_num; i++)
		{
			stk_ptr[i] = i;
		}

		memset(stack_array, 0x12345678, sizeof(stack_array));
	}
	else
	{
		for (int i = 0; i < stack_num; i++)
		{
			stk_ptr[i] = -1;
		}

		memset(stack_array, 0x12345678, sizeof(stack_array));

		m1_ptr = 0;
	}
}

stack_bundle::~stack_bundle()
{
	if (mode == mode_normal)
	{
		for (int i = 0; i < stack_num; i++)
		{
			stk_ptr[i] = i;
		}

		memset(stack_array, 0, sizeof(stack_array));
	}
	else
	{
		for (int i = 0; i < stack_num; i++)
		{
			stk_ptr[i] = -1;
		}

		memset(stack_array, 0, sizeof(stack_array));

		m1_ptr = 0;
	}

}

bool stack_bundle::stack_push(int data, int stk_idx)
{
	if (mode == mode_normal)
	{
		if (stk_ptr[stk_idx] > stack_size)
		{
			cout << "stack full!" << endl;
			return false;
		}
		else
		{
			stack_array[stk_ptr[stk_idx]] = data;
			stk_ptr[stk_idx] += 3;
		}
	}
	else
	{
		stack_array[m1_ptr++] = data;
	}

	return true;
}

bool stack_bundle::stack_pop(int data, int stk_idx)
{
	if (mode == mode_normal)
	{
		if (stk_ptr[stk_idx] < 0)
		{
			cout << "stack empty!" << endl;
			return false;
		}
		else
		{
			stack_array[stk_ptr[stk_idx]] = 0;
			stk_ptr[stk_idx] -= 3;
		}
	}
	else
	{

	}

	return false;
}

int main()
{
	stack_bundle stack(stack_bundle::mode_normal);

	stack.stack_push(0, 0);
	stack.stack_push(1, 1);
	stack.stack_push(2, 2);


	stack.stack_push(7, 0);
	stack.stack_push(8, 0);
	stack.stack_push(6, 0);
	stack.stack_push(5, 2);
	stack.stack_push(9, 0);

	return 0;
}



