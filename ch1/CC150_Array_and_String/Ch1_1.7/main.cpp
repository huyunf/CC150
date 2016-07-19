/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
*/

#include <iostream>
using namespace std;

#define Matrix_Dim_col 4
#define Matrix_Dim_row 4

void dump_matirx(int* M_ptr, int row_dim, int col_dim)
{
	cout << "------ DUMP Matrix ------" << endl;
	for (int j = 0; j < row_dim; j++)
	{
		for (int i = 0; i < col_dim; i++)
		{
			cout << *M_ptr++ << "  ";
		}
		cout << endl;
	}
	cout << "------ ------" << endl;
	cout << endl;
}

int main()
{
	int Matrix[Matrix_Dim_row][Matrix_Dim_col] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 0, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};

	unsigned char r_flag[Matrix_Dim_row] = { 0 };
	unsigned char c_flag[Matrix_Dim_col] = { 0 };

	dump_matirx(&Matrix[0][0], Matrix_Dim_row, Matrix_Dim_col);

	for (int j = 0; j < Matrix_Dim_row; j++)
	{
		for (int i = 0; i < Matrix_Dim_col; i++)
		{
			if (Matrix[j][i] == 0)
			{
				r_flag[j] = 1;
				c_flag[i] = 1;
			}
		}
	}

	for (int j = 0; j < Matrix_Dim_row; j++)
	{
		for (int i = 0; i < Matrix_Dim_col; i++)
		{
			Matrix[j][i] = r_flag[j] == 1 ? 0 : c_flag[i] == 1 ? 0 : Matrix[j][i];
		}
	}

	dump_matirx(&Matrix[0][0], Matrix_Dim_row, Matrix_Dim_col);
}



