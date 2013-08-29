#include<occi.h>
#include<string>
#include<iostream>
#include<vector>
#include"AppointmentDB.h"
#include"Appointment.h"
#include"maindb.h"
#include<sstream>
using namespace oracle::occi;
using namespace std;




int CAppointmentDB::dbinsertAppointment(CAppointment ca)
{
	int Result=0;
    if(1==dbConnect())
    {
        try
 	{
	Statement *stmt1=m_pconn->createStatement(" insert into Appointment values (:1,:2,:3,:4,:5) ");
	stmt1->setString(1,ca.getAppointmentID());
	stmt1->setString(2,ca.getPatientID());
	stmt1->setString(3,ca.getDoctorID());
	stmt1->setString(4,ca.getApp_Date());
//	stmt1->setString(5,ca.getApp_Time());
	stmt1->setString(5,ca.getBranchID());
	Result=stmt1->executeUpdate();
	if ( Result > 0 )
                 {
                     m_pconn->commit();
                     m_pconn->terminateStatement(stmt1);
                 }
	}
	catch (SQLException ea)
        {
            cerr << "Can't connect: " << ea.what();
        }
    }
    if(1==dbDisConnect())
    {
	 return Result;
    }
}
string CAppointmentDB::genAppid()
{

	  if(1==dbConnect())
	  {
           Statement *stmt1=m_pconn->createStatement("select appid.nextval from dual");
           ResultSet *rs1=stmt1->executeQuery();
           rs1->next();
	   int id=rs1->getInt(1);
		string strid="APP";
	   stmt1->closeResultSet(rs1);
           m_pconn->terminateStatement(stmt1);
		ostringstream oss;
		oss<<strid<<id;
		strid=oss.str();
	   return strid;

	}
}

/*int CAppointmentDB::valdate(string da)
{
	 if(1==dbConnect())
          {
	cout<<da;
           Statement *stmt1=m_conn->createStatement("select (to_date(da,'dd-mon-yyyy') - to_date(sysdate,'dd-mon-yyyy')) from dual");
           ResultSet *rs1=stmt1->executeQuery();
           rs1->next();
           int d=rs1->getInt(1);
                
           stmt1->closeResultSet(rs1);
           m_conn->terminateStatement(stmt1);
               
           return d;
}
}*/


vector<CAppointment> CAppointmentDB::dbselectAppointmentDoctor(string did)
{
    string adate;
    string pid,aid;


    vector<CAppointment> app_details;
    if(0==dbConnect())
    {
        return app_details;
    }
    else
    {
       try
       {
           Statement *stmt1=m_pconn->createStatement(" select * from appointment  where docid=:1 and appdate=to_char(SYSDATE,'dd-mm-yyyy')");
           stmt1->setString(1,did);
           ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {
                aid=rs1->getString(1);
                pid=rs1->getString(2);
                did=rs1->getString(3);
                adate=rs1->getString(4);
               // brid=rs1->getString(5);
//              atime=rs1->getString(5);
                CAppointment ca;
                ca.setAppointmentID(aid);
                ca.setPatientID(pid);
                ca.setDoctorID(did);
                ca.setApp_Date(adate);
               // ca.setBranchID(brid);
//              ca.setApp_Time(atime);
                app_details.push_back(ca);
           }
       stmt1->closeResultSet(rs1);
m_pconn->terminateStatement(stmt1);
       }
       catch (SQLException ea)
       {
           cerr << "Can't connect: " << ea.what();
       }
    }
    if(0==dbDisConnect())
        {
       return app_details;
        }

}



vector<CAppointment> CAppointmentDB::dbselectAppointment(string brid)
{
    string adate,atime;
    string pid,aid;
	string did;
    	
    vector<CAppointment> app_details;
    if(0==dbConnect())
    {
        return app_details;
    }
    else
    {
       try
       {
           Statement *stmt1=m_pconn->createStatement("select * from appointment where branchid=:1 and appdate=to_char(SYSDATE,'dd-mm-yyyy')");
	   stmt1->setString(1,brid);
	   ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {
                aid=rs1->getString(1);
                pid=rs1->getString(2);
		did=rs1->getString(3);
		adate=rs1->getString(4);
		brid=rs1->getString(5);
		//atime=rs1->getString(5);
                CAppointment ca;
		ca.setAppointmentID(aid);
		ca.setPatientID(pid);
		ca.setDoctorID(did);
		ca.setApp_Date(adate);
		ca.setBranchID(brid);
//		ca.setApp_Time(atime);
                app_details.push_back(ca);
           }
       stmt1->closeResultSet(rs1);
       m_pconn->terminateStatement(stmt1);
       }
       catch (SQLException ea)
       {
           cerr << "Can't connect: " << ea.what();
       }
    }
    if(0==dbDisConnect())
        {
       return app_details;
        }

}
