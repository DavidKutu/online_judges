#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>
#include <cstring>

using namespace std;

int main()
{
	int n, i, input, f[100002];
	long long int dp[100002];
	memset(&f, 0, sizeof(f));
	memset(&dp, 0, sizeof(dp));
	
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> input;
		f[input] += input;
	}
	
	for (i = 3; i <= 100001; i++)
		dp[i] = max(f[i-2] + dp[i-2], dp[i-1]);
	
	cout << dp[100001] << endl;
}