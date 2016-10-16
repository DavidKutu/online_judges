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

int main()
{
	int n, ans = 0, biggest = 0, initial = 0;
	cin >> n;
	string x[n], test;

	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		test.push_back('1');
	}
	
	for (int i = 0; i < n; i++)
		if (!x[i].compare(test))
			initial++;
		
	if (initial == n)
	{
		cout << initial << endl;
		return 0;
	}
		
	biggest = max(initial, biggest);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
			if (!x[i].compare(x[j]))
				ans++;
			
		biggest = max(ans+1, biggest);
		ans = 0;
	}
	
	cout << biggest << endl;
}