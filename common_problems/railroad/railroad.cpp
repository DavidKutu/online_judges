#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n1 = 1, n2 = 1, i, j;
	int arr1[1000], arr2[1000], arr3[2000], mat[1001][1001];
	cin >> n1 >> n2;
	
	while (n1 != 0 || n2 != 0)
	{		
		for (i = 0; i < n1; i++)
			cin >> arr1[i];
		
		for (i = 0; i < n2; i++)
			cin >> arr2[i];
		
		for (i = 0; i < n1+n2; i++)
			cin >> arr3[i];
		
		memset(mat, 0, sizeof(mat));
		mat[0][0] = 1;
		
		for (i = 0; i <= n1; i++)
			for (j = 0; j <= n2; j++)
				if(mat[i][j] == 1)
				{
                    if(i <= n1 && arr1[i] == arr3[i + j])
						mat[i + 1][j] = 1;
					
                    if(j <= n2 && arr2[j] == arr3[i + j])
						mat[i][j + 1] = 1;
                }
			
		if(mat[n1][n2] == 1)
			cout << "possible" << endl; 
        else   
            cout << "not possible" << endl;
		
		cin >> n1 >> n2;
	}
	
	return 0;
}