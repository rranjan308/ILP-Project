#ifndef _SEPEMP_H
#define _SEPEMP_H
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;

class CSepEmployee
{
private:
	string m_iempid;
	string m_sempfname;
	string m_sempmname;
	string m_semplname;
	string m_cgender;
	string m_sdob;
	string m_saddr1;
	string m_saddr2;
	string m_ipin;
	string m_iphnumber;
	string m_ibranchid;

public:
	string getEmpId();
	string getEmpFName();
	string getEmpMName();
	string getEmpLName();
	string getGender();
	string getDob();
	string getAddr1();
	string getAddr2();
	string getPhNumber();
	string getIpin();
	string getBranchId();
	
	void setEmpId(string);
        void setEmpFName(string);
       void setEmpMName(string);
        void setEmpLName(string);
        void setGender(string);
        void setDob(string);
        void setAddr1(string);
        void setAddr2(string);
	void setPhNumber(string);
        void setIpin(string);
	void setBranchId(string);


};

#endif
