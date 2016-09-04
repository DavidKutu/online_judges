/********************************************************
	David Kutugata		A01138865
*********************************************************/

#include <iostream>

using namespace std;
int mat [32][32];

void triomino(int x1, int x2, int y1, int y2, int a, int b, int cont)
{	
	int xm = (x1+x2)/2;
	int ym = (y1+y2)/2;
	if(x2-x1 == 1 && y2-y1 == 1)
	{
		int i, j;
		for(i = x1; i < x2; i++)
			for(j = y1; j < y2; j++)
				if(mat[i][j] < 0)
					mat[i][j] = cont;
	}
	else
	{
		if(a < xm)
		{
			if(b < ym)
			{
				mat[xm][ym-1] = cont;
				mat[xm-1][ym] = cont;
				mat[xm][ym] = cont;
				/**/
				triomino(x1, xm, y1, ym, a, b, cont+1);
				triomino(xm, x2, y1, ym, xm, ym-1, cont+5);
				triomino(x1, xm, ym, y2, xm-1, ym, cont+10);
				triomino(xm, x2, ym, y2, xm, ym, cont+15);
				/**/
			}
			else //b >= y2/2
			{
				mat[xm-1][ym-1] = cont;
				mat[xm][ym-1] = cont;
				mat[xm][ym] = cont;
				/**/
				triomino(x1, xm, y1, ym, xm-1, ym-1, cont+1);
				triomino(xm, x2, y1, ym, xm, ym-1, cont+5);
				triomino(x1, xm, ym, y2, a, b, cont+10);
				triomino(xm, x2, ym, y2, xm, ym, cont+15);
				/**/
			}
		}
		else //a >= x2/2
		{
			if(b < ym)
			{
				mat[xm-1][ym-1] = cont;
				mat[xm-1][ym] = cont;
				mat[xm][ym] = cont;
				/**/
				triomino(x1, xm, y1, ym, xm-1, ym-1, cont+1);
				triomino(xm, x2, y1, ym, a, b, cont+5);
				triomino(x1, xm, ym, y2, xm-1, ym, cont+10);
				triomino(xm, x2, ym, y2, xm, ym, cont+15);
				/**/
			}
			else //b >= y2/2
			{
				mat[x2/2-1][y2/2-1] = cont;
				mat[x2/2][y2/2-1] = cont;
				mat[x2/2-1][y2/2] = cont;
				
				/******************************************************
				No tengo idea por que, pero a menos que se comenten las
				siguientes llamadas, el programa truena. Pero creo que 
				la lógica es correcta. Lo quiero ver en asesoria.
				*******************************************************/
				
				triomino(x1, xm, y1, ym, xm-1, ym-1, cont+1);
				triomino(xm, x2, y1, ym, xm, ym-1, cont+5);
				triomino(x1, xm, ym, y2, xm-1, ym, cont+10);
				triomino(xm, x2, ym, y2, a, b, cont+15);
				/**/
			}
		}
	}
}

int main()
{
	int n, x, y, i, j;
	cin >> n >> x >> y;
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			mat[i][j] = -1;
		
	mat[x][y] = 0;
	
	triomino(0, n, 0, n, x, y, 2);
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			cout << mat[i][j] << '\t';
		
		cout << endl;
	}
	return 0;
}