#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void findPrimes()
{
	unsigned int i, j;
	unsigned int lim=1500;
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
			cout << i << endl;
}

int main()
{
	findPrimes();
	//double x = sqrt(4000000000u);
	//cout << x << endl;
}