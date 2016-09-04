#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int k, n, i, j;
    
    cin >> k >> n;
	int li[5001] = {0}, error[5001], diff[5001] = {0};

    for (i = 1; i <= n; i++)
	{
		cin >> li[i];
        error[i] = pow(li[i] - li[i-1], 2);
    }
	//https://acm-uva-ufrgs.googlecode.com/svn/trunk/%20acm-uva-ufrgs/Contest%20Volumes/Volume%20CII/10271.cpp
	/******************************************************
		proceso tomado de internet, no comprendo bien
		que se esta haciendo, después de 7 horas me rendi.
		Mi mejor intento fue el anterior a este.
	*******************************************************/
    for (i = 1; i <= k; i++)
	{
		for (j = (n-3*(k-i)-1); j >= 2*i; j--)
			diff[j] = diff[j-2] + error[j];
		
        for (j = (2*i)+1; j <= (n-3*(k-i)-1); j++)
			if(diff[j-1] < diff[j])
				diff[j] = diff[j-1];
		
        diff[n-3*(k-i)] = diff[n-3*(k-i)-1];
	}
	/*******************************************************/
	
    cout << diff[n] << endl;
    return 0;
}