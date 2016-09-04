#include <iostream>
#include <limits.h>

using namespace std;
int d[11], D[11][11] = {0}, order[11][11] = {0};
char mat = 65;

int min(int i, int j)
{
	int k, el_morro = INT_MAX, x;
	
	for (k = i; k < j; k++)
	{
		x = D[i][k]+D[k+1][j]+d[i-1]*d[k]*d[j];
		if (x < el_morro)
		{
			el_morro = x;
			order[i][j] = k;
		}
	}
	
	return el_morro;
}

void print(int i, int j)
{
	if(i == j)
		cout << " " << mat++ << " ";
	else
	{
		cout << "(";
		print(i, order[i][j]);
		print(order[i][j]+1, j);
		cout << ")";
	} 
}

int main()
{
	int n, i, j, diag;
	cin >> n;
	
	for (i = 0; i < n+1; i++)
		cin >> d[i];
	
	for (diag = 1; diag <= n-1; diag++)
		for (i = 1; i <= n-diag; i++)
		{
			j = i+diag;
			D[i][j] = min(i,j);
		}
	
	/******************************
		//Desplegar matriz
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << D[i][j] << " ";
		cout << endl;
	}
	/******************************/

	print(1, n);
	return 0;
}