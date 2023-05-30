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
float* precio;
string* nombre, * status, * clasificacion, * descripcion, * genero, * consola;
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
		numero[i] = i + 1;
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
		scanf_s("%f", &precio[i]);
	}
}

void listas()
{
int op;
float var2;
string var;
cout << "¿Que aspecto desea ver?" << endl << "1.-Nombre 2.-Descripcion 3.-Clasificacion 4.-Genero 5.-Consola 6.-Precio" << endl;
scanf_s("%d", &op);
	switch (op)
	{
	case 1:
		while (getchar() != '\n');
		printf("Ingrese el nombre del articulo a buscar: ");
		getline(cin, var);
		for (int i = 0; i < alta; i++)
		{

			if (nombre[i] == var)
			{
				if ((status[i] == "ELIMINADO"))
				{
					cout << "REGISTRO ELIMINADO" << i + 1 << endl;
					printf("ingrese un registro valido \n");
				}
				else
				{
					printf("Nombre del articulo ");
					cout << numero[i] << ":" << endl;
					printf("%s\n", nombre[i].c_str());

				}
			}
			else
			{
				printf("No se encontro %s\n", &var);
			}
		}
		break;

	case 2:
		for (int i = 0; i < alta; i++)
		{
			if ((status[i] == "ELIMINADO"))
			{
				cout << "REGISTRO ELIMINADO" << i + 1 << endl;
				printf("ingrese un registro valido \n");
			}
			else
			{
				printf("Descripcion del articulo ");
				cout << numero[i] << ":" << endl;
				printf("%s\n", descripcion[i].c_str());
			}
		}
		break;

	case 3:
		while (getchar() != '\n');
		printf("Ingrese la clasificacion del articulo a buscar ");
		getline(cin, var);
		for (int i = 0; i < alta; i++)
		{
			if (clasificacion[i] == var)
			{
				if ((status[i] == "ELIMINADO"))
				{
					cout << "REGISTRO ELIMINADO" << i + 1 << endl;
					printf("ingrese un registro valido \n");
				}
				else
				{
					printf("Clasificacion del articulo ");
					cout << numero[i] << ":" << endl;
					printf("%s\n", clasificacion[i].c_str());

				}
			}
			else
			{
				printf("No se encontro %s\n", &var);
			}
		}
		break;

	case 4:
		while (getchar() != '\n');
		printf("Ingrese el genero del articulo a buscar ");
		getline(cin, var);
		for (int i = 0; i < alta; i++)
		{
			if (genero[i] == var)
			{
				if ((status[i] == "ELIMINADO"))
				{
					cout << "REGISTRO ELIMINADO" << i + 1 << endl;
					printf("ingrese un registro valido \n");
				}
				else
				{
					printf("Genero del articulo ");
					cout << numero[i] << ":" << endl;
					printf("%s\n", genero[i].c_str());
				}
			}
			else
			{
				printf("No se encontro %s\n", &var);
			}
		}
		break;

	case 5:
		while (getchar() != '\n');
		printf("Ingrese la consola a la que pertenece el/los articulo(s) a buscar ");
		getline(cin, var);
		for (int i = 0; i < alta; i++)
		{
			if (consola[i] == var)
			{
				if ((status[i] == "ELIMINADO"))
				{
					cout << "REGISTRO ELIMINADO" << i + 1 << endl;
					printf("ingrese un registro valido \n");
				}
				else
				{
					printf("Consola al que pertenece el articulo");
					cout << numero[i] << ":" << endl;
					printf("%s\n", consola[i].c_str());
				}
			}
			else
			{
				printf("No se encontro %s\n", &var);
			}
		}
		break;

	case 6:
		while (getchar() != '\n');
		printf("Ingrese el precio de el/los articulo(s) a buscar ");
		scanf_s("%f", &var2);
		for (int i = 0; i < alta; i++)
		{
			if (precio[i] == var2)
			{
				if ((status[i] == "ELIMINADO"))
				{
					cout << "REGISTRO ELIMINADO" << i + 1 << endl;
					printf("ingrese un registro valido \n");
				}
				else
				{
					float iva;
					printf("Precio del articulo %d: ", &numero[i]);
					cout << numero[i] << ":" << endl;
					printf(" %f\n", &precio[i]);
					iva = precio[i] * 1.16;
					printf("Precio con IVA incluido: %f\n", &iva);
				}
			}
			else
			{
				printf("No se encontro %s\n", &var2);
			}
		}
		break;

	default:
		printf("OPCION INVALIDA");
		return modificar();
		break;
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

			texto = precio[i] * 1.16;
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
	cout << "¿Que desea modificar?" << endl << "1.-Nombre 2.-Descripcion 3.-Clasificacion 4.-Genero 5.-Consola 6.-Precio" << endl;
	scanf_s("%d", &opcion);
	while (getchar() != '\n');
	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese nombre del articulo" << endl;
			getline(cin, nombre[i]);
		}
		break;

	case 2:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese una descripcion sobre el articulo" << endl;
			getline(cin, descripcion[i]);
		}
		break;
	case 3:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese la clasificacion del articulo" << endl;
			getline(cin, clasificacion[i]);
		}
		break;
	case 4:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese el genero del articulo" << endl;
			getline(cin, genero[i]);
		}
		break;
	case 5:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese la consola a la que pertenece el articulo" << endl;
			getline(cin, consola[i]);
		}
		break;

	case 6:
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
