#include "login.h"
CUserlogin::CUserlogin()
{
}

CUserlogin::CUserlogin(string uname,string pass)
{
        m_sUsername=uname;
        m_sPassword=pass;
}

CUserlogin::CUserlogin(string uname,string pass,string bid,string branch,string des)
{
        m_sUsername=uname;
        m_sPassword=pass;
        m_sBranchid=bid;
        m_sBranch=branch;
	m_sdesignation=des;
        
}

string CUserlogin::getDesignation()
{
return  m_sdesignation;
}


string CUserlogin::getUsername()
{
        return m_sUsername;
}

string CUserlogin::getPassword()
{
        return m_sPassword;
}

string CUserlogin::getBranch()
{
        return m_sBranch;
}

string CUserlogin::getBranchid()
{
        return m_sBranchid;
}
