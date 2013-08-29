//////////////////////////////////////////////////////////////////////////////////////////
//File Description		<User Interface for Employee Management>                //
//Contents			<Add,View,Update and Deactivate employee details>       //
//Author		        <Rahul Ranjan, Nena Jose>                               //
//Date				<18-08-2013>                                            //
//Change History		<Rahul Ranjan,Nena Jose		20-08-2013>             //
//////////////////////////////////////////////////////////////////////////////////////////
#include "employeeui.h"
#include "employeedb.h"
#include<iostream>
#include <string>
#include <sstream>
#include <time.h>
#include "color.h"
#include "sepui.h"
#include "mainui.h"
#include "maindb.h"
#include "sepdb.h"
using namespace std;
CEmployee emp;

void CEmployeeUI::setBrId(string bid)
{
emp.setBranchid(bid); 

}



				
void CEmployeeUI::displaymenu2()
{cin.ignore(255,'\n');
CEmployeeDB cdb;
char ch2[5];
system("clear");
   cout<<yellow<<"\n\t\t           ==============================================="<<white<<endl;
  cout<<magenta<<"\n\t\t                      O.P   D E P A R T M E N T           "<<white<<endl;
   cout<<yellow<<"\n\t\t           ==============================================="<<white<<endl;
  cout<<magenta<<"\n\t\t           D I S P L A Y   E M P L O Y E E   D E T A I L S"<<white<<endl;
   cout<<yellow<<"\n\t\t           ==============================================="<<white<<endl;
cout<<"\n\t\t";
cout<<"\n\n\t\t1. Display all employee details";
cout<<"\n\n\t\t2. Display employee details by employee ID";
cout<<"\n\n\t\t3. Go back to previous menu";
label7:cout<<"\n\n\t\tEnter your choice : ";
cin.getline(ch2,5);
int count=strlen(ch2);
  while( !( count==1 && ch2[0]>=48 && ch2[0]<52) )
  {  cout<<dred<<"\n\n\t\tPlease enter a valid number \n "<<white;

   goto label7;
  }
int choice=ch2[0]-48;
switch(choice)
{
case 1: {retrieveEmpRecords(cdb);
        break;}
case 2: {retrieveEmpRecords1(cdb);
        break;}
case 3: {
        break;}
deafult:{cout<<"Enter a valid option \n";
        break;}
}
}

void CEmployeeUI::displaymenu3()
{
system("clear");
CSepEmployeeUI seui;
CSepEmployeeDb data;

		//	  cout<<dcyan<<"\n\t\t\t    ----------------------------------"<<white<<endl;
		//	  cout<<dyellow<<"\n\t\t\t          Out Patient Department      "<<white<<endl;
		//	cout<<dcyan<<"\n\t\t\t    ----------------------------------"<<white<<endl;
		//	cout<<dyellow<<"\n\t\t\t    Display Separated Employee Details"<<white<<endl;
		//	cout<<dcyan<<"\n\t\t\t    ----------------------------------"<<white<<endl;
			  cout<<yellow<<"\n\t\t          ====================================================="<<white<<endl;
  		        cout<<magenta<<"\n\t\t                        O.P   D E P A R T M E N T              "<<white<<endl;
                      cout<<yellow<<"\n\t\t          ====================================================="<<white<<endl;
                     cout<<magenta<<"\n\t\t          D I S P L A Y   S E P A R A T E D   E M P L O Y E E S"<<white<<endl;
                      cout<<yellow<<"\n\t\t          ====================================================="<<white<<endl;		






			cout<<"\n\t\t";
		  	cout<<"\n\n\t\t1.View all Seperated Employee";
   			cout<<"\n\n\t\t2.View Seperated Employee by EmployeeId";
  			cout<<"\n\n\t\t3.Go back to main menu ";
				  int ichoice=seui.getOption();
				 switch(ichoice)
					{
					case 1:seui.viewSepEmployee(data);
					break;
					case 2:seui.viewSepEmployeebyId(data);
					break;
					case 3:
					     	break;
					}
}	

void CEmployeeUI::displaymenu()
{cin.ignore(255,'\n');
 	system("clear");
	cout<<yellow<<"\n\t\t===================================================================\n"<<white;
       cout<<magenta<<"\t\t          S W A S T I K   S U P E R   S P E C I A L I T Y          \n"<<white; 
        cout<<yellow<<"\t\t===================================================================\n"<<white;
          cout<<cyan<<"\t\t||                                                               ||"<<endl
                    <<"\t\t||                         WELCOME TO                            ||"<<endl
	            <<"\t\t||							         ||"<<endl
	            <<"\t\t||                   OUT PATIENT DEPARTMENT                      || \n"
	            <<"\t\t||							         || \n"
	            <<"\t\t||                    EMPLOYEE MANAGEMENT                        || \n"
	            <<"\t\t||							         || \n"<<white;
	cout<<yellow<<"\t\t===================================================================\n\n";
                
		cout<<"\t\t===================================================================\n\n"<<white;
	cout<<"\t\t1.Add New Employee Details."<<endl<<endl;
	cout<<"\t\t2.Update Employee Details."<<endl<<endl;
	cout<<"\t\t3.Deactivate Employee Details."<<endl<<endl;
	cout<<"\t\t4.Display Employee Details."<<endl<<endl;
        cout<<"\t\t5.Archive Separated Employee."<<endl<<endl;
        cout<<"\t\t6.View Seperated Employee"<<endl<<endl;
   	cout<<"\t\t7.Logout"<<endl<<endl;
	cout<<"\t\t8.Exit the System."<<endl<<endl;
CEmployeeDB cdb;
CDatabase mdb;
CMainUI mui;
CSepEmployeeUI seui;
CSepEmployeeDb data;
int choice,ichoice;
        do{
        choice=getOption();
            switch(choice)
            {
	    case 1:addEmpDetails(cdb);
		   break;
	    case 4:displaymenu2();
		   break;
	    case 2:updateEmpDetails(cdb);
		   break;
	    case 3:deleteEmpDetails(cdb);
		   break;
	    case 5:seui.archiveSepEmployee(data);
		   break;
	    case 6: {displaymenu3();
				}break;  
	case 7:{mui.login(mdb);  
		break;}  
	case 8:exit(0);
	    default:displayString("Enter a valid option\n");
	    }
	displaymenu();
	}while (choice!=7);

}


int CEmployeeUI::getOption()
{   
  
   label:    cout<<"\n\t\tEnter your option(1-8) : ";
             cin.getline(m_ch,10);
	     int count=strlen(m_ch);

      while( !( count==1 && m_ch[0]>=48 && m_ch[0]<57) )
       {  
	cout<<dred<<"\n\t\tPlease enter a number between 1 to 8.\n "<<white;
	goto label;
       }
	int choice=m_ch[0]-48;
        return choice;
}
void CEmployeeUI::displayString(char* str)
{
     cout<<str<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////
//Author                               <Nena Jose>                                      //
//Date                                 <16-08-2013>                                     //
//Name                                 <View Employee Details>                          //
//Description                          <Displays all Employee Details>                  //
//Arguments                            <Vector of Employee class>                       //
//Returns                              <No return>                                      //
//Notes                                <Comments>                                       //
//Change History                       <Nena Jose	20-08-2013>                     //
//////////////////////////////////////////////////////////////////////////////////////////


void CEmployeeUI::display(vector<CEmployee> emp_records)
{
system("clear");
    vector<CEmployee>::iterator empIter;
      //cout<<dcyan<<"\n\t\t\t    ----------------------"<<white<<endl;
  //    cout<<dyellow<<"\n\t\t\t    Out Patient Department  "<<white<<endl;
   // cout<<dcyan<<"\n\t\t\t    ----------------------"<<white<<endl;
   // cout<<dyellow<<"\n\t\t\t       Employee Details    "<<white<<endl;
   // cout<<dcyan<<"\n\t\t\t    ----------------------"<<white<<endl;
//cout<<"\n\t\t------------------------------------------"<<endl;
 //   for (empIter = emp_records.begin(); empIter != emp_records.end(); empIter++)
  // {

   cout<<yellow<<"\n\t\t           ================================="<<white<<endl;
  cout<<magenta<<"\n\t\t               O.P   D E P A R T M E N T    "<<white<<endl;
   cout<<yellow<<"\n\t\t           ================================="<<white<<endl;
  cout<<magenta<<"\n\t\t            E M P L O Y E E   D E T A I L S "<<white<<endl;
   cout<<yellow<<"\n\t\t           ================================="<<white<<endl;


cout<<dcyan<<"\n\t"<<"___________________________________________________________________"<<white<<endl;
        cout<<magenta<<"\n\n\tEMPLOYEE ID\t\tBRANCH ID    \t\tNAME";
cout<<dcyan<<"\n\t"<<"___________________________________________________________________"<<white<<endl;
for (empIter = emp_records.begin(); empIter != emp_records.end(); empIter++)
{
        cout<<"\n\n\t"<<(*empIter).getEmpid()<<"\t\t\t"<<(*empIter).getBranchid()<<"\t\t\t"<<(*empIter).getEmpfname()<<" "<<(*empIter).getEmpmname()<<" "<<(*empIter).getEmplname();
//      cout<<cyan<<"\n\t\t\t\t"<<"Gender               "<<white<<"  : "<<(*empIter).getGender()<<endl;
//      cout<<cyan<<"\n\t\t\t\t"<<"Date of birth        "<<white<<"  : "<<(*empIter).getDob()<<endl;
        //cout<<cyan<<"\n\t\t\t\t"<<"Address              "<<white<<"  : "<<(*empIter).getAddr1()<<","<<(*empIter).getAddr2()<<endl;
        //cout<<cyan<<"\n\t\t\t\t"<<"Pin                  "<<white<<"  : "<<(*empIter).getPin()<<endl;
        //cout<<cyan<<"\n\t\t\t\t"<<"Phone Number         "<<white<<"  : "<<(*empIter).getPhoneno()<<endl;
        //cout<<cyan<<"\n\t\t\t\t"<<"Branch ID            "<<white<<"  : "<<(*empIter).getBranchid()<<endl;
      //  cout<<cyan<<"\n\t\t\t\t"<<"Status               "<<white<<"  : "<<(*empIter).getStatus()<<endl;
   }
cout<<"\n\n\n\n";
getpass("\n\t\tPress <Enter> to go to Previous menu");
displaymenu2();
}
void CEmployeeUI::retrieveEmpRecords1(CEmployeeDB &m)
{
system("clear");
 cout<<yellow<<"\n\t\t           ================================="<<white<<endl;
cout<<magenta<<"\n\t\t               O.P   D E P A R T M E N T    "<<white<<endl;
 cout<<yellow<<"\n\t\t           ================================="<<white<<endl;
cout<<magenta<<"\n\t\t            E M P L O Y E E   D E T A I L S "<<white<<endl;
 cout<<yellow<<"\n\t\t           ================================="<<white<<endl;

string empid;
cout<<"\n\n\n\t\tEnter employee id (eg.EMPxxx): ";
cin>>empid;
string branchid=emp.getBranchid();
if(m.findEmpNo(empid,branchid)==1)
{
//string branchid=emp.getBranchid();
CEmployee emp_record;
emp_record=m.dbSelect1(branchid,empid);
if(sizeof(emp_record)!=0)
{
cout<<dcyan<<"\n\t\t"<<"_____________________________________"<<white<<endl;
        cout<<magenta<<"\n\n\t\t"<<"Employee ID            : "<<emp_record.getEmpid()<<white<<endl;
cout<<dcyan<<"\n\t\t"<<"_____________________________________"<<white<<endl;
        cout<<cyan<<"\n\t\t"<<"Name                 "<<white<<"  : "<<emp_record.getEmpfname()<<" "<<emp_record.getEmpmname()<<" "<<emp_record.getEmplname()<<endl;
        cout<<cyan<<"\n\t\t"<<"Gender               "<<white<<"  : "<<emp_record.getGender()<<endl;
        cout<<cyan<<"\n\t\t"<<"Date of birth        "<<white<<"  : "<<emp_record.getDob()<<endl;
        cout<<cyan<<"\n\t\t"<<"Address              "<<white<<"  : "<<emp_record.getAddr1()<<","<<emp_record.getAddr2()<<endl;
        cout<<cyan<<"\n\t\t"<<"Pin                  "<<white<<"  : "<<emp_record.getPin()<<endl;
        cout<<cyan<<"\n\t\t"<<"Phone Number         "<<white<<"  : "<<emp_record.getPhoneno()<<endl;
        cout<<cyan<<"\n\t\t"<<"Branch ID            "<<white<<"  : "<<emp_record.getBranchid()<<endl;
        cout<<cyan<<"\n\t\t"<<"Status               "<<white<<"  : "<<emp_record.getStatus()<<endl;

}
else
{
cout<<red;
displayString("\n\t\tRecord not Found.\n\n");
cout<<white;
}

}
else
{
cout<<red<<"\n\t\tEmployee ID does not exist \n"<<white<<endl;
}
getpass("\n\t\tPress <Enter> to go to Previous menu");
displaymenu2();
}


string CEmployeeUI::getDate()
{ 
	string date;
	time_t now=time(0);
	tm *ltm=localtime(&now);
	int cur_yr,cur_month,cur_day;
	cur_yr=1900+ltm->tm_year;
	//cur_month=1+ltm->tm_mon;
	//cur_day=ltm->tm_mday;
	ostringstream out;
	int year, month, day;
	char dash1, dash2;
	label:cout<<"\n\n\t\tDate of Birth* (dd-mm-yyyy)  : " << flush;
	while(!(cin>>day>>dash1>>month>>dash2>>year))
	{
	 cout<<dred<<"\n\n\t\tEnter a valid date "<<white;
	 cout<<"\n\n\t\t";
         cin.clear();
        cin.ignore(255,'\n');
        }
	if((cur_yr-year)>18 && (cur_yr-year)<60)
	{
	switch(month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: {if(day>=1 && day<=31)
							{if(dash1=='-' && dash2=='-')
                                                        {out<<day<<dash1<<month<<dash2<<year;
                                                         date=out.str();}
	else {cout<<"\n\n\t\t"<<dred<<"Enter date in the given format"<<white;goto label;}}
	else {cout<<"\n\n\t\t"<<dred<<"Enter a valid date"<<white;goto label;}

                                                      return date;
                                                        break;}
	case 2: {
		  if(day>=1 && day<=28)
	        	{
			if(dash1=='-' && dash2=='-')
       	       		 {
				out<<day<<dash1<<month<<dash2<<year;
       				 date=out.str();
			 }
	 		else 
			{
			cout<<"\n\n\t\t"<<dred<<"Enter date in the given format"<<white;
			goto label;
			}
			}
			else 
			{
			  cout<<"\n\n\t\t"<<dred<<"Enter a valid date"<<white;
			  goto label;
			}

		      return date;
       			 break;
		}
	case 4: case 6: case 9: case 11: {
					  if(day>=1 && day<=30)
					   {
						if(dash1=='-' && dash2=='-')
                                		{
						out<<day<<dash1<<month<<dash2<<year;
                               			  date=out.str();
						}

						else 
						{
						cout<<"\n\n\t\t"<<dred<<"Enter date in the given format"<<white;
						goto label;
						}
					   }
					 else 
					   {
						cout<<"\n\n\t\t"<<dred<<"Enter a valid date"<<white;
						goto label;
					   }

		                      return date;
                	                 break;
					  }
	default:cout<<dred<<"\n\n\t\tEnter a valid date"<<white<<endl;
        	goto label;
		}
	}
	else
	{
	 cout<<dred<<"\n\t\tEnter a valid date"<<white<<endl;
	 goto label;
	}
}


void CEmployeeUI::retrieveEmpRecords(CEmployeeDB &m)
{
 	string branchid=emp.getBranchid();
        vector<CEmployee> emp_records;
        emp_records =m.dbSelect(branchid);
       if(emp_records.size()!=0)
	    display(emp_records);
       else
	{
	cout<<red;     
	displayString("\n\t\tRecord not Found.\n\n");
	cout<<white;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Author                               <Nena Jose>                                                                       // 
//Date                                 <16-08-2013>                                                                      //
//Name                                 <Add Employee Details>                                                            //
//Description                          <Adds a new employee's details into database and generates a unique Employee ID>  //
//Arguments                            <Object of CEmployeeDB class>                                                     //
//Returns                              <No return>                                                                       //
//Notes                                <Comments>                                                                        //
//Change History                       <Nena Jose	20-08-2013>                                                      //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CEmployeeUI::addEmpDetails(CEmployeeDB &m)
{
	system("clear");
  //cout<<dcyan<<"\n\t\t\t    ----------------------"<<white<<endl;
  //cout<<dyellow<<"\n\t\t\t    Out Patient Department"<<white<<endl;
//cout<<dcyan<<"\n\t\t\t    ----------------------"<<white<<endl;
//cout<<dyellow<<"\n\t\t\t     Add Employee Details"<<white<<endl;
//cout<<dcyan<<"\n\t\t\t    ----------------------"<<white<<endl;
   cout<<yellow<<"\n\t\t           ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t                   O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t           ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t            A D D   E M P L O Y E E   D E T A I L S "<<white<<endl;
   cout<<yellow<<"\n\t\t           ========================================="<<white<<endl;

	string id;
	string fname;
	char mname[20];
	string lname;
	char gen[5];
	string dob;
	string addr1;
	string addr2;
	string pin;
	string phone;
	int status=1;
	string branchid;
cout<<yellow<<"\n\n\n\tStarred field are mandatory"<<white;
while(1)
     {

cout<<"\n\n\t\tFirst Name"<<yellow<<"*"<<white<<"                  : ";
      int flag=1;
       cin>>fname;
           for(int i=0;fname[i]!='\0';i++)
                              {
                             if((fname[i]>=65 &&fname[i]<=90)||(fname[i]>=97 && fname[i]<=122))
                                { flag==1;  }
                                else
                                {
                             
                                cout<<dred<<"\n\t\tName cannot contain numbers or special characters.Please enter again\n"<<white;
			        flag=0;
                                break;
                                }
                                }
                                if(flag==1)
                               { break; }
       }
while(1)
     {
cout<<"\n\n\t\tMiddle Name                  : ";
      int flag=1;
	cin.clear();
	cin.ignore(255,'\n');
       cin.getline(mname,20);
           for(int i=0;mname[i]!='\0';i++)
                              {
                             if((mname[i]>=65 &&mname[i]<=90)||(mname[i]>=97 && mname[i]<=122))
                                { flag==1;  }
                                else
                                {
                         
                                cout<<dred<<"\n\t\tName cannot contain numbers or special characters.Please enter again\n"<<white;
	                        flag=0;
                                break;
                                }
                                }
                                if(flag==1)
                               { break; }
       }

while(1)
     {
cout<<"\n\n\t\tLast Name"<<yellow<<"*"<<white<<"                   : ";
      int flag=1;
       cin>>lname;
           for(int i=0;lname[i]!='\0';i++)
                              {
                             if((lname[i]>=65 &&lname[i]<=90)||(lname[i]>=97 && lname[i]<=122))
                                { flag==1;  }
                                else
                                {
                                cout<<dred<<"\n\t\tName cannot contain numbers or special characters.Please enter again\n"<<white;
                                flag=0;
                                break;
                                }
                                }
                                if(flag==1)
                               { break; }
     }
int flag;
do
 {
	cout<<"\n\n\t\tGender(M/F)"<<yellow<<"*"<<white<<"                 : ";
	cin>>gen;
	cin.ignore(80,'\n');
	int cnt1=strlen(gen);
	flag=0;
	if(cnt1==1){
	if (gen[0] == 109 || gen[0] == 77 )
	{
	gen[0]='M';

	}

	else if (gen[0] == 70 || gen[0] == 102)
	{
	gen[0]='F';
	}

	else
	{
	cout<<dred<<"\n\t\tPlease enter M/m or F/f\n"<<white;
	flag=1;
	}
	}
	else { cout<<dred<<"\n\t\tPlease enter in valid format"<<white;flag=1;}
	}while(flag==1);

	dob=getDate();

	cout<<"\n\n\t\tAddress"<<yellow<<"*"<<white<<"                     : ";
	cin>>addr1>>addr2;

	label3:cout<<"\n\n\t\tPin Code"<<yellow<<"*"<<white<<"                    : ";
		cin>>pin;
		int count3=0;
	for(int j=0;pin[j]!='\0';j++)
	{
	count3++;
	}
	if(count3==6)
	{
	for(int i=0;i<count3;i++)
	{
	   while( !( pin[i]>=48 && pin[i]<=57) )
	  { 
		 cout<<dred"\n\t\tPin number should contain only digits.Please enter again\n"<<white;
		   goto label3;
  	  }
	}
    }
	else
	{
	cout<<dred"\n\t\tPin number should contain 6 digits.Please enter again\n"<<white;
	goto label3;
  }
	label4:cout<<"\n\n\t\tMobile number"<<yellow<<"*"<<white<<"               : ";
cin>>phone;
int count4=0;
for(int j=0;phone[j]!='\0';j++)
{
count4++;
}

if(count4==10)
{
for(int j=0;j<count4;j++)
{
   while( !( phone[j]>=48 && phone[j]<=57) )
  {  cout<<dred<<"\n\t\tPhone number should contain only digits.Please enter again"<<white;
   goto label4;
  }}
}
else
{
cout<<dred<<"\n\t\tPhone number should contain 10 digits.Please enter again"<<white;
goto label4;
}

emp.setEmpfname(fname);
emp.setEmpmname(mname);
emp.setEmplname(lname);
emp.setGender(gen);
emp.setDob(dob);
emp.setAddr1(addr1);
emp.setAddr2(addr2);
emp.setPin(pin);
emp.setPhoneno(phone);
branchid=emp.getBranchid();

emp.setBranchid(branchid);
emp.setStatus(status);
id=m.genEmployeeID();
emp.setEmpid(id);
char c;
cout<<yellow<<"\n\t\tDo you want to add the details? (Y/N) : "<<white;
cin>>c;

if(c=='Y' || c=='y')
{
if( m.dbInsert(emp)==1)
        {
		system("clear");
		//cout<<"\n\n\n\n\n\n\n";
   cout<<yellow<<"\n\t\t       ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t               O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t       ========================================="<<white<<endl;
		cout<<dgreen<<"\n\n\n"; 
 		 displayString("\t\tEmployee details added successfully");
		           //cout<<"\t\t\t-----------------------------------\n";
		 cout<<white;
		cout<<"\n\n\n\t\tEmployee ID is : "<<yellow<<id<<white<<"\n\n";
		getpass("\n\t\tPress <Enter> to go to Main menu");
			}
      else if( m.dbInsert(emp)==0)
       {cout<<dred; displayString("\n\t\tConnection error."); cout<<white;}
      else if( m.dbInsert(emp)==-2)
       {cout<<dred; displayString("\n\t\tEmployee not added."); cout<<white;}
}
else if( c=='N' || c=='n')
		{cout<<"\n\n\t\tDetails not added";cout<<"\n\n"; getpass("\n\n\t\tPress <Enter> to go to Main menu");
		}


}

////////////////////////////////////////////////////////////////////////////////////////////////
//Author                               <Rahul Ranjan>                                         //
//Date                                 <16-08-2013>                                           //
//Name                                 <Update Employee Details>                              //
//Description                          <Update the required fields of a perticular employee>  //
//Arguments                            <Object of Employee database class>                    //
//Returns                              <No return>                                            //
//Notes                                <Comments>                                             //
//Change History                        <Rahul Ranjan     20-08-2013  >                       //
////////////////////////////////////////////////////////////////////////////////////////////////

void CEmployeeUI::updateEmpDetails(CEmployeeDB &m)
{
	system("clear");
	 // cout<<dcyan<<"\n\t\t\t    ------------------------"<<white<<endl;
	//  cout<<dyellow<<"\n\t\t\t     Out Patient Department "<<white<<endl;
//	cout<<dcyan<<"\n\t\t\t    ------------------------"<<white<<endl;
//	cout<<dyellow<<"\n\t\t\t    Update Employee Details "<<white<<endl;
	//cout<<dcyan<<"\n\t\t\t    ------------------------"<<white<<endl;
	
   cout<<yellow<<"\n\t\t            ==============================================="<<white<<endl;
  cout<<magenta<<"\n\t\t                       O.P   D E P A R T M E N T           "<<white<<endl;
   cout<<yellow<<"\n\t\t            ==============================================="<<white<<endl;
  cout<<magenta<<"\n\t\t              U P D A T E   E M P L O Y E E   D E T A I L S"<<white<<endl;
   cout<<yellow<<"\n\t\t            ==============================================="<<white<<endl;


	string empid;
	label2:cout<<"\n\n\t\tEnter employee id (eg.EMPxxx): ";
	cin>>empid;
	string brid=emp.getBranchid();
	if(m.findEmpNo(empid,brid)==1)
	{
	cout<<yellow<<"\n\n\t\t1.Update Address   2.Update Pin   3.Update Phone Number\n"<<white;
	label:cout<<"\n\n\t\tEnter your choice(1-3) : ";
	cin.getline(m_ch1,10);
	int count1=strlen(m_ch1);
	
	
	   while( !(count1==1 && m_ch1[0]>=48 && m_ch1[0]<53) )
	  {  cout<<dred<<"\n\t\tPlease enter a number between 1 to 3. \n "<<white;
	   goto label;
          }
	
	int choice1=m_ch1[0]-48;
	switch (choice1)
	{
	case 1:{
		string adr1;
		string adr2;
		if(empid!="-1")
		   {
		    cin.ignore();
	      cout<<"\n\t\tEnter address : ";
	      cin>>adr1>>adr2;
		char c1;
		cout<<yellow<<"\n\t\tDo you want to update the details? (Y/N) : "<<white;
		cin>>c1;
		if(c1=='Y' || c1=='y')
		{
//	string branchid=emp.getBranchid();
		      if (m.dbUpdate1(empid,adr1,adr2)==1)
		       {
			system("clear");
			    cout<<yellow<<"\n\t\t       ========================================="<<white<<endl;
                       cout<<magenta<<"\n\t\t               O.P   D E P A R T M E N T        "<<white<<endl;
                        cout<<yellow<<"\n\t\t       ========================================="<<white<<endl;		

			  
			           cout<<dgreen<<"\n\n\n\t\tEmployee details updated successfully"<<white; 
			                   //   cout<<"\t\t\t-------------------------------------\n";
			cout<<"\n\n";
			getpass("\n\n\t\tPress <Enter> to go to Main menu");}
		      else
		      if (m.dbUpdate1(empid,adr1,adr2)==0)
		       {
			cout<<dred<<"\n\t\tConnection Error"<<white;cout<<"\n\n"; getpass("\n\n\t\tPress <Enter> to go to Main menu");}
		      else
		      if (m.dbUpdate1(empid,adr1,adr2)==-2)
		       {
			cout<<dred<<"\n\t\tNo record found"<<white;cout<<"\n\n";
			getpass("\n\n\t\tPress <Enter> to go to Main menu");}
		   else
			   {
			 cout<<dred<<"\n\t\tEmployee with given Employee ID Does not exist"<<white;}
			  }
			}
		break;
	}
	case 2:{
		string pin;
		if(empid!="-1")
		   {
		    cin.ignore();
		     label5: cout<<"\n\t\tEnter Pin : ";
		      cin>>pin;
		int count5=0;
        for(int j=0;pin[j]!='\0';j++)
        {
        count5++;
        }
        if(count5==6)
        {
        for(int i=0;i<count5;i++)
        {
           while( !( pin[i]>=48 && pin[i]<=57) )
          {
                 cout<<dred"\n\t\tPin number should contain only digits.Please enter again\n"<<white;
                   goto label5;
          }
        }
    }
        else
        {
        cout<<dred"\n\t\tPin number should contain 6 digits.Please enter again\n"<<white;
        goto label5;
  }

		     char c2;
		     cout<<yellow<<"\n\t\tDo you want to update the details? (Y/N) : "<<white;
			cin>>c2;
			if(c2=='Y' || c2=='y')
		       {
			      if (m.dbUpdate3(empid,pin)==1)
			       {
				system("clear");
				//cout<<dgreen<<"\n\n\n\n\n\n\n\t\t\t-------------------------------------\n";
				  //          displayString("\n\t\t\tEmployee details updated successfully"); 
				    //                  cout<<"\t\t\t-------------------------------------\n";
				//cout<<white;
   cout<<yellow<<"\n\t\t       ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t               O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t       ========================================="<<white<<endl;
	//	cout<<dgreen<<"\n\n\n"; 
 		 cout<<dgreen<<"\t\tEmployee details updated successfully"<<white;
		           //cout<<"\t\t\t-----------------------------------\n";cout<<white;	

cout<<"\n\n";

			getpass("\n\n\n\t\tPress <Enter> to go to Main menu");}
			      else
			      if (m.dbUpdate3(empid,pin)==0)
			        {cout<<dred<<"\n\t\tConnection error"<<white;cout<<"\n\n";getpass("\n\n\t\tPress <Enter> to go to Main menu");}
			      else
			      if (m.dbUpdate3(empid,pin)==-2)
			        {cout<<dred<<"\n\t\tNo record found"<<white;cout<<"\n\n";getpass("\n\n\t\tPress <Enter> to go to Main menu");}
else if( c2=='N' || c2=='n')
		{cout<<"\n\n\t\tDetails not updated";cout<<"\n\n"; getpass("\n\n\t\tPress <Enter> to go to Main menu");
		}

		   else
			   { cout<<dred<<"\n\t\tEmployee with given Employee ID Does not exist"<<white;}
			 }
		}
		break;
	}
	case 3:{
		string pno;
		if(empid!="-1")
		   {
		    cin.ignore();
		 label6:     cout<<"\n\t\tEnter Phone Number : ";
		      cin>>pno;
			int count6=0;
			for(int j=0;pno[j]!='\0';j++)
{
count6++;
}

if(count6==10)
{
for(int j=0;j<count6;j++)
{
   while( !( pno[j]>=48 && pno[j]<=57) )
  {  cout<<dred<<"\n\t\tPhone number should contain only digits.Please enter again"<<white;
   goto label6;
  }}
}
else
{
cout<<dred<<"\n\t\tPhone number should contain 10 digits.Please enter again"<<white;
goto label6;
}

			char c3;
			cout<<yellow<<"\n\t\tDo you want to update the details? (Y/N) : "<<white;
			cin>>c3;
			if(c3=='Y' || c3=='y')
			{
			      if (m.dbUpdate2(empid,pno)==1)
			       {system("clear");  
				// cout<<dgreen<<"\n\n\n\n\n\n\n\t\t\t-------------------------------------\n";  
				  //           displayString("\n\t\t\tEmployee details updated successfully"); 
			            //                   cout<<"\t\t\t-------------------------------------\n";
				//cout<<white;
				
   cout<<yellow<<"\n\t\t       ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t               O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t       ========================================="<<white<<endl;
	//	cout<<dgreen<<"\n\n\n"; 
 		 cout<<dgreen<<"\t\tEmployee details updated successfully"<<white;
		           //cout<<"\t\t\t-----------------------------------\n";
		
cout<<"\n\n";
				getpass("\n\n\n\t\tPress <Enter> to go to Main menu");	
				}
			      else
			      if (m.dbUpdate2(empid,pno)==0)
			       {cout<<dred<<"\n\t\tConnection error"<<white;cout<<"\n\n";getpass("\n\n\t\tPress <Enter> to go to Main menu");}
			      else
			      if (m.dbUpdate2(empid,pno)==-2)
			       {cout<<dred<<"\n\t\tNo record found"<<white;cout<<"\n\n";getpass("\n\n\t\tPress <Enter> to go to Main menu");}
			   else
		   { cout<<dred<<"\n\t\tEmployee with given Employee ID Does not exist"<<white;}
 			}
		}
		break;
	}
	default:{
		cout<<dred<<"\n\t\tEnter a valid option\n"<<white;
		break;}
		}
	}
	else

	{ cout<<dred<<"\n\t\tEmployee with given Employee ID Does not exist"<<white;cout<<"\n\n";getpass("\n\n\t\tPress <Enter> to go to Main menu");
  	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//Author		               <Rahul Ranjan>                                   // 
//Date				       <16-08-2013>                                     // 
//Name				       <Delete Employee Details>                        //
//Description			       <Delete the details of perticular employee>      //
//Arguments			       <Object of Employee database class>              //
//Returns		               <No return>                                      //
//Notes				       <Comments>                                       //
//Change History		       <Rahul Ranjan	20-08-2013>                     //
//////////////////////////////////////////////////////////////////////////////////////////
void CEmployeeUI::deleteEmpDetails(CEmployeeDB &m)
{
	system("clear");
	 // cout<<dcyan<<"\n\t\t\t    ----------------------------"<<white<<endl;
	 // cout<<dyellow<<"\n\t\t\t       Out Patient Department   "<<white<<endl;
//	cout<<dcyan<<"\n\t\t\t    ----------------------------"<<white<<endl;
//	cout<<dyellow<<"\n\t\t\t    Deactivate Employee Details "<<white<<endl;
//	cout<<dcyan<<"\n\t\t\t    ----------------------------"<<white<<endl;

   cout<<yellow<<"\n\t\t           ======================================================"<<white<<endl;
  cout<<magenta<<"\n\t\t                          O.P   D E P A R T M E N T              "<<white<<endl;
   cout<<yellow<<"\n\t\t           ======================================================"<<white<<endl;
  cout<<magenta<<"\n\t\t            D E A C T I V A T E   E M P L O Y E E   D E T A I L S"<<white<<endl;
   cout<<yellow<<"\n\t\t           ======================================================"<<white<<endl;




	string empid;
	int stat=0;
	cout<<"\n\t\tEnter Employee id (eg.EMPxxx): ";
	cin>>empid;
	string brid=emp.getBranchid();
	if(m.findEmpNo(empid,brid)==1)
	{
	char c4[5];
	cout<<yellow<<"\n\t\tAre you sure you want to deactivate? (Y/N) : "<<white;
del:	cin>>c4;
	int cnt=strlen(c4);
	if(cnt==1)
	{if( c4[0]=='Y' || c4[0]=='y')
	{
	  if(empid!="-1")
	  {
 	
	      if (m.dbDelete(empid,stat)==1)
        	{system("clear");  
	//	cout<<dgreen<<"\n\n\n\n\n\n\n\t\t\t-----------------------------------------\n"; 
	//	            displayString("\n\t\t\tEmployee details deactivated successfully"); 
         //	                      cout<<"\t\t\t------------------------------------------\n";
	//	cout<<white;
   cout<<yellow<<"\n\t\t       ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t               O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t       ========================================="<<white<<endl;
		//cout<<dgreen<<"\n\n\n"; 
 		 cout<<dred<<"\t\tEmployee details deactivated successfully"<<white;
		           //cout<<"\t\t\t-----------------------------------\n";
	//	 cout<<white;	
cout<<"\n\n";
	getpass("\n\n\t\tPress <Enter> to go to Main menu");
		}
	      else
	      if (m.dbDelete(empid,stat)==0)
	       { cout<<dred<<"\n\t\tConnection error"<<white; cout<<"\n\n";getpass("\n\n\t\tPress <Enter> to go to Main menu");}
	      else
	      if (m.dbDelete(empid,stat)==-2)
	       { cout<<dred<<"\n\t\tRecord not found"<<white; cout<<"\n\n";getpass("\n\n\t\tPress <Enter> to go to Main menu");}
	
   	    }
 	}
	else if( c4[0]=='N' || c4[0]=='n')
		{cout<<"\n\n\t\tDetails not deactivated";cout<<"\n\n"; getpass("\n\n\t\tPress <Enter> to go to Main menu");
		}
	else {cout<<"\n\t\tEnter a valid option : "; goto del; }
}   else {cout<<"\n\t\tEnter a valid option : ";goto del;}
		}	
	 
	  else
	   {cout<<dred<<"\n\t\tEmployee with given Employee ID does not exist"<<white;cout<<"\n\n";getpass("\n\n\t\tPress <Enter> to go to Main menu");}
 
}
void CEmployeeUI::displayError()
{
		cout<<dred<<"\n\t\tError takes place"<<white<<endl;
}





		
