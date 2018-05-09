#include <iostream>
#include "Airports_Files.h"

using namespace std;

int main()
{
    Airports_Files af;
    af.FileInput();
    af.getAirportInfo();
    return 0;
}