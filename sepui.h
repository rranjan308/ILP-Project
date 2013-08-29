#ifndef _SEPUI_H
#define _SEPUI_H
#include <vector>
#include <string.h>
#include "sepemployee.h"
#include "sepdb.h"
#include "maindb.h"
using namespace std;

class CSepEmployeeUI
{
public:
	void archiveSepEmployee(CSepEmployeeDb &m);
	void saveSepEmployee(vector<CSepEmployee>,CSepEmployeeDb &m);
	void viewSepEmployee(CSepEmployeeDb &m);
	 void viewSepEmployeebyId(CSepEmployeeDb &m);
	void displaySepEmployeebyId(vector<CSepEmployee>);
	void displayString(string str);
	int getOption();
	void setBrId(string);
	void displaySepEmployee(vector<CSepEmployee>);
};

#endif
