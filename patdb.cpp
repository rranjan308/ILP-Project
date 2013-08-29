#include <iostream>
#include "patdb.h"
#include <string>
#include "maindb.h"
#include "patient.h"
#include <occi.h>
#include<sstream>
using namespace oracle::occi;
using namespace std;
#define _NO_DATA_FOUND 1403
#define SUCCESS 1
#define FAILURE 0



int CPatdb::dbInsert(CPatient pat)
{
    int Result=0; 
    if(1==dbConnect())
    { 
        try {
                 Statement *stmt1=m_pconn->createStatement(" insert into  patient values (:1,:2,:3,:4,:5,:6,:7,:8,:9,:10,:11,:12,:13,:14) ");
                 stmt1->setString(1,pat.getId());
                 stmt1->setString(2,pat.getFname());
		 stmt1->setString(3,pat.getMname());
		 stmt1->setString(4,pat.getLname());
		 stmt1->setString(5,pat.getDob());
		 stmt1->setString(6,pat.getAdd());
		 stmt1->setString(7,pat.getCity());
		 stmt1->setString(8,pat.getPin());
                 stmt1->setString(9,pat.getBgroup());
		 stmt1->setString(10,pat.getMstatus());
		 stmt1->setString(11,pat.getMobile());
		 stmt1->setString(12,pat.getEmgconnm());
		 stmt1->setString(13,pat.getEmgconno());
		 stmt1->setString(14,pat.getBranchid());

                 Result=stmt1->executeUpdate();
                 if ( Result > 0 )
                 {
                     m_pconn->commit();
                     m_pconn->terminateStatement(stmt1);
                 }
        }
        catch (SQLException ea)
        {
            cerr << "Can.t connect: " << ea.what();
        }
    }
    if(1==dbDisConnect())
    {
       return Result;
    }
}


string CPatdb::genPatientid()
{

	  if(1==dbConnect())
	  {
           Statement *stmt1=m_pconn->createStatement("select patseq.nextval from dual");
           ResultSet *rs1=stmt1->executeQuery();
           rs1->next();
	   int id=rs1->getInt(1);
		string strid="PAT";
	   stmt1->closeResultSet(rs1);
           m_pconn->terminateStatement(stmt1);
		ostringstream oss;
		oss<<strid<<id;
		strid=oss.str();
	   return strid;

	}
}


vector<CPatient> CPatdb::dbSelect(string brid)
{
//string bid;
string fnm,mnm,lnm,emgnm,mstatus,city,bgroup;
string dob,add,id;
string pin,mobile,emobile;


     vector<CPatient> pat_records;
    if(0==dbConnect())
    {
        return pat_records;
    }
    else
    {
       try 
       {
           Statement *stmt1=m_pconn->createStatement(" select * from patient where branchid =:1");
           stmt1->setString(1,brid);
           ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {
                id=rs1->getString(1);
		fnm=rs1->getString(2);
                mnm=rs1->getString(3);
		lnm=rs1->getString(4);
		dob=rs1->getString(5);
		add=rs1->getString(6);
		city=rs1->getString(7);
		pin=rs1->getString(8);
		bgroup=rs1->getString(9);
		mstatus=rs1->getString(10);
		mobile=rs1->getString(11);
		emgnm=rs1->getString(12);
		emobile=rs1->getString(13);
		brid=rs1->getString(14);
                CPatient e;
		e.setId(id);
		e.setFname(fnm);
		e.setMname(mnm);
		e.setLname(lnm);
		e.setDob(dob);
		e.setAdd(add);
		e.setCity(city);
		e.setPin(pin);
		e.setBgroup(bgroup);
		e.setMstatus(mstatus);
		e.setMobile(mobile);
		e.setEmgconnm(emgnm);
		e.setEmgconno(emobile);
		e.setBranchid(brid);
                pat_records.push_back(e);
           }
       stmt1->closeResultSet(rs1);
       m_pconn->terminateStatement(stmt1);
       }
       catch (SQLException ea)
       {
           cerr << "Can.t connect: " << ea.what();
       }
    }
    if(0==dbDisConnect())
    {
       return pat_records;
    }

}



CPatient CPatdb::dbSelect1(string patid)
{
//string bid;
string fnm,mnm,lnm,emgnm,mstatus,city,bgroup;
string dob,add,id,brid;
string pin,mobile,emobile;


     CPatient e;
    if(0==dbConnect())
    {
        return e;
    }
    else
    {
       try
       {
           Statement *stmt1=m_pconn->createStatement(" select * from patient where patid =:1");
           stmt1->setString(1,patid);
           ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {
                id=rs1->getString(1);
                fnm=rs1->getString(2);
                mnm=rs1->getString(3);
                lnm=rs1->getString(4);
                dob=rs1->getString(5);
                add=rs1->getString(6);
                city=rs1->getString(7);
                pin=rs1->getString(8);
                bgroup=rs1->getString(9);
                mstatus=rs1->getString(10);
                mobile=rs1->getString(11);
                emgnm=rs1->getString(12);
                emobile=rs1->getString(13);
                brid=rs1->getString(14);
               
                e.setId(id);
                e.setFname(fnm);
                e.setMname(mnm);
                e.setLname(lnm);
                e.setDob(dob);
                e.setAdd(add);
                e.setCity(city);
                e.setPin(pin);
                e.setBgroup(bgroup);
                e.setMstatus(mstatus);
                e.setMobile(mobile);
                e.setEmgconnm(emgnm);
                e.setEmgconno(emobile);
                e.setBranchid(brid);
                
           }
       stmt1->closeResultSet(rs1);
       m_pconn->terminateStatement(stmt1);
       }
       catch (SQLException ea)
       {
           cerr << "Can.t connect: " << ea.what();
       }
    }
    if(0==dbDisConnect())
    {
       return e;
    }
}




int CPatdb::findPatientid(string pid)
{
    int Result; 
   string id; 
   
   if(1==dbConnect())
    { 
        try {
            Statement *stmt1=m_pconn->createStatement(" select patid from patient  WHERE patid=:1");
            stmt1->setString(1,pid);
            ResultSet *rs1=stmt1->executeQuery();
  //          cout<<"\nconnected";
	    rs1->next();
	    id=rs1->getString(1);
		
            if(id==pid)
               Result=1;
            else
               Result=-2;
//	  cout<<"result"<<Result;
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
       return Result;
    }
}
