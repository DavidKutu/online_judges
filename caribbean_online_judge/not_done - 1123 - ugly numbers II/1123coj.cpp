#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void findUgly(int n)
{
	int cont = 0, i, j, limit = 20*n + 1;
	unsigned int lim=13500;
	int limSqRt = (int)sqrt(lim); //63245
	vector<bool> isPrime(lim, true);
	vector <bool> ugly(limit, 1);
	vector <bool>::iterator it;
	
	for (i=3; i<=limSqRt; i+=2)				//for (i=2; i<=limSqRt; i++)
		if (isPrime[i])
			for (j=i*i; j<=lim; j=j+i*2)	//for (j=i*i; j<=lim; j+=i)
				isPrime[j] = false;
	/**/
	for (i = 2; i <= limit; i++)
		for (j = 7; j <= lim; j+=2)
			if (isPrime[j])
				if (i%j == 0)
					ugly[i] = 0;
	/**/
	for (i = 1; i <= limit; i++)
	{
		if (ugly[i] == 1)
			cont++;
		
		if (cont == n)
			break;
	}
	
	cout << i << endl;
	/**
	for (i = 1; i <= limit; i++)
	{
		if (ugly[i] == 1)
			cout << i << endl;
	}
	/**/
}

int main ()
{
	int n;
	cin >> n;
	
	while (n != 0)
	{
		findUgly(n);
		cin >> n;
	}
	
	return 0;
}