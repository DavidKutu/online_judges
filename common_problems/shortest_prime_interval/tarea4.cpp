#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <set>
#include <stdint.h>

using namespace std;
set<uint64_t> primes;
set<uint64_t>::iterator it;

void findPrimes(int lim)
{
	int limSqRt = (int)sqrt((double)lim), i, j;
	bool *isPrime = new bool[lim + 1];
	memset(isPrime, 1, sizeof(bool)*(lim + 1));
	
	for (i=2; i<=limSqRt; i++)
		if (isPrime[i])
			for (j=i*i; j<=lim; j+=i)
				isPrime[j] = false;
	
	/*Put in set*/
	for (i=2; i<=lim; i++)
		if (isPrime[i])
			primes.insert(i);
		
	delete [] isPrime;
}

int main ()
{
	findPrimes(100000);
	int m, i, menor, mayor;
	cin >> m;
	int input[m];

	for(i=0; i<m; i++)
		cin >> input[i];
	
	for(i=0; i<m; i++)
		for(it=primes.begin(); it!=primes.end(); ++it)
		{
			if(*it>input[i])
			{
				mayor=*it;
				it--;
				cout << *it << " " << mayor << endl;
				break;
			}
			if(*it==input[i])
			{
				cout << *it << " " << *it << endl;
				break;
			}
		}
}