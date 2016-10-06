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
	int in;
	cin >> in;
	string x = to_string(in);
	string x2 = x;
	
	x.erase(x.end()-1);
	x2.erase(x2.end()-2);
	
	int op1 = stoi(x);
	int op2 = stoi(x2);

	int ans = max(op1, op2);
	int real_ans = max(ans, in);
	
	cout << real_ans << endl;
}