#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	int len, i, ones=0, ceros=0;
	string str;
	
	cin >> len;
	cin >> str;	

	/**/
	for(i=0; i<len; i++)
	{
		if(str[i]=='1')
			ones++;
		else
			ceros++;
	}
	/**/
	if(ceros>ones)
		len=len-2*ones;
	else
		len=len-2*ceros;
	/**/	
	
	cout << len << endl;
	return 0;
}