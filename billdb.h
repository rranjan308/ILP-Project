#ifndef _BILLDB_H
#define _BILLDB_H
#include <string>
#include <vector>
#include "maindb.h"
#include "bill.h"
using namespace std;
class CBilldb:public CDatabase
{
public:
   
    vector<CBill> dbSelect(string);
    int dbInsert(CBill );
    string genBillid(); 
    CBill dbBillselect(); 
    CBill dbSelect1(string);
    int findBillid(string );
};
#endif

