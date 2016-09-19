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
	int mem[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777}, in;
	bool do_it = true;
	cin >> in;
	int n = sizeof(mem)/sizeof(mem[0]);
	
	for (int i = 0; i < n; i++)
		if (in%mem[i] == 0)
		{
			cout << "YES" << endl;
			do_it = false;
			break;
		}
		
	if (do_it)
		cout << "NO" << endl;
}