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
	string in, point = "..";
	
	cin >> in;
	
	for (int i = 0; i < in.length(); i++)
	{
		if (in.at(i) < 97)
			in.at(i) += 32;
		
		if (in.at(i) == 97 || in.at(i) == 101 || in.at(i) == 105 || in.at(i) == 111 || in.at(i) == 117 || in.at(i) == 121)
		{
			in.erase(i,1);
			i--;
		}
	}
	
	for (int i = 0; i < in.length(); i++)
		cout << '.' << in[i];
	
	cout << endl;
	return 0;
}