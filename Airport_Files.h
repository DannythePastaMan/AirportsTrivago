#ifndef AIRPORTS_FILES_H
#define AIRPORTS_FILES_H

#include <iostream>

class Airports_Files
{

public:
	Airports_Files();
	void createFile(char *, char *, double, double);
	void readFile();
	void reloadFile(std::string , std::string, std::string, double, double);
	void deleteLine(std::string);
};

#endif // !AIRPORTS_FILES_H

