#include <iostream>
#include "billdb.h"
#include <string>
#include "maindb.h"
#include "bill.h"
#include <occi.h>
#include "patdb.h"
#include<sstream>
using namespace oracle::occi;
using namespace std;
#define _NO_DATA_FOUND 1403
#define SUCCESS 1
#define FAILURE 0


int CBilldb::dbInsert(CBill bill)
{
    int Result=0; 
    if(1==dbConnect())
    { 
        try {
                 Statement *stmt1=m_pconn->createStatement(" insert into  bill values (:1,:2,to_char(SYSDATE,'dd/mm/yyyy'),:3,:4) ");
                 stmt1->setString(1,bill.getBillid());
                 stmt1->setString(2,bill.getPatientid());
		 //stmt1->setString(3,bill.getBilldate());
		 stmt1->setInt(3,bill.getBillamt());
		 stmt1->setString(4,bill.getBranchid());
		  
                 Result=stmt1->executeUpdate()
		;
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



string CBilldb::genBillid()
{

	  if(1==dbConnect())
	  {
           Statement *stmt1=m_pconn->createStatement("select billseq.nextval from dual");
           ResultSet *rs1=stmt1->executeQuery();
           rs1->next();
	   int id=rs1->getInt(1);
		string strid="BillNo";
	   stmt1->closeResultSet(rs1);
           m_pconn->terminateStatement(stmt1);
		ostringstream oss;
		oss<<strid<<id;
		strid=oss.str();
	   return strid;

	}
}



vector<CBill> CBilldb::dbSelect(string brid)
{


     vector<CBill> bill_records;
    if(0==dbConnect())
    {
        return bill_records;
    }
    else
    {
       try 
       {
           Statement *stmt1=m_pconn->createStatement(" select * from bill where branchid=:1 order by billdate desc");
	   stmt1->setString(1,brid);
           ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {
                
                
		CBill c;
		c.setBillid(rs1->getString(1));
		c.setPatientid(rs1->getString(2));
		c.setBilldate(rs1->getString(3));
		c.setBillamt(rs1->getInt(4));
		c.setBranchid(rs1->getString(5));
		bill_records.push_back(c);
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
       return bill_records;
    }

}


CBill CBilldb::dbSelect1(string bid)
{


     CBill c;
    if(0==dbConnect())
    {
        return c;
    }
    else
    {
       try
       {
           Statement *stmt1=m_pconn->createStatement(" select * from bill where billid=:1");
           stmt1->setString(1,bid);
           ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {


                
                c.setBillid(rs1->getString(1));
                c.setPatientid(rs1->getString(2));
                c.setBilldate(rs1->getString(3));
                c.setBillamt(rs1->getInt(4));
                c.setBranchid(rs1->getString(5));
               // bill_records.push_back(c);
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
       return c;
    }

}







CBill CBilldb::dbBillselect()
{     CBill bill_records;
      string btype;
	int amount;
    if(0==dbConnect())
    {
        return bill_records;
    }
    else
    {
       try
       {
           Statement *stmt1=m_pconn->createStatement(" select * from billtype ");
          // stmt1->setString(1,btype);
	  // stmt1->setInt(2,amount);
           ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {

                CBill c;
                btype=rs1->getString(1);
                amount=rs1->getInt(2);
                bill_records.setBilltype(btype);
		bill_records.setBillamt(amount);                
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
       return bill_records;
    }

}



int CBilldb::findBillid(string bid)
{
    int Result; 
   string id; 
   
   if(1==dbConnect())
    { 
        try {
            Statement *stmt1=m_pconn->createStatement(" select billid from bill  WHERE billid=:1");
            stmt1->setString(1,bid);
            ResultSet *rs1=stmt1->executeQuery();
  //          cout<<"\nconnected";
	    rs1->next();
	    id=rs1->getString(1);
		
            if(id==bid)
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

