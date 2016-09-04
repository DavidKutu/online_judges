#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath> 
#include<stack>
#include<math.h>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<complex>	
#include<assert.h>
#include<math.h>
#include<memory.h>
#include<sstream>	
#include<cstdio>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define repi(i,a,n) for(int i=a;i<n;i++)
#define INF (0x7fffffff)
#define mp make_pair
#define fastIO ios::sync_with_stdio(false)
#define read freopen("in.in","r",stdin)
#define write freopen("out.out","w",stdout)
#define scf(xx) scanf("%d",&xx)
#define All(a) a.begin(), a.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef long double ld;

#define X first
#define Y second




ll mod = 1e9 + 7;
char ss[100001];
int n, m;
ll dp[2222][2222][2];

int pre = 0, bef = 0;
int L;
ll solve(int p, int open, int take){
	if (p == L)return take && (open == 0);
	ll &ret = dp[p][open][take];
	if (ret != -1)return ret;
	ret = 0;
	if (!take){
		if (open >= pre)
			ret = (ret + solve(p + 1, open - pre +bef, 1)) % mod;
	}
	ret = (ret + solve(p + 1, open +1, take)) % mod;
	if(open)ret = (ret + solve(p + 1, open - 1, take)) % mod;
	return ret;
}
int main()
{
	//read; write;	
	cin >> n >> m;
	L = n - m + 1;
	scanf("%s", ss);
	string s(ss);
	if (n % 2){
		cout << 0;
		return 0;
	}
	
	int x = 0;
	rep(i, m){
		if (s[i] == '(') x++;
		else x--;
		if (x < 0)pre++, x++;
	}
	bef = x;
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0, 0);
	return 0;
}