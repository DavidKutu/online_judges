/*********************************************************
	Éste código usa el algritmo ya existente de convex 
	hull para resolver la cerca mas chica, no se me 
	ocurrió otra forma para resolverlo.
/*********************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point
{
	long int x, y;
	
	//se tiene que sobrecargar este operador para que sort() funcione
	bool operator < (const point &p)const
	{
		return (x < p.x || (x == p.x && y < p.y));
	}
};

int main()
{
	int n, i, k = 0, t;
	double per = 0;
	cin >> n;
	
	vector <point> beagles;
	beagles.resize(n);
	vector <point> border;
	border.resize(2*n);
	
	//se guardan los datos
	for (i = 0; i < n; i++)
		cin >> beagles[i].x >> beagles[i].y;
	
	//se usa vector y algorithm para ordenarlos facil
	sort(beagles.begin(),beagles.end());
	
	//se saca la cerca por abajo, empezando de la coordenada x menor
	for (i = 0; i < n; ++i)
	{
		//se revisan los puntos anteriores en la cerca
		while (k >= 2 && (border[k-1].x - border[k-2].x)*(beagles[i].y - border[k-2].y)-(border[k-1].y - border[k-2].y)*(beagles[i].x - border[k-2].x) <= 0)
			k--;
		border[k++] = beagles[i];
	}

	//se regresa y se saca la cerca por arriba
	for (i = n-2, t = k+1; i >= 0; i--)
	{
		//se revisan los puntos anteriores en la cerca
		while (k >= t && (border[k-1].x - border[k-2].x)*(beagles[i].y - border[k-2].y)-(border[k-1].y - border[k-2].y)*(beagles[i].x - border[k-2].x) <= 0)
			k--;
		border[k++] = beagles[i];
	}
	
	border.resize(k);
	
	//se saca el perimetro
	for (i = 0; i < k-1; i++)
        per += sqrt(pow(border[i].x-border[i+1].x,2) + pow(border[i].y-border[i+1].y,2));

	cout << "The perimeter of the wall is: " << fixed << setprecision(2) << per << endl;
	
	return 0;
}