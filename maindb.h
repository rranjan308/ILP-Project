#ifndef _maindb_H
#define _maindb_H
#include <occi.h>
#include<iostream>
#include<string>
#include "login.h"
using namespace oracle::occi;
using namespace std;
#define _NO_DATA_FOUND 1403
#define SUCCESS 1
#define FAILURE 0
class CDatabase
{
protected:
	Environment *m_penv;
	Connection *m_pconn;
	string m_susername;
	string m_spassword;
	string m_sdatabase;
public:
	int dbConnect();
	int dbDisConnect();
	vector<CUserlogin> userLogin(string,string);
};
#endif
