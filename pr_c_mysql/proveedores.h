#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>

using namespace std;

class proveedores
{
	//atributos
private: string proveedor, NIT, direccion, telefono;
		 //contructor 
public:
	proveedores() {}
	proveedores(string pro, string nit, string dir, string tel)
	{
		proveedor = pro;
		NIT = nit;
		direccion = dir;
		telefono = tel;
	}

	//metodos
public:
	// set modificar
	void setProveedor(string pro) { proveedor = pro; }
	void setNIT(string nit) { NIT = nit; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(string tel) { telefono = tel; }
	// get mostrar 
	string getProveedor() { return proveedor; }
	string getNIT() { return NIT; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }

	//metodos de la clase
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			cout << "--Datos del proveedor--" << endl;
			string consulta = "SELECT *FROM proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << endl;
				}

			}
			else {
				cout << "Error en la consulta" << endl;
			}

		}
		else {
			cout << "Error al conectar con la base de datos" << endl;
		}
		cn.cerrar_conexion();
	}
	
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insert = "INSERT INTO proveedores(proveedor, NIT, direccion, telefono) VALUES('" + proveedor + "','" + NIT + "','" + direccion + "','" + telefono + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Datos insertados correctamente" << endl;
			}
			else {
				cout << "Error al insertar datos" << endl;
			}
		}
		else {
			cout << "Error al conectar con la base de datos" << endl;
		}
		cn.cerrar_conexion();
		
	}
	// actulizar con el idproveedor
	//pedir idproveedor
	//pedir datos
	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string update = "UPDATE proveedores SET proveedor='" + proveedor + "', NIT='" + NIT + "', direccion='" + direccion + "', telefono='" + telefono + "' WHERE idproveedor=";
			string id_proveedores;
			cout << "Ingrese el id del proveedor que desea modificar" << endl;
			cin >> id_proveedores;
			update += id_proveedores;
			const char* u = update.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				cout << "Datos actualizados correctamente" << endl;
			}
			else {
				cout << "Error al actualizar datos" << endl;
			}
		}
		else {
			cout << "Error al conectar con la base de datos" << endl;
		}
		cn.cerrar_conexion();
		
	}

	// eliminar por idproveedor
	// pedir idproveedor
	//pedir datos

	void aliminar()
	{

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string delete_ = "DELETE FROM proveedores WHERE idproveedor=";
			string id_proveedores;
			cout << "Ingrese el id del proveedor que desea eliminar" << endl;
			cin >> id_proveedores;
			delete_ += id_proveedores;
			const char* d = delete_.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado) {
				cout << "Datos eliminados correctamente" << endl;
			}
			else {
				cout << "Error al eliminar datos" << endl;
			}
		}
		else {
			cout << "Error al conectar con la base de datos" << endl;
		}
		cn.cerrar_conexion();
	}

};

