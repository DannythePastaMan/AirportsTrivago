#include "Routes_FIles.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>

#define FROM 3
#define TO 5

using namespace std;

Routes_FIles::Routes_FIles()
{
}


Routes_FIles::~Routes_FIles()
{
}

void Routes_FIles::createFile(char *from, char *to, double distance)
{
	ofstream file2("Routes.txt", ios::app);

	if (!file2.good())
	{
		cout << "File not opened";
	}

	if (from[FROM] > 3 || to[TO] > 5)
	{
		sprintf(from, "Airports Trivago, argument must be in the range of 3 or 5 respectively: %i", 3 | 5);
		throw invalid_argument(from);
		throw invalid_argument(to);
	}

	file2 << from << "->" << to << ";" << distance << endl;
	cout << endl;
	file2.close();
}

void Routes_FIles::readFile(char *buffer)
{

	ifstream file("Routes.txt", ios::in);

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

void Routes_FIles::reloadFile(char *old_from, char *new_from, char *to, double new_distance)
{
	ifstream file("Routes.txt", ios::in);
	ofstream file_tmp("Ex.txt");

	string tmp_string;

	if (!file || !file_tmp)
	{
		cout << "No file found.";
		return;
	}

	while (getline(file, tmp_string))
	{
		string str = tmp_string.substr(0, 3);

		if (str == old_from)
		{
			deleteRoute(old_from);
			str = new_from;
			file_tmp << str << "->" << to << ";" << new_distance << endl;
		}
		else if (str != old_from)
		{
			file_tmp << tmp_string << endl;
		}
	}


	file.close();
	file_tmp.close();

	std::remove("Routes.txt");
	std::rename("Ex.txt", "Routes.txt");
}

void Routes_FIles::deleteRoute(char *from)
{
	ifstream file("Routes.txt", ios::in);
	ofstream file2("Ex1.txt");

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

		if (str != from)
		{
			file2 << line << endl;
		}
	}

	file.close();
	file2.close();

	remove("Routes.txt");
	rename("Ex1.txt", "Routes.txt");
}

