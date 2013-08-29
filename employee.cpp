#include "employee.h"
#include <string>
string CEmployee::getEmpid()
	{
	return m_iEmpid;
	}
string CEmployee::getEmpfname()
	{
	return m_sEmpfname;	
	}
string CEmployee::getEmpmname()
	{	
	return m_sEmpmname;
	}
string CEmployee::getEmplname()
	{
	return m_sEmplname;
	}
string CEmployee::getGender()
	{
	return m_Gender;
	}
string CEmployee::getDob()
	{
	return m_sDob;
	}
string CEmployee::getAddr1()
	{
	return m_sAddr1;
	}
string CEmployee::getAddr2()
	{
	return m_sAddr2;
	}
string CEmployee::getPin()
	{
	return m_iPin;	
	}
string CEmployee::getPhoneno()
	{
	return m_iPhoneno;
	}
int CEmployee::getStatus()
	{
	return m_iStatus;
	}
string CEmployee::getBranchid()
	{
	return m_sBranchid;
	}
void CEmployee::setEmpid(string a)
	{
	m_iEmpid=a;
	}
void CEmployee::setEmpfname(string nm)
	{
	m_sEmpfname=nm;
	}
void CEmployee::setEmpmname(string nm)
        {
        m_sEmpmname=nm;
        }
void CEmployee::setEmplname(string nm)
        {
        m_sEmplname=nm;
        }
void CEmployee::setGender(string c)
	{
	m_Gender=c;
	}
void CEmployee::setDob(string nm)
	{
	m_sDob=nm;
	}
void CEmployee::setAddr1(string nm)
	{
	m_sAddr1=nm;
	}
void CEmployee::setAddr2(string nm)
        {
        m_sAddr2=nm;
        }
void CEmployee::setPin(string i)
        {
        m_iPin=i;
        }
void CEmployee::setPhoneno(string l)
        {
        m_iPhoneno=l;
        }
void CEmployee::setStatus(int i)
        {
        m_iStatus=i;
        }
void CEmployee::setBranchid(string i)
        {
        m_sBranchid=i;
        }


