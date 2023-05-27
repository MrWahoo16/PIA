#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;


void Alta();
void listas();
void archivos();
void eliminar();
void modificar();

int alta, * numero;
float *precio;
string* nombre, * status, * clasificacion, * descripcion, *genero, *consola;
int main()
{
	int opc;
	printf("SUPER WAHOO STORE\n");
	printf(" 1.-Alta\n 2.-Lista\n 3.-Limpiar pantalla\n 4.-Modificar\n 5.-Eliminar\n 6.-Salir\n");
	scanf_s("%d", &opc);

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		listas();
		return main();
		break;

	case 3:
		system("cls");
		return main();
		break;

	case 4:
		modificar();
		return main();
		break;

	case 5:
		eliminar();
		return main();
		break;

	case 6:
		archivos();
		break;
	}
}

void Alta()
{
	cout << "Digite el num de registros que desea dar de alta" << endl;
	cin >> alta;
	numero = new int[alta];
	nombre = new string[alta];
	descripcion = new string[alta];
	clasificacion = new string[alta];
	genero = new string[alta];
	status = new string[alta];
	consola = new string[alta];
	precio = new float[alta];
	for (int i = 0; i < alta; i++)
	{
		while (getchar() != '\n');
		printf("Ingrese el numero del articulo\n");
		scanf_s("%d", &numero);
		while (getchar() != '\n');

		printf("Ingrese el nombre del articulo\n");
		getline(cin, nombre[i]);

		printf("Ingrese la clasificacion del articulo\n");
		getline(cin, clasificacion[i]);

		printf("Ingrese una descripcion del articulo\n");
		getline(cin, descripcion[i]);

		printf("Ingrese el genero del articulo\n");
		getline(cin, genero[i]);

		printf("Ingrese la consola a la que pertenece el articulo\n");
		getline(cin, consola[i]);
		printf("Ingrese el precio del articulo\n");
		scanf_s("%d", &precio);
	}
}

void listas()
{
	for (int i = 0; i < alta; i++)
	{
		if (status[i] == "ELIMINADO")
		{
			printf("REGISTRO d% ELIMINADO", i + 1);
		}
		else
		{
			printf("d% registro", i + 1);
			printf("NUMERO: %d \n", numero[i]);
			printf("NOMBRE: %s \n", nombre[i]);
			printf("DESCRIPCION: %s \n", descripcion[i]);
			printf("CLASIFICACION: %s \n", clasificacion[i]);
			printf("GENERO: %s \n", genero[i]);
			printf("CONSOLA: %s \n", consola[i]);
			printf("PRECIO: %d \n", precio[i]);
			printf("PRECIO (CON IVA INCLUIDO) %d \n", precio[i]*1.16);
		}
	}
}

void archivos()
{
	ofstream archivo;
	string nombrearchivo;
	int texto;
	string texto2;

	nombrearchivo = "altasmatricula.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	archivo << "NUMERO" << "\t";
	archivo << "NOMBRE" << "\t";
	archivo << "DESCRIPCION" << "\t";
	archivo << "CLASIFICACION" << "\t";
	archivo << "GENERO" << "\t";
	archivo << "CONSOLA" << "\t";
	archivo << "PRECIO" << "\t";
	archivo << "IVA" << "\t";

	for (int i = 0; i < alta; i++)
	{
		if (status[i] == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO ";
			texto = i;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			texto = numero[i];
			archivo << texto << "\t" << "\t";

			texto2 = nombre[i];
			archivo << texto2 << "\t" << "\t";

			texto2 = descripcion[i];
			archivo << texto2 << "\t" << "\t";

			texto2 = clasificacion[i];
			archivo << texto2 << "\t" << "\t";

			texto2 = genero[i];
			archivo << texto2 << "\t" << "\t";

			texto2 = consola[i];
			archivo << texto2 << "\t" << "\t";

			texto = precio[i];
			archivo << texto << "\t" << "\t";

			texto = precio[i]*1.16;
			archivo << texto << "\t" << "\t";

		}
	}


	archivo.close();
}

void eliminar()
{
	int j;
	cout << "ingrese el  registro a eliminar";
	cin >> j;
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		cout << "Eliminando registro" << j + 1 << endl;
		status[i] = "ELIMINADO";
	}
}

void modificar()
{
	int j, opcion, op2;
	do
	{
		cout << "ingrese el numero registro a modificar";
		cin >> j;
		j = j - 1;

		for (int i = j; i == j; i++)
		{
			if ((status[i] == "ELIMINADO"))
			{
				cout << "REGISTRO ELIMINADO" << i + 1 << endl;
				printf("ingrese un registro valido \n");
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);
	cout << "¿Que desea modificar?"<<endl<<"1.-Numero 2.-Nombre 3.-Descripcion 4.-Clasificacion 5.-Genero 6.-Consola 7.-Precio"<<endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese el numero del articulo\n");
			scanf_s("%d", &numero);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese nombre del articulo" << endl;
			getline(cin, nombre[i]);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese una descripcion sobre el articulo" << endl;
			getline(cin, descripcion[i]);
		}
		break;
	case 4:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese la clasificacion del articulo" << endl;
			getline(cin, clasificacion[i]);
		}
		break;
	case 5:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese el genero del articulo" << endl;
			getline(cin, genero[i]);
		}
		break;
	case 6:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese la consola a la que pertenece el articulo" << endl;
			getline(cin, consola[i]);
		}
		break;
	
	case 7:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese el precio del articulo" << endl;
			scanf_s("d%", &precio[i]);
		}
		break;
	default:
		printf("OPCION INVALIDA");
		return modificar();
		break;
	}


}
