#ifndef AIRPORTS_FILES_H
#define AIRPORTS_FILES_H

#include <iostream>

class Airports_Files
{

public:
    Airports_Files();
    void createFile(char *, char *, double, double);
    void readFile(char *);
    void reloadFile(char *, char *, char *, double, double);
    void deleteLine(char *);
    void deleteLineAux(char *);
};

#endif // !AIRPORTS_FILES_H
