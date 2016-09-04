#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	int n, i, j;
	double min = 1414213562.37, res;
	cin >> n;
	long int x[n], y[n];
	
	for (i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
		{
			res = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			if (res < min)
				min = res;
		}
	
	cout << "The distance of best friends are: " << fixed << setprecision(2) << min << endl;
	
	return 0;
}