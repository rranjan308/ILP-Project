#include<occi.h>
#include<string>
#include<iostream>
#include<vector>
#include<sstream>
#include"stockdb.h"
#include"stock.h"
#include"maindb.h"
#include"login.h"
using namespace oracle::occi;
using namespace std;



int CStockdb::dbInsertStock(CStock cs)
{
	int Result=0;
    if(1==dbConnect())
    {
        try
 	{
	Statement *stmt1=m_pconn->createStatement(" insert into blood_stock values (:1,:2,:3,:4,:5,:6,:7) ");
	stmt1->setString(1,cs.getBloodGroup());
	stmt1->setString(2,cs.getBloodStockID());
	stmt1->setString(3,cs.getBloodQuantity());
	stmt1->setString(4,cs.getPrice());
	stmt1->setString(5,cs.getDate());
	stmt1->setString(6,cs.getExDate());
	stmt1->setString(7,cs.getBranchID());
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

string CStockdb::genStockID()
{

	  if(1==dbConnect())
	  {
           Statement *stmt1=m_pconn->createStatement("select bloodstockid.nextval from dual");
           ResultSet *rs1=stmt1->executeQuery();
           rs1->next();
	   int id=rs1->getInt(1);
		string strid="stock";
	   stmt1->closeResultSet(rs1);
           m_pconn->terminateStatement(stmt1);
		ostringstream oss;
		oss<<strid<<id;
		strid=oss.str();
	   return strid;

	}
}


vector<CStock> CStockdb::dbSelectStock()
{
    string sbgroup,spdate,ibid,sedate;
    string squantity;
	string istock;
    string sprice;	
    vector<CStock> blood_records;
    if(0==dbConnect())
    {
        return blood_records;
    }
    else
    {
       try
       {
           Statement *stmt1=m_pconn->createStatement(" select * from blood_stock");
           ResultSet *rs1=stmt1->executeQuery();
           while(rs1->next())
           {
                sbgroup=rs1->getString(1);
                istock=rs1->getString(2);
		squantity=rs1->getString(3);
		sprice=rs1->getString(4);
		spdate=rs1->getString(5);
		sedate=rs1->getString(6);
		ibid=rs1->getString(7);
                CStock cs;
		cs.setBloodGroup(sbgroup);
		cs.setBloodQuantity(squantity);
		cs.setPrice(sprice);
		cs.setDate(spdate);
		cs.setExDate(sedate);
		cs.setBranchID(ibid);
		cs.setBloodStockID(istock);
                blood_records.push_back(cs);
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
       return blood_records;
        }

}
