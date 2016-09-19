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
	string in1, in2;
	cin >> in1 >> in2;
	
	for (int i = 0; i < in1.length(); i++)
	{
		if (in1.at(i) < 97)
			in1.at(i) += 32;
		
		if (in2.at(i) < 97)
			in2.at(i) += 32;
	}
	
	if (in1.compare(in2) == 0)
		cout << 0 << endl;
	else if (in1.compare(in2) < 0)
		cout << -1 << endl;
	else if (in1.compare(in2) > 0)
		cout << 1 << endl;
}