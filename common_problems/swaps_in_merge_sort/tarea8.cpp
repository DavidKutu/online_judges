#include<iostream>

using namespace std;

int swaps(int n, int x[])
{
	bool swapped = true;
    int j = 0, cont = 0, tmp, i;
	
    while(swapped)
	{
		swapped = false;
		j++;
		for(i = 0; i < n - j; i++)
			if(x[i] > x[i + 1])
			{
				tmp = x[i];
				x[i] = x[i + 1];
				x[i + 1] = tmp;
				swapped = true;
				cont++;
			}
    }
	
	return cont;
}

int main()
{
	int n, i, ans;
	cin >> n;
	
	while(n != 0)
	{
		int x[n];
		
		for(i = 0; i < n; i++)
			cin >> x[i];
		
		ans = swaps(n, x);
		cout << ans << endl;
		cin >> n;
	}
	
	return 0;
}