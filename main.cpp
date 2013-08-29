#include "mainui.h"
#include "login.h"
#include "maindb.h"
#include "mainui.h"
#include <iostream>
#include"color.h"
using namespace std;
int main()
{
	CMainUI ui;
	CDatabase data;
	try
	{
		
        	int choice;
		system("clear");
		cout<<cyan<<"\n\n\n                                                              ------------------------------------------------------";
        	cout<<"\n                                                                 	    ****WELCOME TO 3S HOSPITAL ****";
        	cout<<"\n                                                               ------------------------------------------------------\n\n"<<white;
        	ui.login(data);
	}
	catch(...)
	{
		cout<<red<<"\nUNKNOWN EXCEPTION"<<white;
    	}
return 0;
}	
