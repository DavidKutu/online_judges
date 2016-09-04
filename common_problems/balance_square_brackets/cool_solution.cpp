#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;
long long n, m, dp[5000][5000], ans;
int minB, b;
string s;

int main()
{
	cin >> n >> m;
	cin >> s;
	dp[0][0] = 1;
	
	for(int i = 1; i <= n-m; i++)
	{
		dp[i][0] = dp[i-1][1];
		
		for(int j =1; j <= i; j++)
		{
			dp[i][j] = dp[i-1][j+1] + dp[i-1][j-1];
			dp[i][j] %= MOD;
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		if (s[i] == '(')
			b++;
		else
			b--;
		minB = min(b, minB);
	}
	
	for(int c = 0; c <= n-m; c++)
	{
		for(int d = 0; d <= c; d++)
		{
			if (d >= -minB)
			{
				if (d + b <= n-m && d + b >= 0)
					ans += dp[c][d] * dp[n - m - c][d + b] % MOD;
				ans %= MOD;
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}