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
	vector <char> input;
	vector <char> out;
	string n;
	
	char table[6][3] = {
						{'r','b','p'},
						{'y','r','o'},
						{'y','b','g'},
						{'r','l','r'},
						{'b','l','b'},
						{'l','y','y'},
						};
	
	while (cin >> n)
	{
		if(n.size() == 3)
			input.push_back('r');
		else if(n.size() == 4)
			input.push_back('b');
		else if(n.size() == 5)
		{
			if (n[0] == 'g')
				input.push_back('g');
			else if (n[0] == 'b')
				input.push_back('l');
		}
		else if(n.size() == 6)
		{
			if (n[0] == 'y')
				input.push_back('y');
			else if (n[0] == 'o')
				input.push_back('o');
			else if (n[0] == 'p')
				input.push_back('p');
		}
	}
	
	auto it1 = input.begin();
	out.push_back(*it1);
	
	//cout << *it << endl;
	/**/
	for (auto it = input.begin()+1, it2 = out.begin(); it != input.end()-1; ++it, ++it2)
	{
			for (int i = 0; i < 6; i++)
			{
				if (*it == table[i][2])
				{
					if (*it2 == table[i][0])
					{
						out.push_back(table[i][1]);
					}
					else //if (*it2 == table[i][1])
					{
						out.push_back(table[i][0]);
					}
					
					break;
				}
			}
	}
	/**/
	auto it3 = input.end();
	out.push_back(*it3);
	
	for (auto it = out.begin(); it != out.end(); it++)
	{
		cout << *it << ' ';
	}
	/**/
	return 0;
}