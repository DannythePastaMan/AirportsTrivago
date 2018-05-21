#ifndef AIRPORTS_FILES_H
#define AIRPORTS_FILES_H

#include <iostream>

class Airports_Files
{

public:
    Airports_Files();
    void createFile(char *, char *, double, double);
    void readFile(char *, int);
    void reloadFile(char *, char *, char *, double, double);
};

#endif // !AIRPORTS_FILES_H
