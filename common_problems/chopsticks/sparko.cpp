#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int k, n, i, j, cont = 0, cont2 = 0, ans = 0;
    
    cin >> k >> n;
	int li[5001] = {0}, err[5001];
	bool se_vale[5001] = {false};

    for (i = 1; i <= n; i++)
	{
		cin >> li[i];
        err[i] = pow(li[i] - li[i-1], 2);
    }
	
	while (cont < k)
	{
		for (i = 2; i < n; i++)
		{
			if (err[i] == cont2*cont2 && !se_vale[i] && !se_vale[i-1])
			{
				if (!se_vale[i+1])	//no hay pedo con el mayor
				{
					ans += err[i];
					se_vale[i] = true;
					se_vale[i-1] = true;
					se_vale[i+1] = true;
					cont++;
				}
				else
				{
					for (j = i+4; j <= n; j++)	//+4
						if (!se_vale[j])	//existe otro mayor
						{
							ans += err[i];
							se_vale[i] = true;
							se_vale[i-1] = true;
							se_vale[j] = true;
							cont++;
							j = n+1;
						}
				}
			}
			if (err[i] == cont2*cont2 && !se_vale[i])
			{
				for (j = i+2; j <=n; j++)	//+2
					if (!se_vale[j])
					{
						ans += err[i];
						se_vale[i] = true;
						se_vale[i-1] = true;
						se_vale[i+1] = true;
						se_vale[j] = true;
						cont++;
						j = n+1;
					}
			}
			if (cont == k)
				break;
		}
		cont2++;
	}
	
    cout << ans << endl;
    return 0;
}