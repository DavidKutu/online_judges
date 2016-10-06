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
	int count_lower = 0, count_upper = 0;
	string s;
	cin >> s;
	
	for (int i = 0; i < s.length(); i++)
		if (s[i] < 97)
			count_upper++;
		else
			count_lower++;
	
	if (count_upper > count_lower)
	{
		//imprime mayusculas
		for (int i = 0; i < s.length(); i++)
			if (s[i] > 96)
				s[i] -= 32;
		cout << s << endl;
		return 0;
	}
	else 
	{
		//imprime minusculas
		for (int i = 0; i < s.length(); i++)
			if (s[i] < 97)
				s[i] += 32;
		cout << s << endl;
		return 0;
	}
}