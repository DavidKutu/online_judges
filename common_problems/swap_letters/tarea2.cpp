#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	int len, i, j, temp1, temp2;
	string name;
	char c1, c2, temp3;
	const char abcbase[] = 
					 {'a','b','c','d','e','f','g','h','i','j','k','l','m',
				      'n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char abcmod[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
				     'n','o','p','q','r','s','t','u','v','w','x','y','z'};

	/****************************************************************
	Recive los datos de la terminal
	****************************************************************/
	cin >> len;
	cin >> name;
	char in[len][2];
	
	for(i=0; i<len; i++)
	{
		cin >> c1 >> c2;
		in[i][0]=c1;
		in[i][1]=c2;
	}
	/***************************************************************/
	
	/****************************************************************
	Hace Todos los cambios de letras en el abecedario interno
	****************************************************************/
	for(i=0; i<len; i++)
		if(in[i][0]!=in[i][1])
		{
			for(j=0; j<26; j++)
			{
				if(in[i][0]==abcmod[j])
					temp1=j;
				
				if(in[i][1]==abcmod[j])
					temp2=j;
			}
		
			temp3=abcmod[temp1];
			abcmod[temp1]=abcmod[temp2];
			abcmod[temp2]=temp3;
		}
	/***************************************************************/
	
	/****************************************************************
	Hace los cambios de letras en la entrada
	****************************************************************/
	for(i=0; i<name.length(); i++)
		for(j=0; j<26; j++)
			if(name[i]==abcbase[j])
			{
				name[i]=abcmod[j];
				j=27;
			}
	/***************************************************************/
	
	cout << name << endl;
	return 0;
}