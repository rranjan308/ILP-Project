
#ifndef _DOCTOR_H
#define _DOCTOR_H
#include<vector>
#include<iostream>
#include <string>
using namespace std;
class CDoctor 
{
	  string m_sDoctorID;
	  string m_sDocname;
	  string m_sTime;
	  string m_sBranchID;
  public:

  string getDoctorID();
  string getDocname();
  string getTime();
  string getBranchID();
  
	void setDoctorID(string doctorid);
	void setDocname(string dname);
        void setTime(string dtime);
        void setBranchID(string );  
};
#endif

