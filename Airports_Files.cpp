#include "Airports_Files.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Airport
{
    string country;
    string ID;
    double lat, lon;
    Airport();
};

Airport::Airport()
{
    this->country = "";
    this->ID = "";
    this->lat = 0.00;
    this->lon = 0.00;
}

Airport a;

Airports_Files::Airports_Files()
{

}

void Airports_Files::FileInput()
{    
    ofstream file("Airports.txt");

    if(!file.good())
    {
        cout<<"File not opened";
    }

    cout<<"****Ingrese datos****";
    
    cout<<"ID: ";
    cin>>a.ID;

    cout<<"Country: ";
    cin>>a.country;

    cout<<"Lat and long: ";
    cin>>a.lat;
    cin>>a.lon;

    file<<a.ID<<"; "<<a.country<<"; "<<a.lat<<"; "<<a.lon<<endl;
}

string Airports_Files::getID()
{
    return a.ID;
}

string Airports_Files::getCountry()
{
    return a.country;
}
