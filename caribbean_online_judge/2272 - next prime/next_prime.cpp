#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int n;
	unsigned int i, j; //greatest=4000000;
	
	unsigned int lim = 10000000;
	int limSqRt = (int)sqrt(lim); 
	vector<bool> isPrime(lim, true);
	
	cin >> n;
	int input[n];
	
	for(i=0; i<n; i++)
		cin >> input[i];
	
	for (i=3; i<=limSqRt; i+=2)
		if (isPrime[i])
			for (j=i*i; j<=lim; j=j+i*2)
				isPrime[j] = false;
	
	for(i=0; i<n; i++)
	{
		if(input[i]==1)
			cout << 2 << endl;
		if(input[i]==4000000000u)
			cout << 4000000007u << endl;
		if(input[i]%2==0)
			input[i]+=1;
		
		for(j=input[i]; j<lim; j+=2)
			if(isPrime[j])
			{
				cout << j << endl;
				break;
			}
	}
	
	return 0;
	/**
	if(input[n]>greatest)
		{
			greatest=input[n]+100;
			primes.clear();
			findPrimes(greatest);
		}
	/**/	
}