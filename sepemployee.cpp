#include "sepemployee.h"
string CSepEmployee::getEmpId()
{
return m_iempid;
}

void CSepEmployee::setEmpId(string eid)
{
m_iempid=eid;
}
string CSepEmployee::getEmpFName()
{
return m_sempfname;
}

void  CSepEmployee::setEmpFName(string fname)
{
m_sempfname=fname;
}


void  CSepEmployee::setEmpMName(string mname)
{
m_sempmname=mname;
}

void  CSepEmployee::setEmpLName(string lname)
{
m_semplname=lname;
}


string CSepEmployee::getEmpMName()
{
return m_sempmname;
}

string CSepEmployee::getEmpLName()
{
return m_semplname;
}

string CSepEmployee::getGender()
{
return m_cgender;
}

void CSepEmployee::setGender(string ch)
{
m_cgender=ch;
}

string CSepEmployee::getDob()
{
return m_sdob;
}

void CSepEmployee::setDob(string dob)
{
m_sdob=dob;
}

string CSepEmployee::getAddr1()
{
return m_saddr1;
}

void  CSepEmployee::setAddr1(string addr1)
{
 m_saddr1=addr1;
}

void  CSepEmployee::setAddr2(string addr2)
{
 m_saddr2=addr2;
}



string CSepEmployee::getAddr2()
{
return m_saddr2;
}


string CSepEmployee::getIpin()
{
return m_ipin;
}

void CSepEmployee::setIpin(string pin)
{
m_ipin=pin;
}

string CSepEmployee::getPhNumber()
{
return m_iphnumber;
}

void CSepEmployee::setPhNumber(string phnum)
{
m_iphnumber=phnum;
}

string CSepEmployee::getBranchId()
{
return m_ibranchid;
}

void CSepEmployee::setBranchId(string  branchid)
{
m_ibranchid=branchid;
}
