
#ifndef _AppointmentDB_H
#define _AppointmentDB_H
#include <vector>
#include "Appointment.h"
#include"maindb.h"
#include<string>
#include<iostream>
using namespace std;
class CAppointmentDB:public CDatabase
{
public:
//	CAppointmentDB();
//	int dbConnect();
//	int dbDisConnect();
    	//void dbError();
	vector <CAppointment> dbselectAppointment(string);
	int dbinsertAppointment(CAppointment);
	string genAppid();
	 vector <CAppointment> dbselectAppointmentDoctor(string);
//	int valdate(string);
};
#endif
