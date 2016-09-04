/********************************************************
	David Kutugata		A01138865
*********************************************************/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string str;
	int i;
	
	cin >> str;
	
	for(i=0; i<str.length(); i++)
		str[i] = 155 - str[i];		//str[i] = str[i] + 25 - 2*(str[i] - 65);
	
	cout << str << endl;
	return 0;
}