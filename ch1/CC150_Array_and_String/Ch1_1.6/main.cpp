/*
Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

	1 2 3
	4 5 6
	7 8 9

	7 4 1
	8 5 2
	9 6 3
*/

#include <iostream>
using namespace std;

#define Matrix_Dim 4

void dump_matirx(int* M_ptr, int col_dim, int row_dim)
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

/*
	M = [V0		MT = [V0, V1, ..., Vn]	M=[Vn, ..., V1, V0]
		 V1
		 ...
		 Vn]
*/
int main()
{
	int Matrix[Matrix_Dim][Matrix_Dim] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};

	dump_matirx(&Matrix[0][0], Matrix_Dim, Matrix_Dim);

	// Stag 1
	for (int j = 0; j < Matrix_Dim; j++)
	{
		for (int i = j + 1; i < Matrix_Dim; i++)
		{
			int* row = &Matrix[0][0] + j*Matrix_Dim + i;
			int* col = &Matrix[0][0] + i*Matrix_Dim + j;

			*row = *row ^ *col;
			*col = *row ^ *col;
			*row = *row ^ *col;
		}
	}

	// Stag 2
	for (int j = 0; j < Matrix_Dim; j++)
	{
		for (int i = 0, k= Matrix_Dim -1; i < k; i++, k--)
		{
			int tmp = Matrix[j][i];
			Matrix[j][i] = Matrix[j][k];
			Matrix[j][k] = tmp;
		}
	}


	dump_matirx(&Matrix[0][0], Matrix_Dim, Matrix_Dim);
}










