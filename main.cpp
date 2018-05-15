#include <iostream>
#include "Airports_Files.h"

using namespace std;

int main()
{
    string code, country; 
    double lat, lon;
    Airports_Files af;
    af.createFile(code, country, lat, lon);
    af.readFile();
    return 0;
}