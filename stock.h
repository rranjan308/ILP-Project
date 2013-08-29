#ifndef _stock_h
#define _stock_h
#include<string>
#include<iostream>
using namespace std;

class CStock
{

private:
	string m_sBloodGroup;
	string m_sQuantity;
	string m_sPrice;
	string m_iBranchID;
	string m_sDate;
	string m_sExDate;
	string m_sStockID;
public:
	CStock();
	string getBloodGroup();
	void setBloodGroup(string);
	string getBloodQuantity();
	void setBloodQuantity(string);
	string getPrice();
	void setPrice(string);
	string getDate();
	void setDate(string);
	 string getExDate();
        void setExDate(string);
	string getBranchID();
	void setBranchID(string);
	void setBloodStockID(string);
	string getBloodStockID();


};	
#endif

