#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

struct point
{
	double x, y;
};

int main()
{
	int n, i, j, c = 0, temp = 0, temp1 = 0;
	double sum = 0, min;
	cin >> n;
	point m[100];
	bool a[100] = {0};
	double dis_mat[100][100] = {0};

	for (i = 0; i < n; i++)
		cin >> m[i].x >> m[i].y;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			dis_mat[i][j] = sqrt((m[i].x - m[j].x)*(m[i].x - m[j].x) + (m[i].y - m[j].y)*(m[i].y - m[j].y));
	
	/**		Start Prim		**/
	a[0] = 1;
	while(c < n-1)
    {
        min = INT_MAX;
        for(i = 0; i < n; i++)
        {
            if(a[i] == 1)
			{
                for(j = 0; j < n; j++)
				{
                    if(a[j] == 0)
					{
                        if(min > dis_mat[i][j])
                        {
                            min = dis_mat[i][j];
							temp1 = i;
                            temp = j;
                        }
                    }
                }
            }
        }
        a[temp] = 1;
        sum += min;
		//cout << endl << temp1 + 1 << " --> " << temp + 1 << endl;
        c++;
    }
	/**		End Prim		**/
	/**
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout.precision(2);
			cout << fixed << dis_mat[i][j] << "\t";
		}
		cout << endl;
	}
	/**/
	cout.precision(2);
    cout << fixed << sum << endl;
	
	return 0;
}