/*
Imagine a robot sitting on the upper left hand corner of an NxN grid. The robot can only move in two directions: right and down. How many possible paths are there for the robot?

FOLLOW UP

Imagine certain squares are “off limits”, such that the robot can not step on them. Design an algorithm to get all possible paths for the robot.
*/


#include <iostream>
#include <vector>
using namespace std;

bool check_valid(int n_x, int n_y, vector<pair<int, int>>* p)
{
	for (int i = 0; i < p->size(); i++)
	{
		if (n_x == p->at(i).first && n_y == p->at(i).second)
			return false;
	}

	return true;
}

void Robot_Path(int x, int y, vector<pair<int, int>>* v, vector<pair<int, int>>* p)
{
	if (x == 0 && y == 0)
	{
		pair<int, int> cur(x, y);

		v->push_back(cur);

		for (int i = 0; i < v->size(); i++)
		{
			cout << "[" << v->at(i).first << "," << v->at(i).second << "]" << ((i == v->size() - 1) ? "\n" : "->");
		}
	}
	else
	{
		pair<int, int> cur(x, y);

		v->push_back(cur);

		if (x == 0)
		{
			if(check_valid(x, y-1, p))
				Robot_Path(x, y - 1, v, p);
		}
		else if (y == 0)
		{
			if (check_valid(x-1, y, p))
				Robot_Path(x - 1, y, v, p);
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
				{
					if (check_valid(x, y - 1, p))
						Robot_Path(x, y - 1, v, p);
				}
				else 
				{
					if (check_valid(x - 1, y, p))
						Robot_Path(x - 1, y, v, p);
				}
			}
		}
	}

	v->pop_back();

	return;
}

int main()
{
	int N = 4;

	vector<pair<int, int>>* v = new vector<pair<int, int>>;

	vector<pair<int, int>>* p = new vector<pair<int, int>>;

	//p->push_back(make_pair(0, 1));

	Robot_Path(N-1, N-1, v, p);
}


