/*Mediante la aplicación de ciclos y funciones se va a crear un menú que le permita al usuario elegir entre calcular el logaritmo natural, 
seno o coseno mediante la aproximación usando series numéricas infinitas en las cuales el usuario definirá la cantidad de términos de la serie a trabajar.
El menú hará que el usuario regrese al mismo hasta que elija salir con la opción 0.
Para comprobación considerar que el seno y coseno es para un valor de x en radianes.
Anexo las imágenes de las aproximaciones para cada valor.*/
#include <iostream>
float facto ( float numero);
float pote (float numero, float potencia);
float cos (int x, int pos);
float sen (int x, int pos);
float logna(int n,int x);
using namespace std;
int main ()
{
	int menu, pos, x;
	do
	{
		cout << "*****BIENVENIDO AL MENU***** \n"
		 << "Escoja la opcino que desea calcular.\n"
		 << "1. LOGARITMO NATURAL \n"
		 << "2. SENO \n"
		 << "3. COSENO \n"
		 << "0. SALIR \n";
		cin>>menu;
	
		switch (menu)
		{
			case 1:
				cout <<"*****USTED A ESCOGIDO LA FUNCION DE LOGARITMO NATURAL***** \n"
				<<"* * * * *OJO PONER EL VALOR DE X CON .0 EJEMPLO 6.0 * * * * *\n"
				<<"ingrese el valor de x \n";
				cin >> x;
				cout <<"que posicion desea saber \n";
				cin >> pos;
				cout << "el valor de "<< x << " en la posicion " << pos <<" es " <<logna(pos,x)<<endl;
			break;
			case 2:
				cout <<"*****USTED A ESCOGIDO LA FUNCION SENO***** \n"
				<<"ingrese el valor de x \n";
				cin >> x;
				cout <<"que posicion desea saber \n";
				cin >> pos;
				cout << "el valor de "<< x << " en la posicion " << pos <<" es " <<sen(x,pos)<<endl; 
			break;
			case 3:
				cout <<"*****USTED A ESCOGIDO LA FUNCION COSENO***** \n"
				<<"ingrese el valor de x \n";
				cin >> x;
				cout <<"que posicion desea saber \n";
				cin >> pos;
				cout << "el valor de "<< x << " en la posicion " << pos <<" es " <<cos(x,pos)<<endl;
			break;
		}
	}while(menu!=0);
	return 0;
}
float facto ( float numero)
{
	long int suma=1;
	
	for(int i=2; i<=numero;i++)
	{
		suma*=i;
	}
	
	return suma;
}
float pote (float numero, float potencia)
{
	float suma=1;
	for(int i=1;i<=potencia;i++)
	{
		suma*=numero;
	}		

	return suma;
}
float cos (int x, int pos)
{
	float suma=0;
	for (int i=1.0, j=0.0; i<=pos; i++, j+=2)
	{
		if(i%2==1)
		{
			suma+=(pote(x,j)/facto(j));
		}
		else
			suma-=(pote(x,j)/facto(j));
	}
	
	return (float)suma;
}
float sen (int x, int pos)
{
	float suma=0;
	
	for (int i=1.0, j=1.0; i<=pos; i++, j+=2)
	{
		if(i%2==1)
		{
			suma+=(pote(x,j)/facto(j));
		}
		else
			suma-=(pote(x,j)/facto(j));
	}
	
	return suma;
}
float logna(int n,int x)
{
    float suma=0, y;
    y=((x-1.0)/x);
    for(int i=1;i<=n;i++)
        suma+=(1.0/i)*pote(y,i);
    return suma;
}

