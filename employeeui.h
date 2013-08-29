#ifndef _EMPLOYEEUI_H
#define _EMPLOYEEUI_H
#include <vector>
#include "employee.h"
#include<iostream>
#include <string>
#include "employeedb.h"
using namespace std;
class CEmployeeUI
{
char m_ch1[10],m_ch[10];
  public:
	void displaymenu();
	int getOption();
	void displayString(char*);
	string getDate();
	void display(vector<CEmployee>);
	void displayError();
	void retrieveEmpRecords(CEmployeeDB &m);
	void displaymenu2(); 
	void displaymenu3();
	void retrieveEmpRecords1(CEmployeeDB &m);
	void addEmpDetails(CEmployeeDB &m);
	void updateEmpDetails(CEmployeeDB &m);
	void deleteEmpDetails(CEmployeeDB &m);
	void setBrId(string);
	void displaylogo();
};

#endif

	 

