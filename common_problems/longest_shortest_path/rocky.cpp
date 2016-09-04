#include <iostream>
#include <limits.h>

using namespace std;

int main ()
{
	int cases, n, conections, c, i, j, k, maximum, counter = 1;
	char x, y, node;
	cin >> cases;
	
	while (cases > 0)
	{
		cin >> n >> conections;
		short mat[n][n];
		
		for(i = 0; i < n ; i++)
			for(j = 0; j < n; j++)
			{
				if (i == j)
					mat[i][j] = 0;
				else
					mat[i][j] = SHRT_MAX;
			}
		
		for (i = 0; i < conections; i++)
		{
			cin >> x >> y >> c;
			
			mat[(int) x - 65][(int) y - 65] = c;
			mat[(int) y - 65][(int) x - 65] = c;
		}
		
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if((mat[i][k] * mat[k][j] != 0) && (i != j))
					{
						if ((mat[i][k] + mat[k][j] < mat[i][j]) || (mat[i][j] == 0))
							mat[i][j] = mat[i][k] + mat[k][j];
					}
		
		maximum = 0;
		for(i = 0; i < n ; i++)
			if (mat[i][0] > maximum)
			{
				maximum = mat[i][0];
				node = i;
			}

		cout << "Case " << counter++ << ": " << (char) (node + 65) << endl;
		cases--;
	}
	return 0;
}