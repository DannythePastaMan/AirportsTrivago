#include <iostream>
#include <string>
#include <sstream>
#include "Airport_Files.h"
#include "Routes_FIles.h"
#include <fstream>

using namespace std;

int main()
{
	Airports_Files af;
	Routes_FIles rf;

	int opc = -1;

	do
	{
		opc = -1;
		char code[3];
		char country[5];
		double lat, lon;
		cout << "Airports\n 1. Create and Add Airports.\n 2. Read Files.\n 3. Reload file updated.\n4. Delete airport. \n5. Create routes file.\n6. Read Routes.\n7. Edit Routes\n8. Delete Route." << endl;
		cout << "Choose an option: " << endl;
		cin >> opc;
		cout << endl;

		switch (opc) {
		case 1:
		{
			cout << "Ingrese codigo: " << endl;
			cin >> code;
			cout << "Ingrese pais: " << endl;
			cin >> country;

			cout << "Ingrese latitud: " << endl;
			cin >> lat;

			cout << "Ingrese longitud: " << endl;
			cin >> lon;

			af.createFile(code, country, lat, lon);
			break;
		}


		case 2:
		{
			char buffer[1024];
			cout << endl;
			af.readFile(buffer);
			cout << endl;
			break;
		}

		case 3:
		{
			char old_airport[3];
			char new_airport[3];
			char new_country[5];
			double new_lat, new_lon;

			cout << "Ingrese aeropuerto a cambiar: ";
			cin >> old_airport;

			cout << "Ingrese nuevo aeropuerto: ";
			cin >> new_airport;

			cout << "Ingrese nuevo pais: ";
			cin >> new_country;

			cout << "Ingrese nueva latitud: ";
			cin >> new_lat;

			cout << "Ingrese nueva longitud: ";
			cin >> new_lon;

			af.reloadFile(old_airport, new_airport, new_country, new_lat, new_lon);
			break;
		}

		case 4:
		{
			char atd[3];
			cout << "Aiprort to delete: ";
			cin >> atd;

			af.deleteLine(atd);
			break;
		}

		case 5:
		{
			char from[3];
			char to[3];
			double distance = 0;

			cout << "Ingrese el aeropuerto en el que se encuentra: ";
			cin >> from;

			cout << "Ingrese hacia donde quiere ir: ";
			cin >> to;

			cout << "Ingrese distancia:  ";
			cin >> distance;

			rf.createFile(from, to, distance);

			break;
		}

		case 6:
		{
			char buffer[1024];

			rf.readFile(buffer);
			break;
		}

		case 7:
		{
			char old_from[3];
			char new_from[3];
			char to[3];
			double distance;

			cout << "Ingrese ruta a editar: ";
			cin >> old_from;

			cout << "Ingrese nueva ruta: ";
			cin >> new_from;

			cout << "Ingrese hacia donde desea ir: ";
			cin >> to;

			cout << "Ingrese distancia: ";
			cin >> distance;

			rf.reloadFile(old_from, new_from, to, distance);
			break;
		}

		default:
			break;
		}
	} while (opc != -1);

	return 0;
}