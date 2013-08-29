#include<occi.h>
#include<iostream>
#include<string>
#include<vector>
#include "sepdb.h"
#include "maindb.h"
#include "sepemployee.h"
using namespace oracle::occi;
using namespace std;
#define _NO_DATA_FOUND 1403
#define SUCCESS 1
#define FAILURE 0

				
                               

int CSepEmployeeDb::dbSaveSepEmployee(CSepEmployee cs)
{
    int Result=0;
    if(1==dbConnect())
    {
        try {
                Statement *stmt1=m_pconn->createStatement(" insert into seperated_employee values (:1,:2,:3,:4,:5,:6,:7,:8,:9,:10,:11) ");
                stmt1->setString(1,cs.getEmpId());
                stmt1->setString(2,cs.getEmpFName());
		stmt1->setString(3,cs.getEmpMName());
		stmt1->setString(4,cs.getEmpLName());
		stmt1->setString(5,cs.getGender());
		stmt1->setString(6,cs.getDob());
		stmt1->setString(7,cs.getAddr1());
		stmt1->setString(8,cs.getAddr2());
		stmt1->setString(9,cs.getPhNumber());
		stmt1->setString(10,cs.getIpin());
		stmt1->setString(11,cs.getBranchId());
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

vector<CSepEmployee> CSepEmployeeDb::dbFetchSepEmployee(string sbid)
{
	CSepEmployee emp;
	int st=0;
    vector<CSepEmployee> emp_records;
    if(0==dbConnect())
    {
        return emp_records;
    }
    else
 {
       try
 	{
           Statement *stmt1=m_pconn->createStatement(" select * from employee where status=:1 AND branchid=:2 AND empid NOT IN (select empid from seperated_employee)");
		stmt1->setInt(1,st);
		stmt1->setString(2,sbid);
           ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {
                emp.setEmpId(rs1->getString(1));
                emp.setEmpFName(rs1->getString(2));
		emp.setEmpMName(rs1->getString(3));
  		emp.setEmpLName(rs1->getString(4));
		emp.setGender(rs1->getString(5));
		emp.setDob(rs1->getString(6));
              	emp.setAddr1(rs1->getString(7));
		emp.setAddr2(rs1->getString(8));
		emp.setPhNumber(rs1->getString(9));
		emp.setIpin(rs1->getString(10));
		emp.setBranchId(rs1->getString(11));
                emp_records.push_back(emp);
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
       return emp_records;
        }

}


vector<CSepEmployee> CSepEmployeeDb::dbSelectSepEmployee(string bid)
{
CSepEmployee emp;

    vector<CSepEmployee> emp_records;
    if(0==dbConnect())
    {
        return emp_records;
    }
    else
 {
       try
 {
           Statement *stmt1=m_pconn->createStatement(" select * from seperated_employee where branchid=:1");
        	stmt1->setString(1,bid);   
	ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {
                emp.setEmpId(rs1->getString(1));
                emp.setEmpFName(rs1->getString(2));
                emp.setEmpMName(rs1->getString(3));
                emp.setEmpLName(rs1->getString(4));
                emp.setGender(rs1->getString(5));
                emp.setDob(rs1->getString(6));
                emp.setAddr1(rs1->getString(7));
                emp.setAddr2(rs1->getString(8));
                emp.setPhNumber(rs1->getString(9));
                emp.setIpin(rs1->getString(10));
                emp.setBranchId(rs1->getString(11));
                emp_records.push_back(emp);
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
       return emp_records;
        }

}

vector<CSepEmployee> CSepEmployeeDb::dbSelectSepEmployeebyId(string seid,string bid)
{
CSepEmployee emp;

    vector<CSepEmployee> emp_records;
    if(0==dbConnect())
    {
        return emp_records;
    }
    else
 {
       try
 {
           Statement *stmt1=m_pconn->createStatement(" select * from seperated_employee where empid=:1 AND branchid=:2");
		stmt1->setString(1,seid);
		stmt1->setString(2,bid);
           ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {
                emp.setEmpId(rs1->getString(1));
                emp.setEmpFName(rs1->getString(2));
                emp.setEmpMName(rs1->getString(3));
                emp.setEmpLName(rs1->getString(4));
                emp.setGender(rs1->getString(5));
                emp.setDob(rs1->getString(6));
                emp.setAddr1(rs1->getString(7));
                emp.setAddr2(rs1->getString(8));
                emp.setPhNumber(rs1->getString(9));
                emp.setIpin(rs1->getString(10));
                emp.setBranchId(rs1->getString(11));
                emp_records.push_back(emp);
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
       return emp_records;
        }

}

