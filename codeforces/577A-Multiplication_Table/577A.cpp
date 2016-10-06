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
	long long int n, x;
	int ans = 0;
	cin >> n >> x;
	
	if (x > n*n)
	{
		cout << 0 << endl;
		return 0;
	}
	
	long long int minimum = min(n, x);
	for (long long int i = minimum; i >= 1; i--)
		if (x%i == 0 && x/i <= n)
			ans++;
	
	cout << ans << endl;
}