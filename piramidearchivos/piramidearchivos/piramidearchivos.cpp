#include <iostream>
#include <fstream>
#include <string>
void piramide();
void datoss();
void ingresarDatos();
void sacarDatos();
using namespace std;
ofstream  datos;
ifstream imprimirdatos;
string nombrearchiv;
int main()
{
	bool ingres= false;
	int opc;
	do
	{
		cout << "ejercicios de deber" << endl;
		cout << "1. ejercicio de archivos" << endl;
		cout << "2. ejercicios de las piramides" << endl;
		cout << "3. salir" << endl;
		cout << "opcion";
		cin >> opc;
		switch (opc)
		{
		case 1:
		{
			datoss();
			system("pause");
			break;
		}
		case 2:
		{
			piramide();
			system("pause");
			break;
		}
		case 3:
		{
			ingres = true;
			break;
		}
		default:
		{
			cout << "opcion invalida" << endl;
			break;
		}
		}
	} while (ingres==false);
	return 0;

}
void datoss()
{
	cout << " ingrese el nombre para el archivo: ";
	cin >> nombrearchiv;
	ingresarDatos();
}
void ingresarDatos()
{
	int ingres;
	cout << "1. agregar mas datos" << endl;
	cout << "2. ver datos" << endl;
	cout << "opcion" << endl;
	cin >> ingres;
	cin.ignore();
	if (ingres==1)
	{
		string nombre, apellido;
		int edad;
		string ingresa;
		datos.open(nombrearchiv.c_str(), ios::app);
		do
		{
			cout << "nombre: ";
			getline(cin, nombre, '\n');
			cout << "apellido: ";
			getline(cin, apellido, '\n');
			cout << "edad: ";
			cin >> edad;
			datos << nombre << " " << apellido << " " << edad << "\n";
			cout << "desea ingresar mas contactos (s/n): ";
			cin >> ingresa;
			cin.ignore();
		} while (ingresa == "s");
		cout << "datos guardados con exito" << endl;
		datos.close();
	}
	if (ingres==2)
	{
		sacarDatos();
	}
}
void sacarDatos()
{
	string texto;
	string nombre, apellido;
	int edad;
	imprimirdatos.open(nombrearchiv.c_str(), ios::in);
	if (imprimirdatos.fail())
	{
		cout << "archivo dañado" << endl;
	}
	else
	{
		while (!imprimirdatos.eof())
		{
			imprimirdatos >> nombre >> apellido >> edad;
			if (!imprimirdatos.eof())
			{
				getline(imprimirdatos, texto);
				cout << "nombre: " << nombre << endl;
				cout << "apellido: " << apellido << endl;
				cout << "edad: " << edad << endl;
			}
		}
	}
	imprimirdatos.close();
}
void piramide()
{
	ofstream piramide;
	string piramid, nombrearchiv;
	int nivel, i=1, x=1, z;
	cout << "nombre del archivo: "<< endl;
	cin >> nombrearchiv;
	cout << "ingrese el nivel de lapiramide";
	cin >> nivel;
	piramide.open(nombrearchiv.c_str(), ios::out);
	z = nivel;
	while (i<=nivel)
	{
		while (x<=z)
		{
			if (i%2==0)
			{
				piramide << "- ";
			}
			else
			{
				piramide << "* ";
			}
			x++;
		}
		piramide << "\n";
		i++;
		x = 1;
		z--;

	}
	piramide.close();

	ifstream abrirpiramid;
	string text;
	abrirpiramid.open(nombrearchiv.c_str(), ios::in);
	while (!abrirpiramid.eof())
	{
		getline(abrirpiramid, text);
		cout << text << endl;
	}
	abrirpiramid.close();


}