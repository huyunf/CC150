/*
Write an algorithm to print all ways of arranging eight queens on a chess board so that none of them share the same row, column or diagonal.
*/

#if 1

#include <iostream>
#include <vector>
using namespace std;

#define CHESS_BOARD_N 8

#define DIAGONAL 0

void dump_v(vector<pair<int, int>> &v)
{
	for (vector<pair<int, int>>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << "[" << iter->first << "," << iter->second << "]";
	}
	cout << endl;
}

void eight_queens_puzzle(int row, vector<pair<int, int>> &v, bool diag_l, bool diag_r)
{

	if (row == CHESS_BOARD_N)
	{
		dump_v(v);
		return;
	}

	for (int i = 0; i < CHESS_BOARD_N; i++)
	{
		bool valid_col = true;

#if DIAGONAL
		if (diag_l==true && i == row)
		{
			valid_col = false;
		}
		if (diag_r==true && ((i + row) == (CHESS_BOARD_N - 1)))
		{
			valid_col = false;
		}
#else


#endif
		for (vector<pair<int, int>>::iterator iter = v.begin(); iter != v.end(); iter++)
		{
#if DIAGONAL
			if (iter->second == i) valid_col = false;
#else
			if ((iter->second == i) || (iter->first - row == iter->second - i) || (iter->first - row == i - iter->second)) valid_col = false;
#endif
		}

		if (valid_col == false)
		{
			continue;
		}
		else
		{
			v.push_back(make_pair(row, i));

#if DIAGONAL
			eight_queens_puzzle(row + 1, v, (diag_l ? diag_l : (i == row)), (diag_r ? diag_r : ((i + row) == (CHESS_BOARD_N - 1))));
#else
			eight_queens_puzzle(row + 1, v, diag_l, diag_r);
#endif
			v.pop_back();
		}
	}
}

int main()
{
	int N = 8;

	vector<pair<int, int>> v;

	eight_queens_puzzle(0, v, false, false);
}

#else



#include <iostream>
using namespace std;

int c[20], n = 8, cnt = 0;
void print() {
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<n; ++j) {
			if (j == c[i]) cout << "1 ";
			else cout << "0 ";
		}
		cout << endl;
	}
	cout << endl;
}
void search(int r) {
	if (r == n) {
		print();
		++cnt;
		return;
	}
	for (int i = 0; i<n; ++i) {
		c[r] = i;
		int ok = 1;
		for (int j = 0; j<r; ++j)
			if (c[r] == c[j] || r - j == c[r] - c[j] || r - j == c[j] - c[r]) {
				ok = 0;
				break;
			}
		if (ok) search(r + 1);
	}
}
int main() {
	search(0);
	cout << cnt << endl;
	return 0;
}

#endif