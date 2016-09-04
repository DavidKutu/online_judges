#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
double menor;
bool mat[10000][10000] = {0};

void conker (int min, int max)
{
	
}

int main()
{
	int n, i;
	cin >> n;
	long int x[n], y[n], mayor = 0;
	
	for (i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		if (x[i] > y[i])
		{
			if (x[i] > mayor)
				mayor = x[i];
		}
		else //y[i] > x[i]
		{
			if (y[i] > mayor)
				mayor = y[i];
		}
	}
	
	for (i = 0; i < n; i++)
		mat[x[i]][y[i]] = 1;
	
	conker (0, mayor);
	
	cout << "The distance of best friends are: " << fixed << setprecision(2) << menor << endl;
	
	return 0;
}