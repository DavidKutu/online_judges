/**********************************************************
	Con la pena profe, pero éste código no hace nada,
	quiero dedicarle el tiempo, pero mi proyecto integrador
	no va a salir, necesito darle todo mi fin de semana.
**********************************************************/
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int mat[20][20], n;

struct nodo
{
	//string camino;
	int costo_posible;
	int nivel;
	nodo *hijos[19];
	
	bool operator < (const nodo &p)const
	{
		return (costo_posible < p.costo_posible);
	}
};
/**/

void visitar (nodo *r)
{
	// se saca el costo posible, se crean los hijos
}

void nivelXnivel (nodo *r)
{
	int i;
	nodo *no, *h; 
	vector<nodo> f(1, *r);
	
	while (!f.empty())
	{ 
		no = &f.front();
		visitar(no);
		f.erase(f.begin());
		
		for (i = 0; i < (n - no->nivel); i++)
		{
			h = no->hijos[i];
			f.push_back(*h);
			sort(f.begin(), f.end());
		}
	}
}
/**/

int main()
{
	int m, dis, i, j;
	char a, b;
	cin >> n >> m;
	
	//llenar matriz de adyacencias
	memset(mat, 0x70, sizeof(mat));
	for (i = 0; i < m; i++)
	{
		cin >> a >> b >> dis;
		mat[a-65][b-65] = dis;
		mat[b-65][a-65] = dis;
	}

	//sacar primer nodo
	nodo *base;
	base = new nodo;
	base->costo_posible = 0;
	base->nivel = 1;
	set<int> cp;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cp.insert(mat[i][j]);

		base->costo_posible += *cp.begin();
		cp.clear();
	}
	
	for (i = 0; i < n-base->nivel; i++)
		base->hijos[i] = new nodo;
	
	nivelXnivel(base);
	
	//cout << base->costo_posible << endl;
	
	return 0;
}