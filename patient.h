#ifndef _PATIENT_H
#define _PATIENT_H
#include<string>
using namespace std;

class CPatient
 
	{
		string m_sId;
		string m_sFname;
		string m_sMname;
		string m_sLname;
		string m_sDob;
		string m_sAdd;
		string m_sPin;
		string m_sCity;
		string m_sBgroup;
		string m_sMststus;
		string m_sMobile;
		string m_sEmgconnm;
		string m_sEmgconno;
		string m_ibranchid;	
		string m_sDoctorID;	
	public:

		string getId();
		string getFname();
		string getMname();
		string getLname();
		string getDob();
		string getAdd();
		string getPin();
		string getCity();
		string getBgroup();
		string getMstatus();
		string getMobile();
		string getEmgconnm();
		string getEmgconno();
 		string getBranchid();
		string getDoctorID();

		void setId(string);
		void setLname(string);
		void setFname(string);
		void setMname(string);
		void setDob(string);
		void setAdd(string);
		void setPin(string);
		void setCity(string);
		void setBgroup(string);
		void setMstatus(string);
		void setMobile(string);
		void setEmgconnm(string);
		void setEmgconno(string);
		void setBranchid(string);
		void setDoctorID(string);
	};

#endif



