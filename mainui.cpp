#include "mainui.h"
#include "login.h"
#include "maindb.h"
#include "sepui.h"
#include "patient.h"
#include "patientui.h"
#include "employee.h"
#include "employeeui.h"
#include"color.h"
#include "stockUI.h"
#include "stock.h"
void CMainUI::login(CDatabase &a)
{
string suname,spwd,sbrid;
vector <CUserlogin> records;
do
{
system("clear");
cout<<cyan<<"------------------------------------------------------------------------------------------------\n"<<white;
cout<<cyan<<"------------------------------------------------------------------------------------------------\n"<<white;
cout<<cyan<<"------------------------------------------------------------------------------------------------\n"<<white;
cout<<blink<<"------------------------------------------------------------------------------------------------\n"<<white;
cout<<"                   *******     *****   "<<red<<"      |****   "<<white<<endl
    <<"                   ********   *******  "<<red<<"      |****   "<<white<<endl               
    <<"                         **   **       "<<red<<"      |****  " <<white<<endl
    <<"                         **     **     "<<red<<" _____|****    "<<white<<endl
    <<"                    *******       **   "<<red<<" ****************    "<<white<<endl
    <<"                    *******         ** "<<red<<" ****************    "<<white<<endl
    <<"                         **         ** "<<red<<" ****************   " <<white<<endl
    <<"                         **        **  "<<red<<"       ****    "<<white<<endl
    <<"                   ********   *******  "<<red<<"       ****   "<<white<<endl
    <<"                   *******     *****   "<<red<<"       ****  "<<white<<endl
    <<"                                       "<<red<<"       **** "<<blue<<"copyright@SWASTIK SUPER SPECIALITY HOSPITAL "<<white<<endl; 


cout<<blink<<"-------------------------------------------------------------------------------------------------\n"<<white;
cout<<cyan<<"--------------------------------------------------------------------------------------------------\n"<<white;
cout<<cyan<<"--------------------------------------------------------------------------------------------------\n"<<white;
cout<<cyan<<"--------------------------------------------------------------------------------------------------\n"<<white;
cout<<cyan<<"--------------------------------------------------------------------------------------------------\n"<<white;


cout<<yellow<<"\n\t\t\t\tEnter username: ";
cin>>suname;
spwd=getpass("\n\t\t\t\tEnter Password: ");
cout<<white;
CEmployeeUI eui;
CSepEmployeeUI seui;
CPatientui cui;
CStockUI sui;
records=a.userLogin(suname,spwd);
if(records.size()!=0)
        {

        vector<CUserlogin>::iterator iter;
        for(iter=records.begin();iter!=records.end();iter++)
	{
		if(((*iter).getDesignation())=="Receptionist")
		{
//		cout<<yellow<<"\nReceptionist is looged on"<<white;
	//	CPatientui cui;
                sbrid=(*iter).getBranchid();
		cui.setBrId(sbrid);
		cui.displayMenu();
		}
		if(((*iter).getDesignation())=="Doctor")
                {
		string did=(*iter).getUsername();
  //              cout<<yellow<<"\nDoctor is looged on"<<white;
	//	CPatientui cui;
		cui.setDocId(did);
                cui.displayMenudoctor();
                }
		if(((*iter).getDesignation())=="Chairman")
                {
		string did=(*iter).getUsername();
    //            cout<<yellow<<"\nChairman is looged on"<<white;
	//	CPatientui cui;
		sbrid=(*iter).getBranchid();
		eui.setBrId(sbrid);
		seui.setBrId(sbrid);
                eui.displaymenu();
                }
		
		if(((*iter).getDesignation())=="Pharmacist")
                {
		string did=(*iter).getUsername();
      //          cout<<yellow<<"\nPharmacist is looged on"<<white;
	//	CPatientui cui;
		sbrid=(*iter).getBranchid();
		sui.setBrId(sbrid);
                sui.displayMenu();
                }
              


        }
	}
else
        {
        cout<<red<<"\nInvalid Username or password"<<white;
	cout<<"\n\n";
	getpass("Press Enter to continue to Login Screen");
        }
}while(records.size()==0);
}

