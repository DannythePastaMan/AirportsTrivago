#include "Airports_Files.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <cstdlib>

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

char *Airports_Files::readFile()
{
    ifstream file;
    string file_text;
    const char *official_ret = "";
    string ret_str;

    file.open("Airports.txt");

    if(file.is_open())
    {
        char *ret = new char;
        while(getline(file, file_text))
        {
           strcpy(ret, file_text.c_str()); 
           ret_str += ret;
           ret_str += '\r\n';
        }
         
        official_ret = ret_str.c_str();
        char *return_ch = const_cast<char *>(official_ret);
        return return_ch;
    }
    return 0;
}

void Airports_Files::reloadFile(char *airport_to_replace, char *new_airport, char * new_country, double new_lat, double new_lon)
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
        istringstream airport(tmp_string);
        string word;
        getline(airport, word, ';');
        
        if(tmp_string == word)
        {
            file_tmp<<new_airport<<';'<<new_country<<';'<<new_lat<<';'<<new_lon<<endl;
        }

        else
        {
            file_tmp<<tmp_string<<endl;
        }
    }
    file.close();
    file_tmp.close();
}