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
	string in;
	int num[3] = {0};
	cin >> in;
	
	for (int i = 0; i < in.length(); i++)
	{
		if (in[i] == '1')
			num[0]++;
		else if (in[i] == '2')
			num[1]++;
		else if (in[i] == '3')
			num[2]++;
	}
	
	while (num[0] > 0)
	{
		cout << 1;
		num[0]--;
		if (num[1] != 0 || num[2] != 0 || num[0] > 0)
			cout << "+";
	}
	
	while (num[1] > 0)
	{
		cout << 2;
		num[1]--;
		if (num[2] != 0 || num[1] > 0)
			cout << "+";
	}
	
	while (num[2] > 0)
	{
		cout << 3;
		num[2]--;
		if (num[2] > 0)
			cout << "+";
	}
	
	cout << endl;
}