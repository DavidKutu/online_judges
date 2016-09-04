#include<iostream>

using namespace std;
int x[500000];
int cont = 0;

void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
 
    for(i = 0; i < n1; i++)
        L[i] = x[l + i];
    for(j = 0; j < n2; j++)
        R[j] = x[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            x[k] = L[i];
            i++;
        }
        else
        {
            x[k] = R[j];
            j++;
			cont++;
        }
        k++;
    }
 
    while (i < n1)
    {
        x[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        x[k] = R[j];
        j++;
        k++;
    }
	
	if (cont != 0)
		cont = k+i-j;
}

void mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}
 

int main()
{
	int n, i;
	cin >> n;
	
	while(n != 0)
	{
		for(i = 0; i < n; i++)
			cin >> x[i];
		
		mergeSort(0, n-1);
		
		//for(i = 0; i<n; i++)
		//	cout << x[i] << " ";
		
		cout << cont << endl;
		cont = 0;
		cin >> n;
	}
	
	return 0;
}