#ifndef AIRPORTS_FILES_H
#define AIRPORTS_FILES_H

#include <iostream>
#include <vector>
#include <fstream>

struct Airport
{
    int *ID;
    std::string *name;
    std::vector<std::string *> countries;
    std::vector<std::string *> IDs;
    double *lat, *lon;

};

class Airports_Files
{


};

#endif // !AIRPORTS_FILES_H
