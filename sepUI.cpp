#include "sepui.h"
#include<iostream>
#include<string>
#include "maindb.h"
#include "sepdb.h"
#include"color.h"
#include "employeeui.h"
#include<iomanip>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Naznin Malek,Vyankatrao Sawant                          //
//Date				18-08-2013                                              //
//Name				Display Menu                                            //
//Description			It displays the main menu                               //
//Arguments			                                                        //
//Returns			int                                                     //
//Notes				                                                        //
//Change History			                                                //
//////////////////////////////////////////////////////////////////////////////////////////


CSepEmployee semp;
void CSepEmployeeUI::setBrId(string brid)
{
semp.setBranchId(brid);
}

int CSepEmployeeUI::getOption()
{
        
	char ichoice[10];
        cout<<"\n\n\t\tEnter your Choice[1-3] : ";
label:  cin.getline(ichoice,10);
        while(!((strlen(ichoice)==1) && (ichoice[0]>48) && (ichoice[0]<52)))
        {
        cout<<red<<"\n\n\t\tInvalid choice(Choioce should be between 1-3)"<<white<<"\n\n\t\tEnter your choice again: "<<white;
        goto label;
        }
        int ch1=ichoice[0]-48;
        return ch1;

}

void  CSepEmployeeUI::displayString(string str)
{
	cout<<"\n"<<str;
}


//////////////////////////////////////////////////////////////////////////////////////////
//Author			Naznin Malek                                            //
//Date				18-08-2013                                              //
//Name				Archive Separated employee                              //
//Description			It fetches deactivated employees and save them.         //
//Arguments			Database class of SepEmployee                           //
//Returns			void                                                    //
//Notes				                                                        //
//Change History			                                                //
//////////////////////////////////////////////////////////////////////////////////////////

void CSepEmployeeUI::archiveSepEmployee(CSepEmployeeDb &m)
{
 
	char ich1[10];
	int icount,iflag;	
	string branchid;
	branchid=semp.getBranchId();
	vector<CSepEmployee> emp_records;
  	emp_records =m.dbFetchSepEmployee(branchid);
  	if(emp_records.size()!=0)
	{
	do
	{
	cout<<yellow<<"\n\n\t\tDo you really want to add separated employee?(Press y or n) : "<<white;
        cin.getline(ich1,10);
	icount=strlen(ich1);
	if(icount==1)
	{
        if((ich1[0] == 121) || (ich1[0] == 89))
        {
                saveSepEmployee(emp_records,m);
		iflag=1;
        }
        else if((ich1[0] == 110) || (ich1[0] == 78)) 
  	{
		iflag=1;
                cout<<"\n\n\t\tSeparated Employee details not fetched."<<endl<<endl;
		cout<<"\n\n";
		getpass("Press <Enter> to continue");
        }
	}
	else
		{iflag=0;
		cout<<red<<"\n\n\t\tInvalid Choice";
		}

	}while(iflag!=1);
	}
  else	
	{	
     		
		system("clear");

 cout<<yellow<<"\n\t\t     ================================="<<white<<endl;
cout<<magenta<<"\n\t\t         O.P   D E P A R T M E N T    "<<white<<endl;
 cout<<yellow<<"\n\t\t     ================================="<<white<<endl;
		displayString("\n\n\t\t Deactivated employee not found");
		cout<<"\n\n\n";
		getpass("\n\n\t\tPress <Enter> to continue");
	}
}

void CSepEmployeeUI::displaySepEmployee(vector<CSepEmployee> emp_records)
{
    system("clear");
    vector<CSepEmployee>::iterator sepIter;
   /* cout<<cyan<<"\n\n\n                                                         	------------------------------------------------------";
    cout<<"\n							 	    ***********Separated Employee Details **********"<<endl;
    cout<<"                                                                ------------------------------------------------------";*/
 cout<<yellow<<"\n\t\t     ======================================="<<white<<endl;
cout<<magenta<<"\n\t\t            O.P   D E P A R T M E N T       "<<white<<endl;
 cout<<yellow<<"\n\t\t     ======================================="<<white<<endl;
cout<<magenta<<"\n\t\t      S E P A R A T E D   E M P L O Y E E S "<<white<<endl;
 cout<<yellow<<"\n\t\t     ======================================="<<white<<endl;

cout<<dcyan<<"\n\t"<<"___________________________________________________________________"<<white<<endl;
        cout<<magenta<<"\n\n\tEMPLOYEE ID\t\tBRANCH ID    \t\tNAME";
cout<<dcyan<<"\n\t"<<"___________________________________________________________________"<<white<<endl;

  /*  cout<<cyan<<"\n\n"<<"                           -----------------------------------------------------------------------------------------------------------------";	
    cout<<"\n\n"<<setw(40)<<"Employee id"<<"\t\t"<<"First Name"<<"\t\t"<<"Last Name"<<"\t\t"<<"Phone Number"<<"\t\t"<<"Branch id";
    cout<<cyan<<"\n\n"<<"                           -----------------------------------------------------------------------------------------------------------------";*/
    for (sepIter = emp_records.begin(); sepIter != emp_records.end(); sepIter++)    {
cout<<"\n\n\t"<<(*sepIter).getEmpId()<<"\t\t\t"<<(*sepIter).getBranchId()<<"\t\t\t"<<(*sepIter).getEmpFName()<<" "<<(*sepIter).getEmpLName();
}
cout<<"\n\n";
getpass("\n\n\t\tPress <Enter> to continue");
CEmployeeUI eui;
eui.displaymenu3();
}


void CSepEmployeeUI::displaySepEmployeebyId(vector<CSepEmployee> emp_records)
{system("clear");
CEmployeeUI eui;
vector<CSepEmployee>::iterator sepIter;
   /* cout<<cyan<<"\n\n\n                                                                ------------------------------------------------------";
    cout<<"\n                                                                   ***********Separated Employee Details **********"<<endl;
    cout<<"                                                                ------------------------------------------------------";*/

 cout<<yellow<<"\n\t\t     ======================================="<<white<<endl;
cout<<magenta<<"\n\t\t            O.P   D E P A R T M E N T       "<<white<<endl;
 cout<<yellow<<"\n\t\t     ======================================="<<white<<endl;
cout<<magenta<<"\n\t\t      S E P A R A T E D   E M P L O Y E E S "<<white<<endl;
 cout<<yellow<<"\n\t\t     ======================================="<<white<<endl;

    for (sepIter = emp_records.begin(); sepIter != emp_records.end(); sepIter++)   /* {

cout<<yellow<<"\n\n"<<setw(90)<<"First Name\t: "<<(*sepIter).getEmpFName()<<"\n\n"<<setw(90)<<"Middle Name\t: "<<(*sepIter).getEmpMName()<<"\n\n"<<setw(90)<<"Last Name\t: "<<(*sepIter).getEmpLName()<<"\n\n"<<setw(90)<<"Gender\t: "<<(*sepIter).getGender()<<"\n\n"<<setw(90)<<"Date Of Birth\t: "<<(*sepIter).getDob()<<"\n\n"<<setw(90)<<"Phone Number\t: "<<(*sepIter).getPhNumber()<<"\n\n"<<setw(90)<<"Address1\t: "<<(*sepIter).getAddr1()<<"\n\n"<<setw(90)<<"Address2\t: "<<(*sepIter).getAddr2()<<"\n\n"<<setw(90)<<"Pin Code\t: "<<(*sepIter).getIpin()<<"\n\n"<<setw(90)<<"Branch Id\t: "<<(*sepIter).getBranchId()<<white;
}*/

{
cout<<dcyan<<"\n\t\t"<<"_____________________________________"<<white<<endl;
        cout<<magenta<<"\n\n\t\t"<<"Employee ID            : "<<(*sepIter).getEmpId()<<white<<endl;
cout<<dcyan<<"\n\t\t"<<"_____________________________________"<<white<<endl;

cout<<cyan<<"\n\t\t"<<"Name                 "<<white<<"  : "<<(*sepIter).getEmpFName()<<" "<<(*sepIter).getEmpMName()<<" "<<(*sepIter).getEmpLName()<<endl;
        cout<<cyan<<"\n\t\t"<<"Gender               "<<white<<"  : "<<(*sepIter).getGender()<<endl;
        cout<<cyan<<"\n\t\t"<<"Date of birth        "<<white<<"  : "<<(*sepIter).getDob()<<endl;
        cout<<cyan<<"\n\t\t"<<"Address              "<<white<<"  : "<<(*sepIter).getAddr1()<<","<<(*sepIter).getAddr2()<<endl;
        cout<<cyan<<"\n\t\t"<<"Pin                  "<<white<<"  : "<<(*sepIter).getIpin()<<endl;
        cout<<cyan<<"\n\t\t"<<"Phone Number         "<<white<<"  : "<<(*sepIter).getPhNumber()<<endl;
        cout<<cyan<<"\n\t\t"<<"Branch ID            "<<white<<"  : "<<(*sepIter).getBranchId()<<endl;
     //   cout<<cyan<<"\n\t\t"<<"Status               "<<white<<"  : "<<emp_record.getStatus()<<endl;

}
cout<<"\n\n";
getpass("\n\t\tPress <Enter> to continue");
eui.displaymenu3();

}



void CSepEmployeeUI::saveSepEmployee(vector<CSepEmployee> emp_records,CSepEmployeeDb &m)
{	
	int icount=0;	
	vector<CSepEmployee>::iterator sepIter;
	CSepEmployee sep;
	 for (sepIter = emp_records.begin(); sepIter != emp_records.end(); sepIter++)
	{
	sep.setEmpId((*sepIter).getEmpId());
	sep.setEmpFName((*sepIter).getEmpFName());
	sep.setEmpMName((*sepIter).getEmpMName());
	sep.setEmpLName((*sepIter).getEmpLName());
	sep.setGender((*sepIter).getGender());
	sep.setDob((*sepIter).getDob());
	sep.setAddr1((*sepIter).getAddr1());
	sep.setAddr1((*sepIter).getAddr2());
	sep.setIpin((*sepIter).getIpin());
	sep.setPhNumber((*sepIter).getPhNumber());
	sep.setBranchId((*sepIter).getBranchId());
	
	if(m.dbSaveSepEmployee(sep)==1)
		icount++;
		
	else
                {
                cout<<red<<"\n\n\t\tCan't save"<<white;
                }


	}
	if(icount>0)
		cout<<green<<"\n\n\t\tEmployee saved successfully"<<white;

	cout<<"\n\n";
	getpass("\n\t\tPress <Enter> to continue");
}


//////////////////////////////////////////////////////////////////////////////////////////
//Author			Naznin Malek                                            //
//Date				18-08-2013                                              //
//Name				View Separated employee                                 //
//Description			It displays all information of separated employees      //
//				from database                                           //
//Arguments			Database class of SepEmployee                           //
//Returns			void                                                    //
//Notes				                                                        //
//Change History			                                                //
//////////////////////////////////////////////////////////////////////////////////////////

void CSepEmployeeUI::viewSepEmployee(CSepEmployeeDb &m)
{string sbrid;
sbrid=semp.getBranchId();
  vector<CSepEmployee> sepemp_records;
  sepemp_records =m.dbSelectSepEmployee(sbrid);
  if(sepemp_records.size()!=0)
     displaySepEmployee(sepemp_records);
  else
     cout<<red<<"\n\n\t\tRecord not Found"<<white;

}

void CSepEmployeeUI::viewSepEmployeebyId(CSepEmployeeDb &m)
{
  /*cout<<cyan<<"\n\n\n                                                                ------------------------------------------------------";
  cout<<"\n                                                                   ***********Separated Employee Details **********"<<endl;
  cout<<"                                                                ------------------------------------------------------"<<white;*/
system("clear");
 cout<<yellow<<"\n\t\t     ======================================="<<white<<endl;
cout<<magenta<<"\n\t\t            O.P   D E P A R T M E N T       "<<white<<endl;
 cout<<yellow<<"\n\t\t     ======================================="<<white<<endl;
cout<<magenta<<"\n\t\t      S E P A R A T E D   E M P L O Y E E S "<<white<<endl;
 cout<<yellow<<"\n\t\t     ======================================="<<white<<endl;


  string sempid,sbrid;
 sbrid=semp.getBranchId();
  int iflag;
vector<CSepEmployee> sepemp_records;
do
{
  cout<<"\n\n\t\tEnter Employee ID (eg. EMPxxx): ";
	do
	{
	iflag=1;
 	cin>>sempid;
	if((sempid[0]!=69) || (sempid[1]!=77) || (sempid[2]!=80))
		{
		iflag=0;
		}
	if(iflag==0)
	{
		cout<<red<<"\n\n\t\tInvalid ID"<<white;
		cout<<"\n\n\t\tEnter Employee ID : ";
	}
	}while(iflag!=1);


  sepemp_records =m.dbSelectSepEmployeebyId(sempid,sbrid);
  if(sepemp_records.size()!=0)
     displaySepEmployeebyId(sepemp_records);
  else
     cout<<red<<"\n\n\t\tEmployeeID not found"<<white;
}while(sepemp_records.size()==0);

}

