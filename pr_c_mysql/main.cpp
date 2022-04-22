// pr_c_mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
#include <Windows.h>
#include "proveedores.h"
using namespace  std;




int main()
{
	int opcion;
		cout << "--BIENVENIDO A LA BASE DE DATOS DE PROVEEDORES" << endl;
		cout << "1. ingresar nuevo proveedor" << endl;
		cout << "2. Actualizar proveedor" << endl;
		cout << "3. eliminar proveedor" << endl;
		cout << "4. ver proveedores activos" << endl;
		cout << "5. salir" << endl;
		cin >> opcion;

		if (opcion == 1) {
			system("cls");
			string  proveedor;
			string NIT, direccion, telefono;
			cout << "Ingrese proveedor de: ";
			getline(cin, proveedor);
			cout << "Ingrese NIT de: ";
			getline(cin, NIT);
			cout << "Ingrese la direccion del proveedor:";
			getline(cin, direccion);
			cout << "Ingrese el telefono del proveedor: ";
			getline(cin, telefono);

			proveedores p = proveedores(proveedor, NIT, direccion, telefono);
			p.crear();
			p.leer();
		}
		//llamar al contructor actualizar
		// actualizar con idproveedores
		// pedir los datos a actualizar
		else if (opcion == 2) {
			system("cls");
			string  proveedor;
			string NIT, direccion, telefono;
			cout << "Ingrese proveedor de: ";
			getline(cin, proveedor);
			cout << "Ingrese NIT de: ";
			getline(cin, NIT);
			cout << "Ingrese la direccion del proveedor:";
			getline(cin, direccion);
			cout << "Ingrese el telefono del proveedor: ";
			getline(cin, telefono);

			proveedores p = proveedores(proveedor, NIT, direccion, telefono);
			p.actualizar();
			p.leer();
		}
		//llamar al metodo eliminar
		// eliminar con idproveedores
		//pedir el id a eliminar
		else if (opcion == 3) {
			system("cls");
			string  proveedor;
			string NIT, direccion, telefono;
			cout << "Ingrese proveedor de: ";
			getline(cin, proveedor);
			cout << "Ingrese NIT de: ";
			getline(cin, NIT);
			cout << "Ingrese la direccion del proveedor:";
			getline(cin, direccion);
			cout << "Ingrese el telefono del proveedor: ";
			getline(cin, telefono);

			proveedores p = proveedores(proveedor, NIT, direccion, telefono);
			p.eliminar();
			p.leer();
		}
		
		else if (opcion == 4) {
			system("cls");
			string  proveedor;
			string NIT, direccion, telefono;
			cout << "Ingrese proveedor de: ";
			getline(cin, proveedor);
			cout << "Ingrese NIT de: ";
			getline(cin, NIT);
			cout << "Ingrese la direccion del proveedor:";
			getline(cin, direccion);
			cout << "Ingrese el telefono del proveedor: ";
			getline(cin, telefono);

			proveedores p = proveedores(proveedor, NIT, direccion, telefono);
			p.leer();
		}
		
		
		else if (opcion == 4) {
			system("cls");
			proveedores p = proveedores();
			p.leer();
		}

		else if (opcion == 5) {
			system("cls");
			cout << "Gracias por usar nuestra base de datos" << endl;

		}


	return 0;
}

