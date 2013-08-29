#include<occi.h>
#include<iostream>
#include<string>
#include<sstream>
#include "employeedb.h"
#include "employee.h"
using namespace oracle::occi;
using namespace std;
#define _NO_DATA_FOUND 1403
#define SUCCESS 1
#define FAILURE 0
      


int CEmployeeDB::dbInsert(CEmployee emp)
{
    int Result=0;
    if(1==dbConnect())
    {
        try {
                 Statement *stmt1=m_pconn->createStatement(" insert into employee values (:1,:2,:3,:4,:5,:6,:7,:8,:9,:10,:11,:12) ");
                 stmt1->setString(1,emp.getEmpid());
                 stmt1->setString(2,emp.getEmpfname());
		 stmt1->setString(3,emp.getEmpmname());
		 stmt1->setString(4,emp.getEmplname());
		 stmt1->setString(5,emp.getGender());
		 stmt1->setString(6,emp.getDob());
		 stmt1->setString(7,emp.getAddr1());
		 stmt1->setString(8,emp.getAddr2());
		 stmt1->setString(9,emp.getPhoneno());
		 stmt1->setString(10,emp.getPin());
		 stmt1->setString(11,emp.getBranchid());
		 stmt1->setInt(12,emp.getStatus());
	//	 stmt1->setString(12,emp.getEmpid());
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


string CEmployeeDB::genEmployeeID()
{

	  if(1==dbConnect())
	  {
           Statement *stmt1=m_pconn->createStatement("select empid.nextval from dual");
           ResultSet *rs1=stmt1->executeQuery();
           rs1->next();
	   int id=rs1->getInt(1);
		string strid="EMP";
	   stmt1->closeResultSet(rs1);
           m_pconn->terminateStatement(stmt1);
		ostringstream oss;
		oss<<strid<<id;
		strid=oss.str();
	   return strid;

	}
}

vector<CEmployee> CEmployeeDB::dbSelect(string branchid)
{ //  CUserlogin log;
    string empfname;
    string empmname;
    string emplname;
    string empid;
    string gender;
    string dob;
    string addr1;
    string addr2;
    string phoneno;
    string pin;
//    string branchid;
    int status;
//    int Result=0;
    vector<CEmployee> emp_records;
    if(0==dbConnect())
    { 
        return emp_records;
    }
    else
    {
       try
       {
		
           Statement *stmt1=m_pconn->createStatement(" select * from EMPLOYEE where status=1 and branchid=:1");
          // ResultSet *rs1=stmt1->executeQuery();
	   stmt1->setString(1,branchid);
	//   Result=stmt1->executeQuery();
	   ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {
                empid=rs1->getString(1);
                empfname=rs1->getString(2);
                empmname=rs1->getString(3);
		emplname=rs1->getString(4);
		gender=rs1->getString(5);
		dob=rs1->getString(6);
		addr1=rs1->getString(7);
		addr2=rs1->getString(8);
		phoneno=rs1->getString(9);
		pin=rs1->getString(10);
		branchid=rs1->getString(11);
		status=rs1->getInt(12);
		CEmployee e;
		e.setEmpid(empid);
		e.setEmpfname(empfname);
		e.setEmpmname(empmname);
		e.setEmplname(emplname);
		e.setGender(gender);
		e.setDob(dob);
		e.setAddr1(addr1);
		e.setAddr2(addr2);
		e.setPhoneno(phoneno);
		e.setPin(pin);
		e.setBranchid(branchid);
		e.setStatus(status);
                emp_records.push_back(e);
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
        {cout<<"disc";
       return emp_records;
        }

}
int CEmployeeDB::dbUpdate1(string empid,string addr1,string addr2)
{
    int Result=0; 
    if(1==dbConnect())
    { 
        try {
            Statement *stmt1=m_pconn->createStatement(" update employee set address1=:1,address2=:2 where empid=:3");
            stmt1->setString(3,empid);
            stmt1->setString(1,addr1);
	    stmt1->setString(2,addr2);

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
	return Result;
    }
    if(0==dbDisConnect())
    {
       return Result;
    }
}

CEmployee CEmployeeDB::dbSelect1(string branchid, string emp_id)
{
    string empfname;
    string empmname;
    string emplname;
   // string empid;
    string gender;
    string dob;
    string addr1;
    string addr2;
    string phoneno;
    string pin;
    int status;
    CEmployee emp_record;
    if(0==dbConnect())
    {
        return emp_record;
    }
    else
    {
       try
       {
        Statement *stmt1=m_pconn->createStatement(" select * from EMPLOYEE where status=1 and branchid=:1 and empid=:2");
        stmt1->setString(1,branchid);
        stmt1->setString(2,emp_id);
        ResultSet *rs1=stmt1->executeQuery();
        while(rs1->next())
           {
                emp_id=rs1->getString(1);
                empfname=rs1->getString(2);
                empmname=rs1->getString(3);
                emplname=rs1->getString(4);
                gender=rs1->getString(5);
                dob=rs1->getString(6);
                addr1=rs1->getString(7);
                addr2=rs1->getString(8);
                phoneno=rs1->getString(9);
                pin=rs1->getString(10);
                branchid=rs1->getString(11);
                status=rs1->getInt(12);
		 emp_record.setEmpid(emp_id);
                emp_record.setEmpfname(empfname);
                emp_record.setEmpmname(empmname);
                emp_record.setEmplname(emplname);
                emp_record.setGender(gender);
                emp_record.setDob(dob);
                emp_record.setAddr1(addr1);
                emp_record.setAddr2(addr2);
                emp_record.setPhoneno(phoneno);
                emp_record.setPin(pin);
                emp_record.setBranchid(branchid);
                emp_record.setStatus(status);
               // emp_records.push_back(e);
           }

        stmt1->closeResultSet(rs1);

       m_pconn->terminateStatement(stmt1);
       }
       catch (SQLException ea)
       {
         // cerr << "Can't connect: " << ea.what();
       }
    }
    if(0==dbDisConnect())
        {//cout<<"disc";
       return emp_record;
        }

}

int CEmployeeDB::dbUpdate2(string empid, string phno)
{
    int Result=0;
    if(1==dbConnect())
    {
        try {
            Statement *stmt1=m_pconn->createStatement(" update employee set phoneno=:1 where empid=:2");
            stmt1->setString(2,empid);
	    stmt1->setString(1,phno);
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
     return Result;
    }
    if(0==dbDisConnect())
    {
       return Result;
    }
}

int CEmployeeDB::dbUpdate3(string empid,string pin)
{
    int Result=0;
    if(1==dbConnect())
    {
        try {
            Statement *stmt1=m_pconn->createStatement(" update EMPLOYEE set PIN=:1 where EMPID=:2");
            stmt1->setString(2,empid);
            stmt1->setString(1,pin);
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
   return Result; 
   }
    if(0==dbDisConnect())
    {
       return Result;
    }
}
	
int CEmployeeDB::dbDelete(string empid,int status)
{
    int Result=0; 
    if(1==dbConnect())
    { 
        try {
            Statement *stmt1=m_pconn->createStatement(" update EMPLOYEE set STATUS=:1 where EMPID=:2");
            stmt1->setString(2,empid);
	    stmt1->setInt(1,status);
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
   return Result;
   }
    if(0==dbDisConnect())
    {
       return Result;
    }
}
int CEmployeeDB::findEmpNo(string eid,string branchid)
{
    int Result=0;
    if(1==dbConnect())
    {
        try {
            Statement *stmt1=m_pconn->createStatement(" select EMPID from EMPLOYEE where EMPID=:1 and branchid=:2");
            stmt1->setString(1,eid);
	    stmt1->setString(2,branchid);
            ResultSet *rs1=stmt1->executeQuery();
            rs1->next();
            if ( rs1->getString(1) == eid )
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
    return Result;
  }
    if(0==dbDisConnect())
    {
       return Result;
    }
}


