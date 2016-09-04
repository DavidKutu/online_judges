#include <iostream>
#include <cstring>

using namespace std;

int mat[1001][1001];

int max (int a, int b)
{
	if (a < b)
		return b;
	return a;
}

int main()
{
	int t, n, g, i, j, k, ans;
	cin >> t;
	
	while (t > 0)
	{
		cin >> n;
		int p[n], w[n];
		
		for (i = 0; i < n; i++)
			cin >> p[i] >> w[i];
		
		cin >> g;		
		int mw[g];
		
		for (i = 0; i < g; i++)
			cin >> mw[i];
		
		ans = 0;
		for (i = 0; i < g; i++)
		{
			memset(mat, 0, sizeof(mat));
			for (j = 1; j <= n; j++)
				for (k = 1; k <= mw[i]; k++)
					if (w[j-1] <= k)
						mat[j][k] = max(mat[j-1][k], mat[j-1][k-w[j-1]] + p[j-1]);
					else
						mat[j][k] = mat[j-1][k];
					
			ans += mat[n][mw[i]];
		}
		
		cout << ans << endl;
		t--;
	}
	return 0;
}