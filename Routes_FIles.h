#pragma once
#include <iostream>

class Routes_FIles
{
public:

	void createFile(char *, char *, double);
	void readFile(char *);
	void reloadFile(char *, char *, char *, double);
	void deleteRoute(char *);
	Routes_FIles();
	~Routes_FIles();
};

