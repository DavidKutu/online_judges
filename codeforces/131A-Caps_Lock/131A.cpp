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
	bool first_lower = false;
	int upper = 0;
	string in;
	cin >> in;
	
	if (in[0] < 97)
		upper++;
	else
		first_lower = true;
	
	for (int i = 1; i < in.length(); i++)
		if (in[i] < 97)
			upper++;
		
	if (upper == in.length() || (first_lower && upper == in.length()-1))
	{
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] < 97)
				in[i] += 32;
			else
				in[i] -=32;
		}
		
		cout << in << endl;
	}
	else
		cout << in << endl;
}