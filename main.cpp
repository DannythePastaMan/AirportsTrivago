#include <iostream>
#include <string>
#include "Airports_Files.h"

using namespace std;

int main()
{
    //char *airport_to_replace = "LAX"; 
    //char *airport_replaced = "TEXAS";
    char *code = "FRAX"; 
    char *country = "LIASA"; 

    char *newCode = "LAX";
    char *newCountry = "HND";
    double newLat = 12, newLon = 80;

    double lat = 798, lon = 436;

    Airports_Files af;
    
    //af.createFile(code, country, lat, lon);
    //af.readFile();
    af.reloadFile(code, newCode, newCountry, newLat, newLon);
    return 0;
}
