#include "Doctor.h"

string CDoctor::getDoctorID()
{
    return m_sDoctorID;
}


string CDoctor::getDocname()
{
    return m_sDocname;
}

string CDoctor::getTime()
{
    return m_sTime;
}

string CDoctor::getBranchID()
{
    return m_sBranchID;
}


void CDoctor::setDoctorID(string a)
{
	m_sDoctorID=a;
}

void CDoctor::setDocname(string a)
{
	m_sDocname=a;
}

void CDoctor::setTime(string a)
{
	m_sTime=a;
}

void CDoctor::setBranchID(string a)
{
        m_sBranchID=a;
}
