#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>

using namespace std;

int main()
{
	int n, m, i, input, ans = INT_MAX, temp;
	vector<int> f;
	vector<int>::iterator it;
	
	cin >> n >> m;
	
	for (i = 0; i < m; i++)
	{
		cin >> input;
		f.push_back(input);
	}
	
	sort(f.begin(), f.end());
	
	for (int begin = 0, end = n-1; end < m; begin++, end++)
	{
		temp = *(f.begin()+end)-*(f.begin()+begin);
		if (temp < ans)
			ans = temp;
	}
	
	cout << ans << endl;
}