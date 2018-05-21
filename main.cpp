#include <iostream>
#include <string>
#include "Airports_Files.h"

using namespace std;

int main()
{
    char *code;
    int opc = -1;
    cout << "Airports\n 1. Create and Add Airports.\n 2. Read Files.\n 3. Reload file updated." << endl;
    cout << "Chose an option: ";
    cin >> opc;

    do
    {
        switch(opc)
        {
            case 1:
            {
                cout<<"Ingrese codigo: ";
                cin >> code;
            }
        }

    }while(opc != -1);
    return 0;
}
