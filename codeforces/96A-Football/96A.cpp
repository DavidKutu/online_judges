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
	
	cin >> in;
	char prev = in[0];
	int cont = 1;
	bool ans = false;
	
	for (int i = 0; i < in.length(); i++)
	{
		if (in[i] == prev)
		{
			cont++;
			if (cont >= 7)
				ans = true;
		}
		else
		{
			prev = in[i];
			cont = 1;
		}
	}
	
	if (ans)
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
}