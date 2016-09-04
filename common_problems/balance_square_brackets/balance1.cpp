#include <iostream>
#include <cstring>

using namespace std;

int min(int a, int b)
{
	if (a < b)
		return a;
	
	return b;
}

int main()
{
	int n, m, i, j, ans = 0, open_bkts = 0, mat[100][100], el_morro = 0;
	int x = (1e9+7);
	string s;
	cin >> n >> m >> s;
	memset(mat, 0, sizeof(mat));
	
	mat[0][0] = 1;
	for (i = 1; i <= n; i++)
		for (j = 0; j <= n; j++)
		{
			if (i == j)
				mat[i][j] = 1;
			else
			{
				if (j == 0)
					mat[i][j] = mat[i-1][j+1];
				else if (j == n)
					mat[i][j] = mat[i-1][j-1];
				else
					mat[i][j] = mat[i-1][j+1] + mat[i-1][j-1];
			}
		}
	/**
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= n; j++)
			cout << mat[i][j] << ' ';
		cout << endl;
	}
	/**/
	
	for (i = 0; i < m; i++)
	{
		if (s[i] == '[')
			open_bkts++;
		else
			open_bkts--;
		
		el_morro = min(open_bkts, el_morro);
	}
	
	for (i = 0; i <= n - m; i++)
		for (j = 0; j <= i; j++)
			if (j + open_bkts <= n - m && j + open_bkts >= 0 && j >= el_morro*-1)
				ans += mat[i][j] * mat[n - m - i][j + open_bkts] % x;
				
	cout << ans << endl;
	return 0;
}