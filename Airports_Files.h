#ifndef AIRPORTS_FILES_H
#define AIRPORTS_FILES_H

#include <iostream>

class Airports_Files
{

public:
    Airports_Files();
    std::string getCountry();
    std::string getID();
    void FileInput();
    void generateAirports();
};

#endif // !AIRPORTS_FILES_H
