#include <iostream>

using namespace std;
short mat[9][9] = {0};

bool check(int x, int y)
{
	if (x > 9 || y > 9)
		return false;
	
	int i, j, i_start, i_end, j_start, j_end;
	//check row
	for (i = 0; i < 9; i++)
	{
		if (x != i)
			if (mat[x][y] == mat[i][y])
				return false;
	}
	
	//check column
	for (i = 0; i < 9; i++)
	{
		if (y != i)
			if (mat[x][y] == mat[x][i])
				return false;
	}
	
	//check box
	if (x > 5)
	{
		i_start = 6;
		i_end = 9;
	}
	else if (x < 3)
	{
		i_start = 0;
		i_end = 3;
	}
	else
	{
		i_start = 3;
		i_end = 6;
	}
	
	if (y > 5)
	{
		j_start = 6;
		j_end = 9;
	}
	else if (y < 3)
	{
		j_start = 0;
		j_end = 3;
	}
	else
	{
		j_start = 3;
		j_end = 6;
	}
	
	for (i = i_start; i < i_end; i++)
	{
		for (j = j_start; j < j_end; j++)
		{
			if (x != i && y != j)
				if (mat[x][y] == mat[i][j])
					return false;
		}
	}
	
	return true;
}

int main()
{
	short n, i, j, a, x, y, cont = 1;
	bool reset = 1, flag = 0;
	cin >> n;
	
	/**********************
		fill base board
	**********************/
	for (i = 0; i < n; i++)
	{
		cin >> a >> x >> y;
		mat[x][y] = a;
	}
	/*********************/
	
	/******************************************************************
		process
	******************************************************************/
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if (mat[i][j] == 0)
			{
				mat[i][j] = cont;
				
				while (!check(i, j) || flag)
				{
					cont++;
					if (cont > 9)
					{
						if (j == 0)
						{
							i--;
							j = 8;
						}
						else
						{
							j--;
						}
						
						cont = mat[i][j];
						mat[i][j] = 0;
						//j--;
						reset = 0;
						flag = true;
						break;
					}
					else
					{
						mat[i][j] = cont;
						flag = false;
					}
					reset = 1;
				}
				
				if (reset == 1)
					cont = 1;
			}
	/*****************************************************************/
	
	/******************************************************************
		print result
	******************************************************************/
	cout << endl;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j == 3 || j == 6)
				cout << "|  " << mat[i][j] << "  ";
			else
				cout << mat[i][j] << "  ";
		}
		if (i == 2 || i == 5)
			cout << endl << "- - - - - - - - - - - - - - - -" << endl;
		else
			cout << endl;
	}
	/*******************************************************************/
	
	return 0;
}