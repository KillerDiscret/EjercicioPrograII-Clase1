#include<conio.h>
#include<iostream>
using namespace std;
using namespace System;

int menu()
{
	int opcion;
	do
	{
		Console::Clear();
		cout << "\n\t MENU";
		cout << "\n [1] Listar elementos ";
		cout << "\n [2] Agregar al final ";
		cout << "\n [3] Eliminar en posicion";
		cout << "\n [4] Agregar al inicio";
		cout << "\n [5] Ordenar elementos";
		cout << "\n [6] Eliminar Ultimo";
		cout << "\n [7] Modificar posicion";
		cout << "\n Ingrese opcion ";
		cin >> opcion;
	} while (opcion < 1 || opcion>7);
	return opcion;
}
void ListarElementos(int *Arreglo, int *N)
{
	if (Arreglo != NULL)
	{
		for (int i = 0; i<*N; i++)
		{
			cout << "N." << i + 1 << " " << Arreglo[i] << endl;
		}

	}
	else
	{
		cout << "El arreglo esta vacio" << endl;

	}
	_getch();
}
int*AgregarFinal(int *Arreglo, int *N, int elemento)
{
	int *NuevoArreglo = new int[*N + 1];
	for (int i = 0; i<*N;i++)
	{
		NuevoArreglo[i] = Arreglo[i];
	}
	NuevoArreglo[*N] = elemento;
	*N = *N + 1;
	return NuevoArreglo;
}
int*EliminarPosicion(int *Arreglo, int *N, int posicion)
{
	int *NuevoArreglo = new int[*N - 1];
	int n = 0;
	for (int i = 0;i<*N;i++)
	{
		if (i + 1 != posicion)
		{
			NuevoArreglo[n] = Arreglo[i];
			n = n + 1;
		}
		else
		{
			cout << endl;
		}
	}
	*N = *N - 1;
	return NuevoArreglo;
}
int *AgregarInicio(int *Arreglo, int* N, int variable)
{
	int n = 0;
	int *NuevoArreglo = new int[*N + 1];
	NuevoArreglo[0] = variable;
	for (int i = 1;i <= *N;i++)
	{
		NuevoArreglo[i] = Arreglo[n];
		n = n + 1;
	}
	*N = *N + 1;
	return NuevoArreglo;
}
void OrdenarElementos(int *Arreglo, int*N)
{
	int auxiliar;
	for (int i = 0;i<*N - 1;i++)
	{
		for (int j = i + 1;j<*N;j++)
		{
			if (Arreglo[i]<Arreglo[j])
			{
				auxiliar = Arreglo[i];
				Arreglo[i] = Arreglo[j];
				Arreglo[j] = auxiliar;
			}
		}
	}
}
int * EliminarUltimo(int *Arreglo, int *N)
{
	int *NuevoArreglo = new int[*N - 1];
	for (int i=0; i<=*N-1;i++)
	{
		NuevoArreglo[i] = Arreglo[i];
		
	}
	*N = *N - 1;
	return NuevoArreglo;
}
void ModificarPosicion(int *Arreglo, int *N)
{
	int posicion;
	int numero;
	cout << "Ingrese la posicion a modificar: " << endl;
	cin >> posicion;
	cout << "Ingrese el numero: " << endl;
	cin >> numero;
	for (int i=0;i<*N;i++)
	{
		if (i+1==posicion)
		{
			Arreglo[i] = numero;
		}
	}
}
int main()
{
	int *Arreglo = NULL;
	int *N = new int;
	*N = 0;
	while (1)
	{
		int opcion = menu();
		if (opcion == 1)
		{
			ListarElementos(Arreglo, N);

		}
		if (opcion == 2)
		{
			int elemento;
			cout << "Ingrese un número:" << endl;
			cin >> elemento;
			Arreglo = AgregarFinal(Arreglo, N, elemento);
		}
		if (opcion == 3)
		{
			int posicion;
			do {
				cout << "Ingrese la posicion a eliminar:" << endl;
				cin >> posicion;
			} while (posicion < 1);
			Arreglo = EliminarPosicion(Arreglo, N, posicion);
		}
		if (opcion == 4)
		{
			int variable;
			cout << "Ingrese un número:" << endl;
			cin >> variable;
			Arreglo = AgregarInicio(Arreglo, N, variable);
		}
		if (opcion == 5)
		{
			OrdenarElementos(Arreglo, N);
		}
		if (opcion == 6)
		{
			Arreglo=EliminarUltimo(Arreglo,N);
		}
		if (opcion==7)
		{
			ModificarPosicion(Arreglo, N);
		}
	}

	_getch();
}