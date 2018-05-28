#include "Airport_Files.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <io.h>

#define CODE 3
#define COUNTRY 3

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

	if (!file.good())
	{
		cout << "File not opened";
	}

	if (code[CODE] > 3 || country[COUNTRY] > 3)
	{
		sprintf(code, "Airports Trivago, argument must be in the range of 3 or 5 respectively: %i", 3 | 5);
		throw invalid_argument(code);
		throw invalid_argument(country);
	}

	file << code << ";" << country << ";" << lat << ";" << lon << endl;
	cout << endl;
	file.close();
}

void Airports_Files::readFile(char *buffer)
{
	ifstream file("Airports.txt", ios::in);

	if (!file.good())
	{
		cout << "File not found" << endl;
		return;
	}

	while (file >> buffer)
	{
		cout << buffer << endl;
	}
}

void Airports_Files::reloadFile(char *airport_to_replace, char *new_airport, char * new_country, double new_lat, double new_lon)
{
	ifstream file("Airports.txt", ios::in);
	ofstream file_tmp("Airports1.txt");

	string tmp_string;

	if (!file || !file_tmp)
	{
		cout << "No file found.";
		return;
	}

	while (getline(file, tmp_string))
	{
		string str = tmp_string.substr(0, 3);

		if (str == airport_to_replace)
		{
			deleteLine(airport_to_replace);
			str = new_airport;
			file_tmp << str << ";" << new_country << ";" << new_lat << ";" << new_lon << endl;
		}
		else if (str != airport_to_replace)
		{
			file_tmp << tmp_string << endl;
		}
	}


	file.close();
	file_tmp.close();

	std::remove("Airports.txt");
	std::rename("Airports1.txt", "Airports.txt");
}

void Airports_Files::deleteLine(char *line_to_delete)
{
	ifstream file("Airports.txt", ios::in);
	ofstream file2("Ex.txt");

	string line;
	string str;

	if (!file.good())
	{
		cout << "Not Found" << endl;
		return;
	}

	while (getline(file, line))
	{
		str = line.substr(0, 3);

		if (str != line_to_delete)
		{
			file2 << line << endl;
		}
	}

	file.close();
	file2.close();

	remove("Airports.txt");
	rename("Ex.txt", "Airports.txt");
}