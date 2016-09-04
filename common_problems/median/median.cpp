#include <iostream>
#include <iomanip>

using namespace std;
int a[200];

void merge(int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}

int main()
{
	int i, j, t, n, x=1;
	float answer;
	cin >> t;

	while (t > 0)
	{
		cin >> n;
		
		for (i = 0; i < 2*n; i++)
			cin >> a[i];

		//	LLAMADA RECURSIVA CON (N/2 o N*2)
		merge(0, 2*n-1, n-1);
		answer = (a[n-1] + a[n]) / (float) 2;
		//	FIN

		cout << "Median case " << x << ": " << fixed << setprecision(2) << answer << endl;
		x++;
		t--;
	}
	return 0;
}