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

void Airports_Files::createFile(char *code, char *country, double lat, double lon)
{    
    ofstream file("Airports.txt", ios::app);

    if(!file.good())
    {
        cout<<"File not opened";
    }

    file<<code<<";"<<country<<";"<<lat<<";"<<lon<<endl;
    cout<<endl;
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

void Airports_Files::reloadFile(char *airport_to_replace, char *airport_replaced, char * new_country, double new_lat, double new_lon)
{
    ifstream file("Airports.txt");
    ofstream file_tmp("Airports2.txt");

    if(!file || !file_tmp)
    {
        cout<<"No file found.";
        return;
    }

    string tmp_string;

    while(getline(file, tmp_string))
    {
        if(tmp_string == airport_to_replace)
        {
            file_tmp<<airport_replaced<<";"<<new_country<<";"<<new_lat<<";"<<new_lon<<endl;
        }

        else
        {
            file_tmp<<tmp_string<<endl;
        }
    }
    file.close();
    file_tmp.close();
}