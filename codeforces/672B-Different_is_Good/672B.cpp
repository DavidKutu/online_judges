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
	int n, abc[27] = {0}, cont = 0, ans = 0;
	string s;
	cin >> n >> s;
	
	for (int i = 0; i < n; i++)
	{
		abc[s[i] - 97]++;
		cont++;
		if (abc[s[i] - 97] > 1)
			ans++;
	}
	
	if (cont > 26)
	{
		cout << -1 << endl;
		return 0;
	}
	
	cout << ans << endl;
	return 0;
}