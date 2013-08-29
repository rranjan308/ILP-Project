
#ifndef _APPOINTMENT_H
#define _APPOINTMENT_H
#include<vector>
#include<iostream>
#include <string>
using namespace std;
class CAppointment 
{
	  string m_sPatientID;
	  string m_sDoctorID;
 	  string m_sAppointmentID;
	  string m_sDate;
	  string m_sTime;
	  string m_sBranchID;
  public:

  string getPatientID();
  string getDoctorID();
  string getAppointmentID();
  string getApp_Date();
  string getApp_Time();
  string getBranchID();
  
  void setPatientID(string patientid);
  void setDoctorID(string doctorid);
  void setAppointmentID(string appid);
  void setApp_Date(string doa);
  void setApp_Time(string toa);
  void setBranchID(string branchid);
};
#endif

