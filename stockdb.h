
#ifndef _stockdb_H
#define _stockdb_H
#include <vector>
#include "stock.h"
#include"maindb.h"
#include"login.h"
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
class CStockdb:public CDatabase
{
//protected:
//	int m_sStockid;
public:
//	CStockdb();
//	int dbConnect();
//	int dbDisConnect();
    	//void dbError();
	vector <CStock> dbSelectStock();
	int dbInsertStock(CStock );
	string genStockID();
	vector<CUserlogin> userLogin(string,string);
//	void setbloddstockid(int);
  //      int getbloddstockid();

};
#endif

