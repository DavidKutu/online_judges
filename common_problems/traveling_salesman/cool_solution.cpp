#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;
int mat[20][20], visited[20], cost = 0, n;

int least(int c)
{
	int i, nc = 999;
	int min = 999, kmin;
	
	for(i = 0; i < n; i++)
		if (visited[i] == 0)
			if (mat[c][i] < min)
			{
				min = mat[c][i];
				kmin = mat[c][i];
				nc = i;
			}
	
	if (min != 999)
		cost += kmin;
	return nc;
}

void mincost(int city)
{
	int ncity;
	visited[city] = 1;
	ncity = least(city);
	
	if (ncity == 999)
	{
		ncity = 0;
		cost += mat[city][ncity];
		return;
	}
	mincost(ncity);
}

int main()
{
	int m, dis, i, j;
	char a, b;
	cin >> n >> m;
	
	//llenar matriz de adyacencias
	memset(mat, 0x70, sizeof(mat));
	memset(visited, 0, sizeof(visited));
	for (i = 0; i < m; i++)
	{
		cin >> a >> b >> dis;
		mat[a-65][b-65] = dis;
		mat[b-65][a-65] = dis;
	}

	mincost(0);
	cout << cost << endl;
	
	return 0;
}