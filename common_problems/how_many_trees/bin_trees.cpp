#include <iostream>

using namespace std;
unsigned long long A[31];
	
unsigned long long sum (int n)
{
	unsigned long long acum = 0;
	
	for (int i = 0; i < n; i++)
		acum += A[i]*A[n-1-i];
	
	return acum;
}

int main()
{
	A[0] = 1;
	A[1] = 1;
	int n, i;
	cin >> n;

	for (i = 2; i <= n; i++)
		A[i] = sum(i);
	
	cout << A[n] << " BTrees" << endl;
	
	return 0;
}