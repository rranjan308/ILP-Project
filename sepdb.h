#ifndef _SEPDB_H
#define _SEPDB_H
#include <vector>
#include<iostream>
#include<string>
#include "sepemployee.h"
#include "maindb.h"
#include "login.h"

using namespace std;

class CSepEmployeeDb:public CDatabase
{
public:
vector<CUserlogin>userLogin(string,string);
int dbSaveSepEmployee(CSepEmployee);
vector<CSepEmployee> dbFetchSepEmployee(string);
vector<CSepEmployee> dbSelectSepEmployee(string);
vector<CSepEmployee> dbSelectSepEmployeebyId(string,string);

};
#endif
