#include <iostream>
#include <set>

using namespace std;
int M[51][51];

int minimo(int i, int k)
{
	int w, e;
	set <int> min;

	for (w = i, e = 0; w < k; w++, e++)
		min.insert(M[i][w] + M[w+1][k]);

	return *min.begin();
}

int main()
{
	int i, j, k, l, n, ci[51];
	cin >> l;

	while (l != 0)
	{
		cin >> n;
		
		for (i = 1; i <= n; i++)
			cin >> ci[i];

		ci[0] = 0;
		ci[n+1] = l;

		//	FILL MATRIX
		for (i = 0; i <= n; i++)
			M[i][i] = 0;

		for (j = 0; j <= n; j++)
			for(i = 0; i < n+1-j; i++)
			{
				k = i + j + 1;
				M[i][k] = minimo(i, k) + ci[k+1] - ci[i];
			}

		// DONE WITH MATRIX

		cout << "The minimum cutting is " << M[0][n] << "." << endl;
		cin >> l;
	}
	return 0;
}