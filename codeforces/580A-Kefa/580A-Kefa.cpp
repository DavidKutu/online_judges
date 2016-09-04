#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>

using namespace std;

int main()
{
	int n, i, input, ans = 1, cont = 1;
	vector<int> f;
	vector<int>::iterator it;
	
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> input;
		f.push_back(input);
	}
	
	for (i = 1; i < n; i++)
	{
		if (f[i-1] <= f[i])
		{
			cont++;
			if (i == n-1 && ans < cont)
				ans = cont;
		}
		else
		{
			if (ans < cont)
				ans = cont;
			cont = 1;
		}
	}
	
	cout << ans << endl;
}