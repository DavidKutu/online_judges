#include <iostream>
#define MAX 2147483647

using namespace std;

int main()
{
	int tries, c, s, q, param1, param2, param3, test1, test2, i, j, k, cont=0;
	cin >> tries;
		
	while (tries > 0)
	{
		cin >> c;
		cin >> s;
		cin >> q;

		unsigned int mat [c][c];
		
		for(i = 0; i < c ; i++)
			for(j = 0; j < c; j++)
			{
				if (i == j)
				{
					mat[i][j] = 0;
				}
				else
				{
					mat[i][j] = MAX;
				}
			}
	
		for (i = 0; i < s; i++)
		{
			cin >> param1;
			cin >> param2;
			cin >> param3;
			
			mat[param1-1][param2-1] = param3;
			mat[param2-1][param1-1] = param3;
		}
		
		for (k = 0; k < c; k++)
			for (i = 0; i < c; i++)
				for (j = 0; j < c; j++)
					if((mat[i][k] * mat[k][j] != 0) && (i != j))
					{
						if(mat[i][k] < mat[j][k])
						{
							if(mat[j][k] < mat[i][j])
								mat[i][j] = mat[j][k];
						}
						else //mat[j][k] < mat[i][k]
						{
							if(mat[i][k] < mat[i][j])
								mat[i][j] = mat[i][k];
						}
					}
		
		cout << "Case " << ++cont << ":" << endl;
		
		for (i= 0; i < q; i++)
		{
			cin >> test1;
			cin >> test2;
			/**/
			if (mat[test1-1][test2-1] == MAX)
				cout << "no path" << endl;
			else
				cout << mat[test1-1][test2-1] << endl;
		}
		/**/
		tries--;
	}
	return 0;
}