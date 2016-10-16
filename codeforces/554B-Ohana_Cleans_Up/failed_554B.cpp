#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdint>
#include <cstring>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int iexp(int base, int expo)
{
	if (expo == 0)
		return 1;
	
	int res = 1;
	
	for (int i = 0; i < expo; i++)
		res *= base;
	
	return res;
}

int main()
{
	int n, ans = 0, biggest = 0;
	cin >> n;
	string x[n], y[n], test;
	uint64_t mask = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		test.push_back('1');
	}
	
	//check all combinations which are 2^n
	int lim = iexp(2, n);
	for (int i = 0; i < lim; i++)
	{
		//return 'y' to original
		for (int j = 0; j < n; j++)
			y[j] = x[j];
		
		//change columns according to mask
		for (int j = 0; j < n; j++)		//this for is used to travel the whole mask
			if (mask & (1 << j))
				for (int k = 0; k < n; k++)	//this goes vertically to swap values of columns
				{
					//y[k][j] = 1 - y[k][j];
					if (y[k][j] == '1')
						y[k][j] = '0';
					else
						y[k][j] = '1';
				}
		
		//check if rows are equal to "11111111..."
		for (int j = 0; j < n; j++)
			if (!y[j].compare(test))
				ans++;
				
		//increment mask and update answer
		mask++;
		biggest = max(ans, biggest);
		ans = 0;
	}
	
	cout << biggest << endl;
}