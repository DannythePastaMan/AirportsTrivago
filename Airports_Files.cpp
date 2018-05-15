#include "Airports_Files.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

/*struct Airport
{
    string country;
    string ID;
    double lat, lon;
    Airport();
}a;

Airport::Airport()
{
    this->country = "";
    this->ID = "";
    this->lat = 0;
    this->lon = 0;
}
*/

Airports_Files::Airports_Files()
{

}

void Airports_Files::createFile(string code, string country, double lat, double lon)
{    
    ofstream file("Airports.txt", ios::app);

    if(!file.good())
    {
        cout<<"File not opened";
    }

    file<<code<<"; "<<country<<"; "<<lat<<"; "<<lon<<endl;
    file.close(); 
}

string Airports_Files::readFile()
{
    ifstream file("Airports.txt");
    string file_text;

    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file, file_text);
            cout<<file_text<<endl;
        }
    }
    return file_text;
}

void Airports_Files::reloadFile()
{
 
}