#ifndef _PATIENTDB_H
#define _PATIENTDB_H
#include <string>
#include <vector>
#include "maindb.h"
#include "patient.h"
using namespace std;
class CPatdb:public CDatabase
{
public:
   
    vector<CPatient> dbSelect(string);
    int dbInsert(CPatient );
    string genPatientid(); 
    int findPatientid(string );
    CPatient dbSelect1(string);
};
#endif

