
#ifndef _DoctorDB_H
#define _DoctorDB_H
#include <vector>
#include "Doctor.h"
#include"maindb.h"
#include<string>
#include<iostream>
using namespace std;
class CDoctorDB:public CDatabase
{
public:
//	CAppointmentDB();
//	int dbConnect();
//	int dbDisConnect();
    	//void dbError();
	vector <CDoctor> dbselectDoctor(string);
	int findDocid(string);	
};
#endif
