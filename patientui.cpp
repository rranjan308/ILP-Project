//////////////////////////////////////////////////////////////////////////////////////////
//File Description		User Interface
//Contents			add,view patient details ,bill payment,create and view appointment
//Author			Tathagat Yash Nilesh Sarraf


//Date				20-08-2013
//
//////////////////////////////////////////////////////////////////////////////////////////
#include "mainui.h"
#include "maindb.h"
#include "patientui.h"
#include "patient.h"
#include<iostream>
#include<string>
#include "color.h"
#include <sstream>
#include "bill.h"
#include "Appointment.h"
#include "Doctor.h"
using namespace std;


CPatient pat;
CBill bi;


void CPatientui::setDocId(string did)
{
pat.setDoctorID(did);
}

void CPatientui::setBrId(string bid)
{
pat.setBranchid(bid);
bi.setBranchid(bid);
}



///////////////////////////////////////////////////////////////////////////////////////
//Author			Tathagat Yash
//Date				17-08-2013
//Name				displayMenudoctor
//Description			view menu
//Arguments			
//Returns			void
//Notes				<Comments>
//Change History			Tathagat		Date 24-08-2013		Description>
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui::displayMenudoctor()
{CMainUI mui;
CDatabase mdb;
CAppointmentDB adata;
system("clear");
	int ichoice;
	string did=pat.getDoctorID();
	  /*  cout<<yellow<<"\n\n\t\t           =======================================   "<<white<<endl;
         cout<<magenta<<"\n\t\t                   O.P   D E P A R T M E N T        "<<white<<endl;
           cout<<yellow<<"\n\t\t           =======================================  "<<white<<endl;
         cout<<magenta<<"\n\t\t            A P P O I N T M E N T   D E T A I L S   "<<white<<endl;
           cout<<yellow<<"\n\t\t           =======================================  "<<white<<endl;*/
   	do{system("clear");
cout<<yellow<<"\n\t\t===================================================================\n";      
cout<<magenta<<"\t\t       S W A S T I K   S U P E R   S P E C I A L I T Y             ";
 cout<<yellow<<"\n\t\t===================================================================\n";
        cout<<cyan<<"\t\t||                          WELCOME TO                           ||"<<endl
                    <<"\t\t||                                                               ||"<<endl
                    <<"\t\t||                   OUT PATIENT DEPARTMENT                      || \n"
                    <<"\t\t||                                                               || \n"
                    <<"\t\t||               PATIENT APPOINTMENT MANAGEMENT                  || \n"
                    <<"\t\t||                                                               || \n"<<white;
      //  cout<<yellow<<"\t\t\t-------------------------------------------------------------------\n";
        cout<<yellow<<"\t\t===================================================================\n\n";       
 //cout<<"\t\t\t-------------------------------------------------------------------\n\n"<<white;
 cout<<yellow<<"\t\t===================================================================\n\n"<<white;  
	cout<<"\n\n\t\t 1.View Appointment.";
	cout<<"\n\n\t\t 2.Logout.";
   	cout<<"\n\n\t\t 3.Exit.";

	
	cout<<"\n\n\t\tEnter your choice (1-3): ";
		
		cin>>ichoice;
                switch(ichoice)
                        {
                                case 1:
                                        {
                                                system("clear");
                                                view_AppointmentDoctor(adata);
                                                break;
                                        }

                                case 2:mui.login(mdb);break;
                                               
				case 3:exit(0);
                                default:
                                         displayString("You have given a invalid option ");
          }

       //  displayMenu();
        
        }while(ichoice!=3);

}

///////////////////////////////////////////////////////////////////////////////////////
//Author			Tathagat Yash
//Date				17-08-2013
//Name				displayMenu
//Description			view menu
//Arguments			
//Returns			void
//Notes				<Comments>
//Change History			Tathagat		Date 24-08-2013		Description>
//////////////////////////////////////////////////////////////////////////////////////////


void CPatientui::displayMenu()
{int ichoice; 
CPatdb data;
CMainUI mui;
CDatabase mdb;
CAppointmentDB adata;
CBilldb bdata;
CDoctorDB doc;
cin.ignore(255,'\n');
system("clear");

 cout<<yellow<<"\n\t\t===================================================================\n";      
cout<<magenta<<"\t\t       S W A S T I K   S U P E R   S P E C I A L I T Y             ";
 cout<<yellow<<"\n\t\t===================================================================\n";
        cout<<cyan<<"\t\t||                          WELCOME TO                           ||"<<endl
                    <<"\t\t||                                                               ||"<<endl
                    <<"\t\t||                   OUT PATIENT DEPARTMENT                      || \n"
                    <<"\t\t||                                                               || \n"
                    <<"\t\t||               PATIENT APPOINTMENT MANAGEMENT                  || \n"
                    <<"\t\t||                                                               || \n"<<white;
      //  cout<<yellow<<"\t\t\t-------------------------------------------------------------------\n";
        cout<<yellow<<"\t\t===================================================================\n\n";       
 //cout<<"\t\t\t-------------------------------------------------------------------\n\n"<<white;
 cout<<yellow<<"\t\t===================================================================\n\n"<<white;   
 cout<<"\n\n\t\t1. Add patient details"<<endl<<endl;
   cout<<"\t\t2. Display patient Details"<<endl<<endl;
   cout<<"\t\t3. Bill Payement"<<endl<<endl;
   cout<<"\t\t4. Display Bill Details"<<endl<<endl;
   cout<<"\t\t5. Create Appointment"<<"\n\n";
   cout<<"\t\t6. View Appointment Details"<<"\n\n";
   cout<<"\t\t7. Logout"<<"\n\n";
   cout<<"\t\t8. Exit"<<"\n\n";

do   {ichoice=getOption();

			switch(ichoice)
			{
			case 1:addPatientdetails(data);
			        break;
			case 2:
				{
				 cin.ignore(255,'\n');
				 system("clear");
  		    cout<<yellow<<"\n\n\t\t           ==================================  "<<white<<endl;
                cout<<magenta<<"\n\t\t               O.P   D E P A R T M E N T      "<<white<<endl;
                  cout<<yellow<<"\n\t\t           ==================================  "<<white<<endl;
                cout<<magenta<<"\n\t\t             P A T I E N T   D E T A I L S   "<<white<<endl;
                  cout<<yellow<<"\n\t\t           ==================================  "<<white<<endl;
cout<<"\n\t\t\t";
cout<<"\n\n\t\t1. Display all Patient Details";
cout<<"\n\n\t\t2. Display Patient Details by Patient ID";
cout<<"\n\n\t\t3. Go back to previous menu";
				 ichoice=getOption1();
				 switch(ichoice)
					{
					case 1:retrivePatrecords(data);
					break;
					case 2:retrivePatrecords1(data);
					break;
					case 3:displayMenu();

					     break	;
					}
				}break;
			case 3:addBilldetails(bdata,data);
                                break;
                        case 4:
                  		{
				cin.ignore(255,'\n');system("clear");
				 cout<<yellow<<"\n\n\t\t           ==========================="<<white<<endl;
                		cout<<magenta<<"\n\t\t            O.P   D E P A R T M E N T "<<white<<endl;
                  		 cout<<yellow<<"\n\t\t           ==========================="<<white<<endl;
                		cout<<magenta<<"\n\t\t             B I L L   D E T A I L S   "<<white<<endl;
                  		 cout<<yellow<<"\n\t\t           ==========================="<<white<<endl;
				cout<<"\n\t\t";
				cout<<"\n\n\t\t1. Display all Bill Details";
				cout<<"\n\n\t\t2. Display Bill Details by Bill Number";
				cout<<"\n\n\t\t3. Go back to previous menu";
                                ichoice=getOption1();
				switch(ichoice)
                                        {
                                        case 1:retriveBillrecords(bdata);
                                        break;
                                        case 2:retriveBillrecords1(bdata);
                                        break;
                                        case 3:
                                             displayMenu();break;
                                       }
		               }break;
			case 5:create_Appointment(adata, doc, data);
			        break;
			case 6:view_Appointment(adata);
				break;
			case 7:mui.login(mdb);break;
			
                        case 8:exit(0);
			default:displayString("\n Invalid Option");
			}
			displayMenu();
			
	}while(ichoice!=8);
   
}

///////////////////////////////////////////////////////////////////////////////////////
//Author			Tathagat Yash
//Date				17-08-2013
//Name				getOption
//Description			get option
//Arguments			
//Returns			int
//Notes				<Comments>
//Change History			Tathagat		Date 26-08-2013	Description>
//////////////////////////////////////////////////////////////////////////////////////////
int CPatientui::getOption()
{
char ch[10];
label: cout<<"\n\n\t\tEnter your option(1-8) : ";
       cin.getline(ch,10);
       int count=strlen(ch);
       while( !( count==1 && ch[0]>48 && ch[0]<57) )
       {  
	cout<<dred<<"\n\n\t\tPlease enter a number between 1 to 8.\n "<<white;
	goto label;
       }
       int choice=ch[0]-48;

       return choice;

}


int CPatientui::getOption1()
{
char ch[10];
label:   cout<<"\n\n\t\tEnter your option(1-3) : ";
         cin.getline(ch,10);
         int count=strlen(ch);
         while( !( count==1 && ch[0]>48 && ch[0]<52) )
         {  
         cout<<dred<<"\n\n\t\tPlease enter a number between 1 to 3.\n "<<white;
	 goto label;
         }
	 int choice=ch[0]-48;

         return choice;
}

///////////////////////////////////////////////////////////////////////////////////////
//Author			Tathagat Yash
//Date				17-08-2013
//Name				viewPatientdetails
//Description			view patient details
//Arguments			vector<CPatient> pat_records
//Returns			void
//Notes				<Comments>
//Change History			<Author		Date		Description>
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui:: viewPatientdetails(vector<CPatient> pat_records)
{   system("clear");
    vector<CPatient>::iterator patIter;
 cout<<yellow<<"\n\t\t     ================================="<<white<<endl;
cout<<magenta<<"\n\t\t         O.P   D E P A R T M E N T    "<<white<<endl;
 cout<<yellow<<"\n\t\t     ================================="<<white<<endl;
cout<<magenta<<"\n\t\t       P A T I E N T   D E T A I L S   "<<white<<endl;
 cout<<yellow<<"\n\t\t     ================================="<<white<<endl;    



    cout<<dcyan<<"________________________________________________________________________________________________\n"<<white;
    cout<<magenta<<"\nPATIENT ID\t"<<"NAME\t"<<"\tDATE OF BIRTH\t"<<"BLOOD GROUP\t"<<"MOBILE NUMBER\t"<<"EMG CONTACT NO.\n";
    cout<<dcyan<<"________________________________________________________________________________________________\n"<<white;
    for (patIter = pat_records.begin(); patIter != pat_records.end(); patIter++)  
       { 
         cout<<"\n"<<(*patIter).getId()<<"\t\t"<<(*patIter).getFname()<<" "<<(*patIter).getLname()<<"\t"<<(*patIter).getDob()<<"\t"<<(*patIter).getBgroup()<<"\t\t"<<(*patIter).getMobile()<<"\t"<<(*patIter).getEmgconno()<<"\n";
       }
cout<<yellow;
getpass("\n\n\t\tPress <Enter> to go to Main menu");
cout<<white;
}

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Tathagat Yash
//Date				17-08-2013
//Name				retrivePatrecords 
//Description			retieve patient records
//Arguments			CPatdb &m
//Returns			void
//Notes				<Comments>
//Change History			<Author		Date		Description>
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui:: retrivePatrecords(CPatdb &m)
{
  int result = 0;
  string brid=pat.getBranchid();
  vector<CPatient> pat_records;
  pat_records =m.dbSelect(brid);
  if(pat_records.size()!=0)
    viewPatientdetails(pat_records);
  else
    displayString("\n\n\t\tRecord not Found");
}

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Tathagat Yash
//Date				17-08-2013
//Name				retrivePatrecords1 
//Description			retieve patient records by patient id
//Arguments			CPatdb &m
//Returns			void
//Notes				<Comments>
//Change History			<Author		Date		Description>
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui:: retrivePatrecords1(CPatdb &m)
{

/*cout<<yellow<<"\n\t\t     ================================="<<white<<endl;
  cout<<magenta<<"\n\t\t         O.P   D E P A R T M E N T    "<<white<<endl;
   cout<<yellow<<"\n\t\t     ================================="<<white<<endl;
  cout<<magenta<<"\n\t\t      E M P L O Y E E   D E T A I L S "<<white<<endl;
   cout<<yellow<<"\n\t\t     ================================="<<white<<endl;*/
system("clear");

cout<<yellow<<"\n\t\t     ================================="<<white<<endl;
cout<<magenta<<"\n\t\t         O.P   D E P A R T M E N T    "<<white<<endl;
 cout<<yellow<<"\n\t\t     ================================="<<white<<endl;
cout<<magenta<<"\n\t\t       P A T I E N T   D E T A I L S   "<<white<<endl;
 cout<<yellow<<"\n\t\t     ================================="<<white<<endl; 
  int result = 0,iflag;
  char pats[20];
  cout<<"\n\n\n\t\tEnter Patient ID  : ";
	do
	{
	iflag=1;
 	cin>>pats;
	if((pats[0]!=80) || (pats[1]!=65) || (pats[2]!=84))
		{
		iflag=0;
		}
	if(iflag==0)
	{
		cout<<red<<"\n\n\t\tInvalid ID"<<white;
		cout<<"\n\n\t\tEnter Patient ID : ";
	}
	}while(iflag!=1);

 if(m.findPatientid(pats)==1)
   {
   CPatient pat1;
   pat1=m.dbSelect1(pats);
   if(sizeof(pat1)!=0)
    {
     system("clear");
 cout<<yellow<<"\n\t\t     ================================="<<white<<endl;
cout<<magenta<<"\n\t\t         O.P   D E P A R T M E N T    "<<white<<endl;
 cout<<yellow<<"\n\t\t     ================================="<<white<<endl;
cout<<magenta<<"\n\t\t       P A T I E N T   D E T A I L S   "<<white<<endl;
 cout<<yellow<<"\n\t\t     ================================="<<white<<endl;


      
          cout<<dcyan<<"\n\t\t____________________________________________________"<<white;
    cout<<magenta<<"\n\n\t\tPatient ID                         : "<<pat1.getId()<<white;
        cout<<dcyan<<"\n\t\t____________________________________________________\n"<<white;
	  cout<<cyan<<"\n\t\tFirst Name        "<<white<<"                 : "<<pat1.getFname()<<" "<<pat1.getMname()<<" "<<pat.getLname();
	cout<<cyan<<"\n\n\t\tDate of Birth    "<<white<<"                  : "<<pat1.getDob();
	cout<<cyan<<"\n\n\t\tAddress       "<<white<<"                     : "<<pat1.getAdd();
	cout<<cyan<<"\n\n\t\tCity          "<<white<<"                     : "<<pat1.getCity();
	cout<<cyan<<"\n\n\t\tPin           "<<white<<"                     : "<<pat1.getPin();
  	cout<<cyan<<"\n\n\t\tBlood Group         "<<white<<"               : "<<pat1.getBgroup();
	cout<<cyan<<"\n\n\t\tMartial Status     "<<white<<"                : "<<pat1.getMstatus();
	cout<<cyan<<"\n\n\t\tMobile Number       "<<white<<"               : "<<pat1.getMobile();
	cout<<cyan<<"\n\n\t\tEmergency Contact Name   "<<white<<"          : "<<pat1.getEmgconnm();
	cout<<cyan<<"\n\n\t\tEmergency Contact Number   "<<white<<"        : "<<pat1.getEmgconno();
	cout<<cyan<<"\n\n\t\tBranch            "<<white<<"                 : "<<pat.getBranchid()<<endl;
       
        getpass("\n\n\t\tPress <Enter> to go to Main menu");
       // cout<<white;
     } 
    
 else
    {
    cout<<red<<"\n\n\t\tRecord not Found"<<white<<endl;cout<<"\n\n\t\t";getpass("\t\t\tPress <Enter> to go to Main menu");
    }
  }
else
{
cout<<red<<"\n\n\t\tPatient ID does not exist \n"<<white<<endl;
}

}


void CPatientui::displayString(char* str)
{
     cout<<str<<endl;
}



//////////////////////////////////////////////////////////////////////////////////////////
//Author			Tathagat Yash
//Date				17-08-2013
//Name				addPatientdetails 
//Description			data base of Patient 
//Arguments			CPatdb &m
//Returns			void
//Notes				<Comments>
//Change History			<Author		Date		Description>
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui::addPatientdetails(CPatdb &m)
{  system("clear");
   cout<<yellow<<"\n\n\t\t           ====================================="<<white<<endl;
   cout<<magenta<<"\n\n\t\t               O.P   D E P A R T M E N T      "<<white<<endl;
   cout<<yellow<<"\n\n\t\t           ====================================="<<white<<endl;
   cout<<magenta<<"\n\n\t\t          A D D  P A T I E N T   D E T A I L S"<<white<<endl;
   cout<<yellow<<"\n\n\t\t           ====================================="<<white<<endl;    
  int i,flag=0,c[1],year,month,day,cmm,cdd,cyy;
  char  mnm[20],lnm[20],emgnm[20],mstatus[10],city[20], pin[20],mobile[15],emobile[15], fnm[20],ch,dash1,dash2,add[30],choi[10];
  string dob,id,bgroup,date,bid;
  id=m.genPatientid();
  pat.setId(id);
cout<<yellow"\n\tStarred fields are mandatory\n\n"<<white;
while(1)
     {cout<<"\n\t\tFirst name"<<yellow<<"*"<<white<<"                  : ";
      int flag=1;
       cin>>fnm;
           for(int i=0;fnm[i]!='\0';i++)
                              {
                             if((fnm[i]>=65 && fnm[i]<=90)||(fnm[i]>=97 && fnm[i]<=122))
                                { flag==1;  }
                                else
                                {
				cout<<red<<"\n\n\t\tInvalid name. Please enter again"<<white;
                              //  cout<<;
                                flag=0;
                                break;
                                }
                                }
                                if(flag==1)
                               { break; }
     }

pat.setFname(fnm);

while(1)
     {
cout<<"\n\n\t\tMiddle name                  : ";
      int flag=1;
	cin.clear();
       cin.ignore(200,'\n');
       cin.getline(mnm,20);
		
           for(int i=0;mnm[i]!='\0';i++)
                              {
                             if((mnm[i]>=65 && mnm[i]<=90)||(mnm[i]>=97 && mnm[i]<=122))
                                { flag==1;  }
                                else
                                {
                                cout<<red<<"\n\n\t\tInvalid name. Please enter again"<<white;
                              //  cout<<;
                                flag=0;
                                break;
                                }
                                }
                                if(flag==1)
                               { break; }
     }

pat.setMname(mnm);

while(1)
     {
cout<<"\n\n\t\tLast name"<<yellow<<"*"<<white<<"                   : ";
      int flag=1;
       cin>>lnm;
           for(int i=0;lnm[i]!='\0';i++)
                              {
                             if((lnm[i]>=65 && lnm[i]<=90)||(lnm[i]>=97 && lnm[i]<=122))
                                { flag==1;  }
                                else
                                {
                                cout<<red<<"\n\n\t\tPlease enter correct last name"<<white;
                              //  cout<<;
                                flag=0;
                                break;
                                }
                                }
                                if(flag==1)
                               { break; }
     }
pat.setLname(lnm);


ostringstream out;
time_t now = time(0);
tm *ltm = localtime(&now);



cdd = ltm->tm_mday;
cmm=(1 + ltm->tm_mon);
cyy= (1900+ltm->tm_year); 



label: cout<< "\n\n\t\tDate Of Birth (DD-MM-YYYY)"<<yellow<<"*"<<white<<"  : " ;

while(!(cin>>day>>dash1>>month>>dash2>>year))
 {	
 cout<<red<<"\n\t\tEnter a valid date"<<white;
cout<<"\n\n\t\t";
     cin.clear();
     cin.ignore(255,'\n');

 } 
 
if(year<=cyy and year>=(cyy-130) )
	{	if(year==cyy)
		{				
			if(month<=cmm)
			{	if(day<=cdd)
				    goto a;
				else {cout<<red<<"\n\n\t\tEnter a valid date"<<white<<endl; 
				    goto label;}
			}
		else {cout<<red<<"\n\n\t\tEnter a valid month\n"<<white<<endl;
		goto label;}
		}
		else 
		
		{			 	
	
	
	        a:switch(month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
									{if(day>=1 && day<=31 && dash1=='-' && dash2=='-')
                                                        		{out<<day<<dash1<<month<<dash2<<year;
                                                         		date=out.str();
									}

									else {cout<<red<<"\n\n\t\tEnter a valid date"<<white<<endl;goto label;}
                                                      
                                                        		break;
									}
									
case 2:{ 
	{if(day>=1 && day<=28 && dash1=='-' && dash2=='-')
        {out<<day<<dash1<<month<<dash2<<year;
        date=out.str();
	}
	else {cout<<red<<"\n\n\t\tEnter a valid date"<<white<<endl; goto label;}
        break;
	}
	}
case 4: case 6: case 9: case 11: {
				if(day>=1 && day<=30 && dash1=='-' && dash2=='-')
                                {out<<day<<dash1<<month<<dash2<<year;
                                date=out.str();}
				else {cout<<red<<"\n\n\t\tEnter a valid date"<<white<<endl; goto label;}
                                break;
				}
default:cout<<red<<"\n\n\t\tEnter a valid date"<<white<<endl;
        goto label;
		}
             }	     
	}

else {
	cout<<red<<"\n\n\t\tEnter valid year"<<white;
        goto label;
     }


pat.setDob(date);


cout<<"\n\n\t\tAddress*                     : ";
cin.clear();
cin.ignore(200,'\n');
cin.getline( add,30 );

pat.setAdd(add);


while(1)
     {
cout<<"\n\n\t\tPin Code* (6 digits)         : ";
      int flag=1;
       cin>>pin;
           for( i=0;pin[i]!='\0';i++)
                              {
                             if((pin[i]>=48 && pin[i]<=57))
                                { flag==1;  }
                                else
                                {
                                cout<<red<<"\n\n\t\tPlease enter numbers"<<white;
                              //  cout<<;
                                flag=0;
                                break;
                                }
                                }
         for (i=0;pin[i]!='\0';i++);
         if(flag==1 and i!=6 )
        { flag=0;cout<<red<<"\n\n\t\tEnter only 6 digits"<<white;}
                                if(flag==1)
                               { break; }
     }

pat.setPin(pin);
cin.clear();
cin.ignore(200,'\n');
while(1)
     {
cout<<"\n\n\t\tCity*                        : ";
      int flag=1;
       cin>>city;
           for(int i=0;city[i]!='\0';i++)
                              {
                             if((city[i]>=65 && city[i]<=90)||(city[i]>=97 && city[i]<=122))
                                { flag==1;  }
                                else
                                {
                                cout<<red<<"\n\n\t\tPlease enter characters"<<white;
                              //  cout<<;
                                flag=0;
                                break;
                                }
                                }
                                if(flag==1)
                               { break; }
     }

pat.setCity(city);
cin.clear();
cin.ignore(200,'\n');
cout<<yellow<<"\n\n\t\tEnter the Blood group among the following* :\n\n\t\t"<<"1.O+"<<"\t\t2.A+"<<"\n\t\t3.B+"<<"\t\t4.AB+"<<"\n\t\t5.O-"<<"\t\t6.A-"<<"\n\t\t7.B-"<<"\t\t8.AB-";
label1:cout<<white<<"\n\t\tEnter your choice            : ";
cin>>choi;
int count=strlen(choi);


while(!(count==1 && ( choi[0]>48 && choi[0]<57)) )
 {  cout<<dred<<"\n\t\tPlease enter a valid number \n "<<white;
    goto label1;
 }

int ch1=choi[0]-48;
switch(ch1)
	{
		case 1:
			{
				bgroup="O+";
				break;
			}
		case 2:
			
                        {
                                bgroup="A+";
                                break;
                        }
                case 3:
			
                        {
                               bgroup="B+";
                                break;
                        }
                case 4:
			
                        {
                                bgroup="AB+";
                                break;
                        }
                case 5:
			
                        {
                                bgroup="O-";
                                break;
                        }
                case 6:
			
                        {
                                bgroup="A-";
                                break;
                        }
                case 7:
			
                        {
                                bgroup="B-";
                                break;
                        }
                case 8:
			
                        {
                                bgroup="AB+";
                                break;
                        }
                default:
				cout<<"\n\t\tInvalid Blood Group";
	}
pat.setBgroup(bgroup);

cout<<yellow<<"\n\n\t\tMartial Status*"<<endl
<< "\t\t1 - Married  \t\t 2- Unmarried"<<white;

label2:cout<<white<<"\n\n\t\tEnter your choice            : ";
cin>>choi;
count=strlen(choi);

while(!(count==1 && ( choi[0]>48 && choi[0]<=50)) )
{  cout<<dred<<"\n\t\tPlease enter a valid number"<<white;
     goto label2;
}

ch1=choi[0]-48;
switch(ch1)
        {
                case 1:
                        {
                                strcpy(mstatus,"MARRIED");
                                break;
                        }
                case 2:

                        {
                               strcpy(mstatus,"UNMARRIED");
                                break;
			}		
	}	
       
pat.setMstatus(mstatus);
       


while(1)
     {
cout<<"\n\n\t\tPhone number*                : ";
      int flag=1;
       cin>>mobile;
           for( i=0;mobile[i]!='\0';i++)
                              {
                             if((mobile[i]>=48 && mobile[i]<=57))
                                { flag==1;  }
                                else
                                	{
                                	cout<<red<<"\n\t\tPlease enter numbers"<<white;
                              //  cout<<;
                                	flag=0;
                                	break;
                                	}	
                                }
	 for( i=0;mobile[i]!='\0';i++);
	 	if(flag==1 and i!=10 )
	 		flag=0;	
         if(flag==1)
         	break; 

	cout<<red<<"\n\t\tEnter 10 digits"<<white; 
     }


pat.setMobile(mobile);



while(1)
     {
      cout<<"\n\n\t\tEmergency contact Name*      : ";
      int flag=1;
       cin>>emgnm;
           for(int i=0;emgnm[i]!='\0';i++)
                              {
                             if((emgnm[i]>=65 && emgnm[i]<=90)||(emgnm[i]>=97 && emgnm[i]<=122))
                                 flag==1;  
                              else
                                {
                                cout<<red<<"\n\n\t\tPlease enter correct name"<<white;
                              //  cout<<;
                                flag=0;
                                break;
                                }
                               }
            if(flag==1)
                break; 
     }


pat.setEmgconnm(emgnm);

while(1)
     {
       cout<<"\n\n\t\tEnter emergency phone number*: ";
       int flag=1;
       cin>>emobile;
           for( i=0;emobile[i]!='\0';i++)
                              {
                                if((emobile[i]>=48 && emobile[i]<=57))
                                	flag==1;  
                                else
                                	{
                                	cout<<red<<"\n\t\tPlease enter numbers"<<white;
                              //  cout<<;
                                	flag=0;
                                	break;
                                	}
                               }
         for( i=0;emobile[i]!='\0';i++);
         	if(flag==1 and i!=10 )
         	{cout<<red<<"\n\t\tPlease enter 10 digits"<<white;	flag=0;}

         if(flag==1)
              break; 
     }     



pat.setEmgconno(emobile);
bid=pat.getBranchid();
pat.setBranchid(bid);


	char c4[5];
	cout<<yellow<<"\n\n\t\tAre you sure you want to add details? (Y/N) : "<<white;
del:	cin>>c4;
	int cnt=strlen(c4);
	if(cnt==1)
	{
        	if( c4[0]=='Y' || c4[0]=='y')
			{
      			 if( m.dbInsert(pat)==1)
         		  {  system("clear");

				/*cout<<"\n\n\n\n\n\n\n";
                   		cout<<dgreen<<"\t\t\t----------------------------------\n";
                 		displayString("\n\t\t\tPatient details added successfully");
                           	cout<<"\t\t\t----------------------------------\n";
                 		cout<<white;
 				cout<<dgreen<<"\n\t\t\tPatient ID is : "<<id<<"\n\n"<<white;    
				getpass("\t\t\tPress <Enter> to go to Main menu");*/


cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t             O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;
		cout<<dgreen<<"\n\n\n"; 
 		 displayString("\t\tPatient details added successfully");
		           //cout<<"\t\t\t-----------------------------------\n";
		 cout<<white;
		cout<<"\n\n\n\t\tPatient ID is : "<<yellow<<id<<white<<"\n\n";
		getpass("\n\t\tPress <Enter> to go to Main menu");
         		 }	
      			else if( m.dbInsert(pat)==0)
       			 {
			 cout<<red; displayString("\n\t\t\tConnection error");
			 cout<<white;
			 }
                        else if( m.dbInsert(pat)==-2)
       			 {
			 cout<<red; displayString("\n\t\t\tPatient  not added");
			 cout<<white;
			 }	 
                        else
                         {
			 cout<<red; displayString("\n\t\tEnter a valid number between 1 to 100");cout<<white;
			 }
	                }
  		else if( c4[0]=='N' || c4[0]=='n')
		 {
		 cout<<"\n\n\t\tDetails not added"<<"\n\n"; getpass("\n\t\tPress <Enter> to go to Main menu");
		 }
	else 
	 {
	 cout<<red<<"\n\t\tEnter a valid option : "<<white; goto del; 
	 }
       } 
  else 
   {
   cout<<red<<"\n\t\tEnter a valid option : "<<white;goto del;
   }
}


void CPatientui:: displayError()
	{
		cout<<"\t\t\tError takes place"<<endl;
	}

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Tathagat Yash
//Date				17-08-2013
//Name				viewBilldetails
//Description			view bill details
//Arguments			vector<CBill> bill_records
//Returns			void
//Notes				<Comments>
//Change History			<Author		Date		Description>
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui:: viewBilldetails(vector<CBill> bill_records)
{
vector<CBill>::iterator billIter;
system("clear");
      cout<<yellow<<"\n\n\t\t           ============================"<<white<<endl;
    cout<<magenta<<"\n\t\t            O.P   D E P A R T M E N T  "<<white<<endl;
      cout<<yellow<<"\n\t\t           ============================"<<white<<endl;
    cout<<magenta<<"\n\t\t             B I L L   D E T A I L S   "<<white<<endl;
      cout<<yellow<<"\n\t\t           ============================"<<white<<endl;

cout<<cyan<<"\n\t__________________________________________________________________________________________"<<white;
cout<<magenta<<"\n\n\tBill Id \t\t"<<"Patiend ID\t\t"<<"Bill date\t"<<"Bill amount(RS)\t"<<"Branch Id";
cout<<cyan<<"\n\t__________________________________________________________________________________________\n\n"<<white;
    
    for (billIter = bill_records.begin(); billIter != bill_records.end(); billIter++)   
	 {
	  cout<<"\t"<<(*billIter).getBillid()<<"\t\t"<<(*billIter).getPatientid()<<"\t\t\t"<<(*billIter).getBilldate()<<"\t\t"<<(*billIter).getBillamt()<<"\t"<<(*billIter).getBranchid()<<"\n";
   	}
cout<<endl<<endl;
getpass("\n\t\tPress <Enter> to go to Main menu");
}

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Tathagat Yash
//Date				17-08-2013
//Name				retriveBillrecords
//Description			retrieve bill records
//Arguments			CBilldb &m
//Returns			void
//Notes				<Comments>
//Change History			<Author		Date		Description>
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui:: retriveBillrecords(CBilldb &m)
{
  int result = 0;
  string bbrid =bi.getBranchid();
  vector<CBill> bill_records;
  bill_records =m.dbSelect(bbrid);
  if(bill_records.size()!=0)
    viewBilldetails(bill_records);
  else
    {cout<<red; displayString("\n\t\t\tRecord not Found"); cout<<white;}

}

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Tathagat Yash
//Date				17-08-2013
//Name				retriveBillrecords1
//Description			retrieve bill records by bill no.
//Arguments			CBilldb &m
//Returns			void
//Notes				<Comments>
//Change History			<Author		Date		Description>
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui:: retriveBillrecords1(CBilldb &m)
{
  int result = 0,iflag;
  char billno[20];
  cout<<"\n\n\n\t\tEnter Bill ID : ";
	do
	{
	iflag=1;
 	cin>>billno;
	if((billno[0]!=66) || (billno[1]!=105) || (billno[2]!=108) || (billno[3]!=108)|| (billno[4]!=78)|| (billno[5]!=111))
		{
		iflag=0;
		}
	if(iflag==0)
	{
		cout<<red<<"\n\n\t\tInvalid ID"<<white;
		cout<<"\n\n\t\tEnter Bill ID : ";
	}
	}while(iflag!=1);

if(m.findBillid(billno)==1)
{
CBill bill1;
bill1=m.dbSelect1(billno);
 if(sizeof(bill1)!=0)
  {
  system("clear"); 
  cout<<magenta<<"\n\n\t\t\t================================================================\n\n"<<white;
          cout<<cyan<<"\t\t\t       S W A S T I K   S U P E R   S P E C I A L I T Y \n\n "<<white;  
  cout<<magenta<<"\t\t\t================================================================\n\n"<<white;
  cout<<yellow<<"\t\t\tBill No   : "<<white<<bill1.getBillid()<<yellow<<"\t\tDate Of Payment : "<<white<<bill1.getBilldate();	
  cout<<"\n\n";
  cout<<yellow<<"\t\t\tPatient ID: "<<white<<bill1.getPatientid()<<yellow<<"\t\tBranch          : "<<white<<bill1.getBranchid();
               cout<<"\n\n\t\t\t----------------------------------------------------------------\n";
                cout<<"\t\t\t  Description\t\t\t\t             Amount\n";	
               cout<<"\n\n\t\t\t----------------------------------------------------------------\n";
               cout<<"\n\t\t\tRegistration Fees                                    :Rs."<<bill1.getBillamt()<<"\n\n";
               cout<<"\n\n\n\n\n\n\t\t\t----------------------------------------------------------------\n\n\n";
               cout<<"\t\t\tTotal Amount                                         :Rs."<<bill1.getBillamt()<<"\n\n";

  cout<<endl;
  getpass("\n\t\t\tPress <Enter> to go to Main menu");
  }
 else
  {
  displayString("\n\t\t\tBill no is invalid");cout<<endl;getpass("\t\t\tPress <Enter> to go to Main menu");
  }
}
else
{
cout<<red<<"\n\t\t\t\tBill ID does not exist \n"<<white<<endl;
getpass("\t\t\tPress <Enter> to go to Main menu");
}

}

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Tathagat Yash
//Date				17-08-2013
//Name				addPatientdetails 
//Description			add bill details
//Arguments			CPatdb &m
//Returns			void
//Notes				<Comments>
//Change History			<Author		Date		Description>
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui::addBilldetails(CBilldb &m,CPatdb &p)
{ 
CBill bill,billi; 
char ch,pid[20];
int amt,flag=0,fla,iflag,cdd,cmm,cyy;
string date,bid,brid;
system("clear");
time_t now = time(0);
tm *ltm = localtime(&now);
cdd = ltm->tm_mday;
cmm=(1 + ltm->tm_mon);
cyy= (1900+ltm->tm_year);
 /*cout<<magenta<<"\n\n\t\t\t================================================================\n\n"<<white;
 cout<<cyan<<"\t\t\t       S W A S T I K   S U P E R   S P E C I A L I T Y \n\n "<<white;
 cout<<magenta<<"\n\t\t\t================================================================\n\n"<<white;
cout<<cyan<<"\t\t\t        O . P    D E P A R T M E N T   BILL   P A Y M E N T\n\n "<<white;
 cout<<magenta<<"\n\t\t\t================================================================\n\n"<<white;*/
   cout<<yellow<<"\n\n\t\t           ============================"<<white<<endl;
    cout<<magenta<<"\n\t\t            O.P   D E P A R T M E N T  "<<white<<endl;
     cout<<yellow<<"\n\t\t           ============================"<<white<<endl;
    cout<<magenta<<"\n\t\t             B I L L   P A Y M E N T   "<<white<<endl;
     cout<<yellow<<"\n\t\t           ============================"<<white<<endl;


do
{
fla=0;
  cout<<"\n\n\n\t\tEnter Patinet ID : ";
	do
	{
	iflag=1;
 	cin>>pid;
	if((pid[0]!=80) || (pid[1]!=65) || (pid[2]!=84))
		{
		iflag=0;
		}
	if(iflag==0)
	{
		cout<<red<<"\n\n\t\tInvalid ID"<<white;
		cout<<"\n\n\t\tEnter Patinet  ID : ";
	}
	}while(iflag!=1);
 	if(p.findPatientid(pid)==1)
		{
		bill.setPatientid(pid);
			{
		            bid=m.genBillid();
                            bill.setBillid(bid);
                            brid=pat.getBranchid();
                            int bamt;		   
			    billi=m.dbBillselect();
                            system("clear");
                cout<<magenta<<"\n\n\t\t\t================================================================\n\n"<<white;
                cout<<cyan<<"\t\t\t       S W A S T I K   S U P E R   S P E C I A L I T Y \n\n "<<white;
                cout<<magenta<<"\t\t\t================================================================\n\n"<<white;
                cout<<yellow<<"\t\t\tBill No   : "<<white<<bid<<yellow<<"\t\tDate of Bill   : "<<white<<cdd<<"-"<<cmm<<"-"<<cyy<<white;
  cout<<"\n\n";
  cout<<yellow<<"\t\t\tPatient ID: "<<white<<pid<<yellow<<"\t\tBranch         : "<<white<<brid;
               cout<<"\n\n\t\t\t----------------------------------------------------------------\n";
		 cout<<"\t\t\t Description\t\t\t\t              Amount";	
               cout<<"\n\n\t\t\t----------------------------------------------------------------\n";
               cout<<"\t\t\t "<<billi.getBilltype()<<"                                    :Rs."<<billi.getBillamt()<<"\n\n";
               cout<<"\n\n\n\n\n\n\t\t\t----------------------------------------------------------------\n\n\n";
               cout<<"\t\t\tTotal Amount                                         :Rs."<<billi.getBillamt()<<"\n\n";
               cout<<"\n\t\t\t----------------------------------------------------------------\n\n\n";

  cout<<endl;
  //getpass("\n\n\t\tPress <Enter> to go to Main menu");





			  //  cout<<"S.No\t"<<"Bill Description \t\t"<<"Amount\n";
			   // cout<<bid<<billi.getBilltype()<<"\t\t"<<billi.getBillamt()<<endl;
			    bamt=billi.getBillamt();	
			    bill.setBillamt(bamt);
			    bill.setBranchid(brid);
			    cout<<yellow<<"\n\t\tContinue with Bill payment?(Y/N) : "<<white;
				char c4[10];
                            del:	cin>>c4;
			    int cnt=strlen(c4);
				if(cnt==1)
				 {
				  if( c4[0]=='Y' || c4[0]=='y')
				    {
      				     if( m.dbInsert(bill)==1)
     	 				 {	
	system("clear"); //displayString("\t\tPatient details  added successfully");
  /*  cout<<yellow<<"-------------------------------------------------------------------------------------------\n";
    cout<<yellow<<"-------------------------------------------------------------------------------------------\n"<<green;
    cout<<"                              SWASTIK SUPER SPECIALITY HOSPITAL        \n";
    cout<<yellow<<"--------------------------------------------------------------------------------------------\n";
    cout<<yellow<<"--------------------------------------------------------------------------------------------\n"<<white;

    cout<<green<<"           			ADDED SUCCESSFULLY\n";*/
system("clear");
		//cout<<"\n\n\n\n\n\n\n";
   cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t             O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;
		cout<<dgreen<<"\n\n\n"; 
 		 displayString("\t\tBill payment successful");
		           //cout<<"\t\t\t-----------------------------------\n";
		 cout<<white;
		cout<<"\n\n\t\tBill Number : "<<yellow<<bid<<white<<"\n\n";
		getpass("\n\t\tPress <Enter> to go to Main menu");
        	
    //cout<<"\n\tBill ID\t\t: "<<bid;
  //  cout<<"\n\n";
  //  getpass("\t\t Press <Enter> to go to Main menu");

		                       }

                                    else if( m.dbInsert(bill)==0)
          			    {
				    cout<<red; displayString("Connection error         ");
				    }
                                    else if( m.dbInsert(bill)==-2)
                                    displayString("Bill details  not added");
                                    else
                                    displayString("Enter a valid number between 1  to 100.    ");
				   }
	                	else if( c4[0]=='N' || c4[0]=='n')
				{
				cout<<"\n\n\t\tPayment cancelled"<<endl; getpass("\n\t\tPress <Enter> to go to Main menu");
				}
	                        else 
				{
				cout<<"\n\t\tEnter a valid option : "; goto del; 
				}
			       }
			      else 
			      {
			      cout<<"\n\t\tEnter a valid option : ";goto del;
                              }
		         }
                     }

   else 
   {
   cout<<red<<"\n\n\t\tPatient id does not exit"<<white;fla=1;cout<<white;
   }
 }while(fla==1);

}

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Nilesh Sarraf                                           //
//Date				18-08-2013                                              //
//Name				View Doctor                                             //
//Description			For viewing all doctors information from databse        //
//Arguments			Doctor databse class                                    //
//Returns			void                                                    //
//Notes				                                                        //
//Change History			                                                //
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui::view_Doctor(CDoctorDB &a)
{       CDoctor doc; 
	cout<<"\nDoctors on Panel\n";
	vector <CDoctor> doc_details;
	string brid=pat.getBranchid();
	cout<<brid;
	doc_details=a.dbselectDoctor(brid);
	if(doc_details.size()!=0)
		displayd(doc_details);
	else
		displayString("\n\n\t\tDoctor ID does not exist");

}

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Nilesh Sarraf                                           //
//Date				19-08-2013                                              //
//Name				Display Doctor details                                  //
//Description			For displaying all doctors information from databse     //
//Arguments			vector<CDoctor> doc_details                             //
//Returns			void                                                    //
//Notes				                                                        //
//Change History			                                                //
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui::displayd(vector<CDoctor> doc_details)
{
	
	vector<CDoctor>::iterator Dociter;
	cout<<cyan<<"\n                                      Doctors On Panel\n";
	cout<<"          ____________________________________________________________________________________\n";

	
	cout<<"          Doctor ID"<<"\t\t\t"<<"Doctor Name"<<"\t\t\t        "<<"Timings\n";
	//cout<<"          ------------------------------------------------------------------------------"<<white;
       cout<<"          ____________________________________________________________________________________\n"<<white;

	for(Dociter=doc_details.begin();Dociter!=doc_details.end();Dociter++)
	     cout<<"\n          "<<(*Dociter).getDoctorID()<<"\t\t\t"<<(*Dociter).getDocname()<<"\t\t\t\t"<<(*Dociter).getTime();
	cout<<endl;
}



//////////////////////////////////////////////////////////////////////////////////////////
//Author			Nilesh Sarraf                                           //
//Date				17-08-2013                                              //
//Name				Date Validation                                         //
//Description			It validates the date that it is in proper format       //
//Arguments			                                                        //
//Returns			string                                                  //
//Notes				                                                        //
//Change History			                                                //
//////////////////////////////////////////////////////////////////////////////////////////
string CPatientui::enterdate()
{
string date;
ostringstream out;
int year, month, day;
char dash1, dash2;
label:cout<< "\n\n\t\tEnter Date (dd-mm-yyyy)\t: " << flush;
while(!(cin>>day>>dash1>>month>>dash2>>year))
{
 cout<<red<<"\n\n\t\tSorry! it is an invalid entry  "<<white;
 cin.clear();
 cin.ignore(255,'\n');
	goto label;
}
time_t t = time(NULL);
struct tm tm = *localtime(&t);
int curday=tm.tm_mday;
int curmonth=tm.tm_mon+1;
int curyear=tm.tm_year+1900;
if ((dash1=='-') && (dash2=='-'))
  {
   if((day>=curday && day<=curday+10) && (month==curmonth) && (year==curyear) )
	{
	if(month<10)
		out<<day<<dash1<<"0"<<month<<dash2<<year;
	else
		out<<day<<dash1<<month<<dash2<<year;
			
        date=out.str();
	
        return date;
	}
   else
	{
	cout<<red<<"\n\n\t\tAppoinments are available only for next 10 days"<<white;
	goto label;
	}
   }
else
{
cout<<red<<"\n\n\t\tPlease enter date in given format"<<white;
goto label;
}

}
//////////////////////////////////////////////////////////////////////////////////////////
//Author			Nilesh Sarraf                                           //
//Date				17-08-2013                                              //
//Name				Appointment Creation                                    //
//Description			It Creates an appointment for patient                   //
//Arguments			Database class of patient,appointment and doctor        //
//Returns			void                                                    //
//Notes				                                                        //
//Change History			                                                //
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui::create_Appointment(CAppointmentDB &a, CDoctorDB &b, CPatdb &c)
{
	system("clear");
	/*cout<<yellow<<"-------------------------------------------------------------------------------------------\n";
cout<<yellow<<"-------------------------------------------------------------------------------------------\n"<<green;
cout<<"                              SWASTIK SUPER SPECIALITY HOSPITAL        \n";
cout<<yellow<<"--------------------------------------------------------------------------------------------\n";
cout<<yellow<<"--------------------------------------------------------------------------------------------\n"<<white;
cout<<white<<"||	                	   Create Appointment                                    ||\n"; 
cout<<yellow<<"--------------------------------------------------------------------------------------------\n";
cout<<yellow<<"--------------------------------------------------------------------------------------------\n"<<white;*/
   cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t             O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t        C R E A T E   A P P O I N T M E N T   "<<white<<endl;
   cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;



	CAppointment ca;
	string bid;
	char sure,pid[20],did[20];
	string  aid;
	string adate;
	string atime;
	int flaag,iflag;
do
{
flaag=0;
cout<<"\n\n\t\tEnter Patient ID : ";
	do
	{
	iflag=1;
 	cin>>pid;
	if((pid[0]!=80) || (pid[1]!=65) || (pid[2]!=84))
		{
		iflag=0;
		}
	if(iflag==0)
	{
		cout<<red<<"\n\n\t\tInvalid ID"<<white;
		cout<<"\n\n\t\tEnter Patient ID (eg.PATxxx): ";
	}
	}while(iflag!=1);
	if(c.findPatientid(pid)==1){
	CPatientui ci;
	vector <CDoctor> doc_details;
	//cout<<yellow;
	string brid=pat.getBranchid();
	doc_details=b.dbselectDoctor(brid); //cout<<white;
	ci.displayd(doc_details);
	int flag;
        do
         {	
          flag=0;
	  cout<<"\n\n\t\tEnter Doctor ID : ";
	    do
	{
	iflag=1;
 	cin>>did;
	if((did[0]!=68) || (did[1]!=79) || (did[2]!=67))
		{
		iflag=0;
		}
	if(iflag==0)
	{
		cout<<red<<"\n\n\t\tInvalid ID"<<white;
		cout<<"\n\n\t\tEnter Doctor ID (eg.DOCxxx) : ";
	}
	}while(iflag!=1);
	if(b.findDocid(did)==1){
	adate=enterdate();
	ca.setPatientID(pid);
	ca.setDoctorID(did);
	ca.setApp_Date(adate);
	string brid=pat.getBranchid();
	ca.setBranchID(brid);
	aid=a.genAppid();
        ca.setAppointmentID(aid);
	cout<<yellow<<"\n\n\t\tAre you sure to create this appointment (Y/N) : "<<white;
        char c4[20];  
del:	cin>>c4;
	int cnt=strlen(c4);
	if(cnt==1)
	 { if( c4[0]=='Y' || c4[0]=='y')
	{
    if(a.dbinsertAppointment(ca)>0)
     {
    system("clear");
   /* cout<<yellow<<"-------------------------------------------------------------------------------------------\n";
    cout<<yellow<<"-------------------------------------------------------------------------------------------\n"<<green;
    cout<<"                              SWASTIK SUPER SPECIALITY HOSPITAL        \n";
    cout<<yellow<<"--------------------------------------------------------------------------------------------\n";
    cout<<yellow<<"--------------------------------------------------------------------------------------------\n"<<white;
	
     cout<<green<<"                             ADDED SUCCESSFULLY\n";

		cout<<green<<"\n                  ********      Appointment ID   : "<<aid<<"     *******"<<reset<<" \n";
		cout<<white; getpass("                             Press enter to continue");*/

		//cout<<"\n\n\n\n\n\n\n";
   cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t             O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;
		cout<<dgreen<<"\n\n\n"; 
 		 displayString("\t\tAppointment created successfully");
		           //cout<<"\t\t\t-----------------------------------\n";
		 cout<<white;
		cout<<"\n\n\n\t\tAppointment ID is : "<<yellow<<aid<<white<<"\n\n";
		getpass("\n\t\tPress <Enter> to go to Main menu");


     }
    else
     {
		cout<<red<<"\n\n\t\tError"<<white;
     }
   }	
else if( c4[0]=='N' || c4[0]=='n')
		{cout<<"\n\n\t\tAppointment not created"<<endl<<endl; getpass("\n\n\t\tPress <Enter> to go to Main menu");
		}
	else {cout<<"\n\n\t\tEnter a valid option : "; goto del; }
}   else {cout<<"\n\n\t\tEnter a valid option : ";goto del;}
			

 }
else
{
cout<<red;
displayString("\n\n\t\tDoctor ID does not exist");cout<<white;
flag=1;
}
}while(flag==1);}
	else
	{
	 cout<<red;displayString("\n\n\t\tPatient ID does not exist");cout<<white;
	flaag=1;	
	}
}while(flaag==1);	

}

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Nilesh Sarraf                                               //
//Date				17-08-2013                                                  //
//Name				View Appointment                                            //
//Description			It Retrieve all the appointment information from database   //
//Arguments			Appointment database class                                  //
//Returns			void                                                        //
//Notes				                                                     //
//Change History			                                                     //
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui::view_Appointment(CAppointmentDB &a)
{

	vector <CAppointment> app_details;
	
	string brid=pat.getBranchid();
	
	app_details=a.dbselectAppointment(brid);
	if(app_details.size()!=0)
		display(app_details);
	else
		{cout<<red;displayString("\n\n\t\tNo appointments created");cout<<white<<endl;getpass("\n\n\t\tPress <Enter> to go to Main menu");}
 

}
//////////////////////////////////////////////////////////////////////////////////////////
//Author			Nilesh Sarraf                                               //
//Date				17-08-2013                                                  //
//Name				View Appointment                                            //
//Description			It Retrieve all the appointment information from database   //
//Arguments			Appointment database class                                  //
//Returns			void                                                        //
//Notes				                                                     //
//Change History			                                                     //
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui::view_AppointmentDoctor(CAppointmentDB &a)
{

        vector <CAppointment> app_details;

        //string brid=pat.getBranchid();
	string did=pat.getDoctorID();
        app_details=a.dbselectAppointmentDoctor(did);
        if(app_details.size()!=0)
                display(app_details);
        else
                {cout<<red;displayString("\n\n\t\tNo appointments created");cout<<white;}


}

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Nilesh Sarraf                                           //
//Date				17-08-2013                                              //
//Name				Display                                                 //
//Description			It display all the appointments information             //
//Arguments			vector<CAppointment> app_details                        //
//Returns			void                                                    //
//Notes				                                                        //
//Change History			                                                //
//////////////////////////////////////////////////////////////////////////////////////////
void CPatientui::display(vector<CAppointment> app_details)
{
	
	system("clear");
	vector<CAppointment>::iterator Appiter;
	/*cout<<magenta<<"\n                                          ......Appointment Details......\n"<<white;
	cout<<magenta<<"\n         Appointment ID"<<"\t\t\t"<<"Patient ID"<<"\t\t"<<"Doctor ID"<<"\t\t"<<"Appointment Date"<<"\t\n";
	cout<<"        --------------------------------------------------------------------------------------------------"<<white;*/
	cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t             O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t       A P P O I N T M E N T   D E T A I L S  "<<white<<endl;
   cout<<yellow<<"\n\t\t     ========================================="<<white<<endl;

cout<<dcyan<<"\n\t"<<"__________________________________________________________________________"<<white<<endl;
cout<<magenta<<"\n\t Appointment ID"<<"\t\t"<<"Patient ID"<<"\t"<<"Doctor ID"<<"\t"<<"Appointment Date"<<"\n";
cout<<dcyan<<"\n\t"<<"__________________________________________________________________________"<<white<<endl;

     
/*     cout<<dcyan<<"\n\t"<<"______________________________________________________________________"<<white<<endl;
        cout<<magenta<<"\n\n\t ID\t\tBRANCH ID    \t\tNAME";
cout<<dcyan<<"\n\t"<<"_______________________________________________________________________"<<white<<endl;*/
	
	for(Appiter=app_details.begin();Appiter!=app_details.end();Appiter++)
           {
	    cout<<"\n          "<<(*Appiter).getAppointmentID()<<"\t\t"<<(*Appiter).getPatientID()<<"\t\t"<<(*Appiter).getDoctorID()<<"\t\t"<<(*Appiter).getApp_Date();
	   }
	cout<<endl<<"\n";
	getpass("\n\n\t\tPress <Enter> to go to Main menu");
}
