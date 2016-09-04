#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int n, a, b, c, ans = 0, status = 1;
	
	cin >> n >> a >> b >> c;
	int og_n = n;
	int arr[] = {a, b, c};
	vector <int> in(arr, arr + sizeof(arr)/sizeof(int));
	sort(in.begin(), in.end());
	
	if (in[2] > n)
		in.erase(in.begin() + 2);
	
	if (in[1] > n)
		in.erase(in.begin() + 1);
	
	if (n%in[0] == 0)
	{
		cout << n/in[0] << endl;
		return 0;
	}
	
	while (n%in[0] != 0)
	{
		if (status == 1)
		{
			n -= in[1];
			ans++;
			
			if (n == 0)
				break;
			
			if (n < in[0])
			{
				n = og_n;
				status = 2;
				ans = 0;
			}
		}
		else if (status == 2)
		{
			n -= in[2];
			ans++;
			
			if (n == 0)
				break;
			
			if (n < in[0])
			{
				n = og_n;
				status = 3;
				ans = 0;
			}
		}
		else if (status == 3)
			break;
	}

	if (status != 3)
	{
		ans += n/in[0];
		cout << ans << endl;
		return 0;
	}
	
	if (a+b+c == n)
	{
		cout << 3 << endl;
		return 0;
	}
	else
	{
		//proceso iniciando con el mayor
		cout << 4 << endl;
		return 0;
	}
}