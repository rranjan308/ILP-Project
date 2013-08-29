#ifndef _MAINUI_H
#define _MAINUI_H
#include<string>
#include "login.h"
#include "maindb.h"
using namespace std;

class CMainUI
{
        protected:
		string m_sUsername,m_sPassword;

	public:
		void login(CDatabase &m);
};
#endif
