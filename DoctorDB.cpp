#include<occi.h>
#include<string>
#include<iostream>
#include<vector>
#include"DoctorDB.h"
#include"Doctor.h"
#include"maindb.h"
using namespace oracle::occi;
using namespace std;




/*int CDoctorDB::dbinsertAppointment(CAppointment ca)
{
	int Result=0;
    if(1==dbConnect())
    {
        try
 	{
	Statement *stmt1=m_conn->createStatement(" insert into Appointment values (:1,:2,:3,:4,:5,:6) ");
	stmt1->setInt(1,ca.getAppointmentID());
	stmt1->setInt(2,ca.getPatientID());
	stmt1->setInt(3,ca.getDoctorID());
	stmt1->setString(4,ca.getApp_Date());
	stmt1->setString(5,ca.getApp_Time());
	stmt1->setInt(6,ca.getBranchID());
	Result=stmt1->executeUpdate();
	if ( Result > 0 )
                 {
                     m_conn->commit();
                     m_conn->terminateStatement(stmt1);
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
}*/


int CDoctorDB::findDocid(string did)
{
    int Result; 
    if(1==dbConnect())
    {//cout<<"connnnnnnect"; 
        try {
            Statement *stmt1=m_pconn->createStatement(" select docid  from doctor WHERE docid=:1");
            stmt1->setString(1,did);
            ResultSet *rs1=stmt1->executeQuery();
            rs1->next();
            if ( rs1->getString(1) == did )
               Result=1;
            else
               Result=-2;
            stmt1->closeResultSet(rs1);
            m_pconn->terminateStatement(stmt1);
        }
        catch (SQLException ea)
        {
            cerr << "Can.t connect: " << ea.what();
        }
    }
    if(1==dbDisConnect())
    {
//cout<<"---------------------"<<Result;     
 return Result;
    }
}

vector<CDoctor> CDoctorDB::dbselectDoctor(string branchid)
{
    string did,dname,dtime;

   
    	
    vector<CDoctor> doc_details;
    if(0==dbConnect())
    {
        return doc_details;
    }
    else
    {
       try

       {
           Statement *stmt1=m_pconn->createStatement(" select * from doctor where branchid=:1");
 	   stmt1->setString(1,branchid);
           ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {
                did=rs1->getString(1);
                dname=rs1->getString(2);
		dtime=rs1->getString(3);

		branchid=rs1->getString(4);
		
		CDoctor cd;
		
		cd.setDoctorID(did);
		cd.setDocname(dname);
		cd.setTime(dtime);
		cd.setBranchID(branchid);
                doc_details.push_back(cd);
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
       return doc_details;
        }

}
