#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <string>
using namespace std;
class CEmployee 
  {
	  string m_iEmpid;
	  string m_sEmpfname;
	  string m_sEmpmname;
	  string m_sEmplname;
	  string m_Gender;
	  string m_sDob;
	  string m_sAddr1;
	  string m_sAddr2;
	  string m_iPin;
	  string m_iPhoneno;
	  int m_iStatus;
          string m_sBranchid;  
     public:
  	  string getEmpid();
	  string getEmpfname();
	  string getEmpmname();
	  string getEmplname();
	  string getGender();
	  string getDob();
	  string getAddr1();
	  string getAddr2();
	  string getPin();
	  string getPhoneno();
	  int getStatus();
	  string getBranchid();
	  
	  void setEmpid(string);
	  void setEmpfname(string);
	  void setEmpmname(string);
	  void setEmplname(string);
	  void setGender(string);
	  void setDob(string);
	  void setAddr1(string);
	  void setAddr2(string);
	  void setPin(string);
	  void setPhoneno(string);
	  void setStatus(int);
	  void setBranchid(string);
	
  };
#endif
