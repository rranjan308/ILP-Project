#include "bill.h"
void CBill::setBilltype(string date)
        {
        m_sBtype=date;
        }
void CBill::setBilldate(string date)
	{
	m_sDate=date;
	}

void CBill::setBillamt(int amt)
	{
	m_iBillamt=amt;
	}

void CBill::setBranchid(string amt)
	{
	m_iBranchid=amt;
	}
void CBill::setBillid(string amt)
	{
	m_sBillid=amt;
	}
void CBill::setPatientid(string amt)
	{
	m_sPatientid=amt;
	}

int CBill::getBillamt()
	{
	return m_iBillamt;
	}

string CBill::getBillid()
	{
	return m_sBillid;
	}

string CBill::getBilldate()
	{
	return m_sDate;
	}

string CBill::getPatientid()
	{
	return m_sPatientid;
	}
string CBill::getBranchid()
	{
	return m_iBranchid;
	}

string CBill::getBilltype()
        {
        return m_sBtype;
        }

