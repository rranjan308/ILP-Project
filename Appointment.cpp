#include "Appointment.h"
string CAppointment::getPatientID()
{
    return m_sPatientID;
}

string CAppointment::getDoctorID()
{
    return m_sDoctorID;
}

string CAppointment::getAppointmentID()
{
    return m_sAppointmentID;
}

string CAppointment::getApp_Date()
{
    return m_sDate;
}

string CAppointment::getApp_Time()
{
    return m_sTime;
}

string CAppointment::getBranchID()
{
    return m_sBranchID;
}

void CAppointment::setPatientID(string a)
{
	m_sPatientID=a;
}

void CAppointment::setDoctorID(string a)
{
	m_sDoctorID=a;
}

void CAppointment::setAppointmentID(string a)
{
	m_sAppointmentID=a;
}

void CAppointment::setApp_Date(string b)
{
	m_sDate=b;
}

void CAppointment::setApp_Time(string b)
{
	m_sTime=b;
}

void CAppointment::setBranchID(string a)
{
	m_sBranchID=a;
}
