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
	int n, i, f[100], g[100], dp[100][3];
	memset(&f, 0, sizeof(f));
	memset(&g, 0, sizeof(g));
	memset(&dp, 0, sizeof(dp));
	
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> f[i];
		g[i] = 1-f[i];
	}
	
	dp[0][0] = f[0];
	dp[0][1] = g[0];
	dp[0][2] = g[0];
	
	for (i = 1; i < n; i++)
	{
		dp[i][0] = dp[i-1][0] + f[i];
		dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + g[i];
		dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + f[i];
	}
	
	int ans = max(dp[n-1][2], dp[n-1][1]);
	
	cout << ans << endl;
}