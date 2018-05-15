#include <iostream>
#include <string>
#include "Airports_Files.h"

using namespace std;

int main()
{
    //char *airport_to_replace = "LAX"; 
    //char *airport_replaced = "TEXAS";
    char *code = "TAX"; 
    char *country = "USA"; 
    double lat = 90, lon = 80;

    Airports_Files af;
    
    af.createFile(code, country, lat, lon);
    af.readFile();
    //af.reloadFile(airport_to_replace, airport_replaced);
    return 0;
}