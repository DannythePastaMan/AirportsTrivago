#ifndef AIRPORTS_FILES_H
#define AIRPORTS_FILES_H

#include <iostream>

class Airports_Files
{

public:
    Airports_Files();
    void createFile(std::string, std::string, double, double);
    std::string readFile();
    void reloadFile();
};

#endif // !AIRPORTS_FILES_H
