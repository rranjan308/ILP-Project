#include<iostream>
#include<string>
#include "maindb.h"
#include "login.h"
using namespace oracle::occi;
using namespace std;
#define _NO_DATA_FOUND 1403
#define SUCCESS 1
#define FAILURE 0


vector<CUserlogin> CDatabase::userLogin(string uname,string pwd)
{
        string sname,spass,sbranchid,sbranchname,sdesignation;
        vector<CUserlogin> log_records;
         if(0==dbConnect())
                {
                        return log_records;
                }
                else
                {
                        try
                        {
                                Statement *p_stmt=m_pconn->createStatement("select * from login where username=:1 AND password=:2");

                                p_stmt->setString(1,uname);
                                p_stmt->setString(2,pwd);
                                ResultSet *p_rs=p_stmt->executeQuery();
                                while(p_rs->next())
                                {
                                        sname=p_rs->getString(1);
                                        spass=p_rs->getString(2);
                                        sbranchid=p_rs->getString(3);
                                        sbranchname=p_rs->getString(4);
					sdesignation=p_rs->getString(5);
                                        CUserlogin el(sname,spass,sbranchid,sbranchname,sdesignation);
                                        log_records.push_back(el);
                                }

                                p_stmt->closeResultSet(p_rs);
                                m_pconn->terminateStatement(p_stmt);
                        }

                        catch(SQLException e)
                        {
                                cerr<<"Cannot connect: "<<e.what();
                        }
                }
                if(0==dbDisConnect())
                {
                        return log_records;
                }
}


int CDatabase::dbConnect()
{
    try
    {
        m_susername="TRA_T05_05";
        m_spassword="tcstvm";
        m_sdatabase="oraunixdb";

        m_penv=Environment::createEnvironment(Environment::DEFAULT);
        m_pconn=m_penv->createConnection(m_susername,m_spassword,m_sdatabase);

     }

        catch(SQLException se)
        {
        cerr<<"\n Database Connection Problem";
        return FAILURE;
        }
        return SUCCESS;
}

int CDatabase::dbDisConnect()
{
    try
    {
       m_penv->terminateConnection(m_pconn);
  Environment::terminateEnvironment(m_penv);
    }
    catch(SQLException ea)
    {
        cerr << "Can't connect: " << ea.what();
  return FAILURE;
    }
    return SUCCESS;
    }

