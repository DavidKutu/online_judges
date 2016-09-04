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
	int n, len;
	string in, tmp;
	vector <string> vec;
	
	cin >> n;
	while (cin >> in)
		vec.push_back(in);
	
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		len = (*it).length();
		
		if (len > 10)
		{
			tmp = (*it).at(0) + to_string(len-2) + (*it).back();
			*it = tmp;
		}
		
		cout << *it << endl;
	}
	
	return 0;
}