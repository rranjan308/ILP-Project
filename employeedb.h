#ifndef _DB_H
#define _DB_H
#include <string>
#include <vector>
#include "employee.h"
#include "maindb.h"


using namespace std;
class CEmployeeDB:public CDatabase
{
public:
 	vector<CUserlogin> userLogin(string,string);
    vector<CEmployee> dbSelect(string );
    int dbInsert(CEmployee );
    int dbDelete(string,int);
    int dbUpdate1(string,string,string);
    int dbUpdate2(string,string);  
    int dbUpdate3(string,string);
    string genEmployeeID();
    CEmployee dbSelect1(string,string);
    int findEmpNo(string,string);
};
#endif


