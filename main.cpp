#include <iostream>
#include <string>
#include <sstream>
#include "Airports_Files.h"
#include <fstream>

using namespace std;

int main()
{
	Airports_Files af;
	int opc = -1;

	do
	{
		opc = -1;
		char code[3];
		char country[5];
		double lat, lon;
		cout << "Airports\n 1. Create and Add Airports.\n 2. Read Files.\n 3. Reload file updated.\n4. Delete airport." << endl;
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

			default:
				break;
		}
	} while (opc != -1);
    
	return 0;
}