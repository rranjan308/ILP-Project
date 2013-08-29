#ifndef _PATIENTUI_H
#define _PATIENTUI_H
#include <vector>
#include "patient.h"
#include "patdb.h"
#include "Appointment.h"
#include "AppointmentDB.h"
#include "DoctorDB.h"
#include "Doctor.h"
#include "billdb.h"
#include "bill.h"


using namespace std;
class CPatientui
{
  public:
	void displayMenu();
	int getOption();
	void retrivePatrecords(CPatdb&);
	void viewPatientdetails(vector<CPatient>);
	void addPatientdetails(CPatdb&);
	void displayString(char* str);
	void displayError();
        int getOption1();
	void displayMenu1();
	void viewPatientdetails1(vector<CPatient>);
        void retrivePatrecords1(CPatdb&);
        
        void displayMenu2();	
  	void create_Appointment(CAppointmentDB &a, CDoctorDB &b, CPatdb &c);
//	void display_Appointment(vector<CAppointment>);
	void view_Appointment(CAppointmentDB &a);
	void view_AppointmentDoctor(CAppointmentDB &a);
	void display(vector<CAppointment>);
	string enterdate();

	void view_Doctor(CDoctorDB &a);
	void displayd(vector<CDoctor>);
	
	
	void retriveBillrecords(CBilldb&);
	void viewBilldetails(vector<CBill>);
	void addBilldetails(CBilldb& ,CPatdb& );
       void retriveBillrecords1(CBilldb&); 


	void displayMenudoctor();
	void setDocId(string);
	void setBrId(string);


};
#endif

