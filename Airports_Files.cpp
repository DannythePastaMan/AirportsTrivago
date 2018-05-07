#include "Airports_Files.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Airport
{
    int ID;
    string name;
    vector<string> countries;
    vector<string> IDs;
    double lat, lon;
};

Airport a;

Airports_Files::Airports_Files()
{

}

void Airports_Files::FileInput()
{    
    ofstream file("Airports.txt");
    generateAirports();

    if(!file.good())
    {
        cout<<"File not opened";
    }

    for (size_t i = 0; i < a.IDs.size(); i++)
    {
        file<<a.IDs[i]<<endl;
    }

}

void Airports_Files::getID()
{

}

void Airports_Files::getName()
{

}

void Airports_Files::generateAirports()
{
    a.IDs.push_back("SAP");
    a.IDs.push_back("MIA");
    a.IDs.push_back("JFK");
    a.IDs.push_back("LAX");
    a.IDs.push_back("MAD");
    a.IDs.push_back("HND");
}