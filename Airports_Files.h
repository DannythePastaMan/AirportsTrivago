#ifndef AIRPORTS_FILES_H
#define AIRPORTS_FILES_H

#include <iostream>

class Airports_Files
{

public:
    Airports_Files();
    void createFile(char *, char *, double, double);
    std::string readFile();
    void reloadFile(char *, char *);
};

#endif // !AIRPORTS_FILES_H
