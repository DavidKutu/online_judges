/********************************************************
	David Kutugata		A01138865
*********************************************************/
#include <iostream>

using namespace std;
int n, m, cont=0, mat[10000][10000];

void snake(int x, int y)
{
	if(mat[x][y] == 0)
		return;
	else
	{
		cont++;
		mat[x][y] = 0;
	}
	
	if(x > 0)
		snake(x-1, y);
	
	if(x < n-1)
		snake(x+1, y);

	if(y > 0)
		snake(x, y-1);

	if(y < m-1)
		snake(x, y+1);
}

int main()
{
	int i, j, biggest=0;
	cin >> n >> m;
	
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			cin >> mat[i][j];

	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
		{
			snake(i, j);
			
			if(cont > biggest)
				biggest = cont;
				
			cont = 0;
		}

	cout << biggest << endl;		
	return 0;
}