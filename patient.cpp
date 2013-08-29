#include "patient.h"

void CPatient::setId(string a)
	{
	m_sId=a;
	}

void CPatient::setFname(string nm)
	{
	m_sFname=nm;
	}

void CPatient::setMname(string nm)
	{
	m_sMname=nm;
	}

void CPatient::setLname(string nm)
	{
	m_sLname=nm;
	}

void CPatient::setDob(string dob)
	{
	m_sDob=dob;
	}

void CPatient::setAdd(string add)
	{
	m_sAdd=add;
	}

void CPatient::setPin(string pin)
	{
	m_sPin=pin;
	}

void CPatient::setCity(string city)
	{
	m_sCity=city;
	}

void CPatient::setBgroup(string bl)
	{
	m_sBgroup=bl;
	}

void CPatient::setMstatus(string m)
	{
	m_sMststus=m;
	}

void CPatient::setMobile(string mob)
	{
	m_sMobile=mob;
	}

void CPatient::setEmgconnm(string nm)
	{
	m_sEmgconnm=nm;
	}

void CPatient::setEmgconno(string mob)
	{
	m_sEmgconno=mob;
	}

void CPatient::setBranchid(string id)
        {
        m_ibranchid=id;
        }
	
void CPatient::setDoctorID(string id)
        {
        m_sDoctorID=id;
        }

string CPatient::getId()
	{
	return m_sId; 
	}

string CPatient::getFname()
	{
	return m_sFname; 
	}

string CPatient::getMname()
	{
	return m_sMname;
	}

string CPatient::getLname()
	{
	return m_sLname;
	}

string CPatient::getDob()
	{
	return m_sDob; 
	}

string CPatient::getAdd()
	{
	return m_sAdd;
	}

string CPatient::getPin()
	{
	return m_sPin;
	}

string CPatient::getCity()
	{
	return m_sCity;
	}

string CPatient::getBgroup()
	{
	return m_sBgroup;
	}

string CPatient::getMstatus()
	{
	return m_sMststus;
	}

string CPatient::getMobile()
	{
	return m_sMobile;
	}

string CPatient::getEmgconnm()
	{
	return m_sEmgconnm;
	}

string CPatient::getEmgconno()
	{
	return m_sEmgconno;
	}

string CPatient::getBranchid()
        {
        return m_ibranchid;
        }

string CPatient::getDoctorID()
        {
        return m_sDoctorID;
        }
