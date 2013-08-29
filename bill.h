#ifndef _BILL_H
#define _BILL_H
#include<string>
using namespace std;

class CBill

	{
		
		string m_sBillid;
		string m_sPatientid;
		string m_sDate;
		int m_iBillamt;
		string m_iBranchid;
		string m_sBtype;
	public:
		
		string getBilldate();
 		int getBillamt();
		string getPatientid();
		string getBillid();
		string getBranchid();
		string getBilltype();

		void setBilldate(string);
		void setBillamt(int);
		void setBranchid(string);
		void setPatientid(string);
		void setBillid(string);
		void setBilltype(string);		
	};





#endif
