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
set<int> all_primes;

void findPrimes(unsigned int lim)
{
	unsigned int i, j;
	//unsigned int lim=1500;
	int limSqRt = (int)sqrt(lim); //63245
	vector<bool> isPrime(lim, true);
	
	for (i=3; i<=limSqRt; i+=2)				//for (i=2; i<=limSqRt; i++)
		if (isPrime[i])
			for (j=i*i; j<=lim; j=j+i*2)	//for (j=i*i; j<=lim; j+=i)
				isPrime[j] = false;
	
	/*Put in set*/
	//cout << 1 << endl << 2 << endl;
	for (i=3; i<=lim; i+=2)
		if (isPrime[i])
			all_primes.insert(i);
}

int main()
{
	unsigned int n, x = 4;
	cin >> n;
	findPrimes(n);
	
	auto it = all_primes.begin();
	while ((n-x)%(*it) != 0)
	{
		x += 2;
		if (x >= n)
		{
			it++;
			x = 4;
		}
	}
	
	cout << x << " " << n-x << endl;
}