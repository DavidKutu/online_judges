#include <iostream>
#include <cstring>

using namespace std;
 
int max(int a, int b)
{
	if (a > b)
		return a;
	
	return b;
}

int main()
{
	int n, i, j, len1, len2, m = 1, res;
	string str1, str2;
	cin >> n;
	
	while (n > 0)
	{
		cin >> str1 >> str2;
		len1 = str1.length();
		len2 = str2.length();
		
		int mat[len1+1][len2+1];
		res = 0;
		
		for (i = 0; i <= len1; i++)
			for (j = 0; j <= len2; j++)
			{
				if (i == 0 || j == 0)
					mat[i][j] = 0;
				else if (str1[i-1] == str2[j-1])
				{
					mat[i][j] = mat[i-1][j-1] + 1;
					res = max(res, mat[i][j]);
				}
				else
					mat[i][j] = 0;
			}
		
		cout << "Case " << m++ << ": " << res << endl;   
		n--;
	}
	  
	return 0;
}