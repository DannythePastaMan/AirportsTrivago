#include "Airports_Files.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Airport
{
    std::string country;
    string ID;
    double lat, lon;
    Airport();
};

Airport::Airport()
{
    this->country = "";
    this->ID = "";
    this->lat = 0;
    this->lon = 0;
}

Airport a;

Airports_Files::Airports_Files()
{

}

void Airports_Files::FileInput()
{    
    ofstream file("Airports.txt", fstream::app);

    if(!file.good())
    {
        cout<<"File not opened";
    }

    
    cout<<"****Ingrese datos****\n";
    
    cout<<"ID: ";
    cin>>a.ID;

    cout<<"Country: ";
    cin>>a.country;

    cout<<"Lattitude: ";
    cin>>a.lat;

    cout<<"Longitude: ";
    cin>>a.lon;

    file<<a.ID<<"; "<<a.country<<"; "<<a.lat<<"; "<<a.lon<<endl;
    file.close(); 
}

string Airports_Files::getAirportInfo()
{
    ifstream file("Airports.txt");

    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file, a.country);
            cout<<"Airport Info: "<<a.country;
            cout<<endl;
        }
    }
    return a.country;
}