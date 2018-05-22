#include "Airport_Files.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <cstdlib>

using namespace std;

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

	file << code << ";" << country << ";" << lat << ";" << lon << endl;
	cout << endl;
	file.close();
}

void Airports_Files::readFile()
{
	string text;
	ifstream file("Airports.txt");

	if (!file.good())
	{
		cout << "Not found" << endl;
		return;
	}

	while(getline(file, text))
	{
		cout << text << endl;
	}
	file.close();
}

void Airports_Files::reloadFile(string airport_to_replace, string new_airport, string new_country, double new_lat, double new_lon)
{
	ifstream file("Airports.txt", ios::in);
	ofstream file_tmp("Airports2.txt", ios :: app);

	if (!file || !file_tmp)
	{
		return;
	}

	string tmp;
	bool found = false;

	while (getline(file, tmp))
	{
		if (tmp == airport_to_replace)
		{
			tmp = new_airport;
			found = true;
			file_tmp << tmp << "\n" << new_airport << ";" << new_country << ";" << new_lat << ";" << new_lon << endl;
		}
		
		file.close();
		
		if (found)
		{
			file.close();
			break;
		}
	}
	file.close();
} 

void Airports_Files::deleteLine(string line_to_delete)
{
	ifstream file("Airports.txt", ios::in);
	ofstream file2("Ex.txt", ios::app);
	string line;

	if (!file.good())
	{
		cout << "Not Found" << endl;
		return;
	}

	while (getline(file, line))
	{
		if (line == line_to_delete)
		{
			line.replace(0, line_to_delete.length(), " ");
		}
		file2 << line << endl;
	}
	file.close();
	file2.close();
}