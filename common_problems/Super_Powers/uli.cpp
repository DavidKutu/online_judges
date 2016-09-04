#include <iostream>
#include <cstdint>
#include <set>

using namespace std;

const int ex[] = {	 4,  6,  8,  9, 10, 12, 14, 15, 16, 18, 
					20, 21, 22, 24, 25, 26, 27, 28, 30, 32, 
					33, 34, 35, 36, 38, 39, 40, 42, 44, 45, 
					46, 48, 49, 50, 51, 52, 54, 55, 56, 57, 
					58, 60, 62, 63, 64
				 };

uint64_t ipow(uint64_t base, int expo)
{
	uint64_t res = base, temp;
	while (expo > 1)
	{
		temp = res*base;
	
		if (res != 0 && temp/res != base)
			return 0;
		
		res = temp;
		expo--;
	}
	return res;
}

int main()
{
	int i, j;
	uint64_t temp;
	set <uint64_t> ans;

	ans.insert(1);
	
	for (i = 2; i <= 100000; i++)
		for (j = 0; j < 45; j++)
		{
			temp = ipow(i, ex[j]);
			
			if (temp != 0)
				ans.insert(temp);
		}

	for(auto it = ans.begin(); it != ans.end(); it++)
		cout << *it << endl;

	return 0;
}