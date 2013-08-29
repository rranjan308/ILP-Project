#ifndef _LOGIN_H
#define _LOGIN_H
#include<string>
using namespace std;

class CUserlogin
{
        string m_sUsername,m_sPassword,m_sBranchid,m_sBranch,m_sdesignation;

        public:

        CUserlogin();
        CUserlogin(string,string);
        CUserlogin(string,string,string,string,string);

        string getUsername();
        string getPassword();
        string getBranch();
	string getBranchid();
	string getDesignation();        
};
#endif
