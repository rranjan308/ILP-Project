#include"stockUI.h"
#include"stock.h"
#include"stockdb.h"
#include"login.h"
#include "maindb.h"
#include<vector>
#include<sstream>
#include "mainui.h"
#include<iostream>
#include"color.h"
using namespace std;





CStock cs;
void CStockUI::setBrId(string sbid)
{
cs.setBranchID(sbid);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Vyankatrao Sawant                                       //
//Date				18-08-2013                                              //
//Name				Date Validation                                         //
//Description			It validates the date that it is in proper format       //
//Arguments			                                                        //
//Returns			string                                                  //
//Notes				                                                        //
//Change History			                                                //
//////////////////////////////////////////////////////////////////////////////////////////


string CStockUI::enterDate()
{
string sdate;
ostringstream out;
char chdash1='-'; 
char chdash2='-';


time_t t = time(NULL);
struct tm tm = *localtime(&t);
int icurday=tm.tm_mday;
int icurmonth=tm.tm_mon+1;
int icuryear=tm.tm_year+1900;
out<<icurday<<chdash1<<icurmonth<<chdash2<<icuryear;
sdate=out.str();
string sexpdate,sfindate;
sexpdate=calculateExpDate(icurday,icurmonth,icuryear);
sfindate=sdate+"/"+sexpdate;
return sfindate;
}

string CStockUI::calculateExpDate(int icurday,int icurmonth,int icuryear)
{
	int iexpday,iexpmonth,iexpyear;
	iexpyear=icuryear;
	iexpday=icurday+35;
	string sexpdate;
	ostringstream out;
	char chdash1='-';
	char chdash2='-';	
	switch(icurmonth)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: {if(iexpday>31)
										{
										iexpmonth=icurmonth+1;
										iexpday=iexpday-31;
											if(iexpday>30)
											{
												iexpday=iexpday-30;
												iexpmonth=iexpmonth+1;
										
											}
										}
										out<<iexpday<<chdash1<<iexpmonth<<chdash2<<iexpyear;
										sexpdate=out.str();
										return sexpdate;
                                                        		break;
									}	
                                                        
		case 2: {if(iexpday>28)
				{
				iexpmonth=icurmonth+1;
                                iexpday=iexpday-28;
				}
				 out<<iexpday<<chdash1<<iexpmonth<<chdash2<<iexpyear;
                                  sexpdate=out.str();
                                  return sexpdate;
  						
        			break;}
case 4: case 6: case 9: case 11: {if(iexpday>30)
					{
						iexpmonth=icurmonth+1;
                                		iexpday=iexpday-30;
					}
				  out<<iexpday<<chdash1<<iexpmonth<<chdash2<<iexpyear;
                                  sexpdate=out.str();
                                  return sexpdate;
                                 break;}
default:cout<<red<<"\n\n\t\tEnter a valid date"<<white<<endl;

	}
}


//////////////////////////////////////////////////////////////////////////////////////////
//Author			Vyankatrao Sawant                                       //
//Date				17-08-2013                                              //
//Name				Add blood stock                                         //
//Description			It adds the all details of blood stock in database      //
//Arguments			Database class of stockdb                               //
//Returns			void                                                    //
//Notes				                                                        //
//Change History			                                                //
//////////////////////////////////////////////////////////////////////////////////////////


void CStockUI::addstock(CStockdb &a)
{
   cout<<yellow<<"\n\t\t           ====================================="<<white<<endl;
  cout<<magenta<<"\n\t\t                 O.P   D E P A R T M E N T           "<<white<<endl;
   cout<<yellow<<"\n\t\t           ====================================="<<white<<endl;
  cout<<magenta<<"\n\t\t              A D D   B L O O D   S T O C K         "<<white<<endl;
   cout<<yellow<<"\n\t\t           ====================================="<<white<<endl;
cout<<"\n\t\t";
	string sbgroup;
	string sQty;
	char ichoice[10];
	char ich1[10];
	int sbranch;
	int iflag;
	string sprice;
	string sdate,spdate,sedate;
	cout<<"\n\n\t\tEnter the following Details";
	cout<<yellow<<"\n\n\t\tAll fields are mandatory"<<white;
	cout<<"\n\n\t\tChoose Blood group from the following\n\n";
	cout<<magenta<<"\t\t------------------------------"<<white;
	cout<<yellow<<"\n\t\t********BLOOD GROUPS*********"<<white;
	cout<<magenta<<"\n\t\t------------------------------"<<white;
	cout<<magenta<<"\n\t\t------------------------------"<<white;
	cout<<cyan<<"\n\t\t1.O+"<<"\t\t\t2.A+"<<"\n\n\t\t3.B+"<<"\t\t\t4.AB+"<<"\n\n\t\t5.O-"<<"\t\t\t6.A-"<<"\n\n\t\t7.B-"<<"\t\t\t8.AB-"<<white;
	cout<<magenta<<"\n\t\t------------------------------"<<white;
	cout<<"\n\n\t\tChoice                      		     : ";
label1:	cin.getline(ichoice,10);
	int icount=strlen(ichoice);
	 while(!((icount==1) && ((ichoice[0]>48) && (ichoice[0]<57))))
        {
                cout<<red<<"\n\n\t\tInvalid blood group choice\n"<<white<<"\n\n\t\tChoice                      		     : ";

		goto label1;
        }
	
	switch(ichoice[0]-48)
	{
		case 1:
			{
				sbgroup="O+";
				break;
			}
		case 2:
			
                        {
                                sbgroup="A+";
                                break;
                        }
                case 3:
			
                        {
                                sbgroup="B+";
                                break;
                        }
                case 4:
			
                        {
                                sbgroup="AB+";
                                break;
                        }
                case 5:
			
                        {
                                sbgroup="O-";
                                break;
                        }
                case 6:
			
                        {
                                sbgroup="A-";
                                break;
                        }
                case 7:
			
                        {
                                sbgroup="B-";
                                break;
                        }
                case 8:
			
                        {
                                sbgroup="AB-";
                                break;
                        }
                default:
				cout<<red<<"\n\n\t\tInvalid Blood Group\n";
	}

	
	char b;	
	int flag;
	do
	{
	flag=0;
	cout<<"\n\n\t\tQuantity of Blood Stock     		     : ";
	getline(cin,sQty,'\n');
	for(int i=0;i<sQty.length();i++)
	{
		b=sQty[i];
		if(!((b>=48) && (b<=57)) || (b==46) ||(b==32))
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
                cout<<red<<"\n\n\t\tInvalid Quantity of blood stock"<<white;
        }while(flag==1);
	
        char c;
        int flag1;
        do{flag1=0;
	cout<<"\n\n\t\tPrice per packet(INR)"<<"\n\t\t(Note:Each packet includes 200ml)     	     :";
        getline(cin,sprice,'\n');
		
        for(int j=0;j<sprice.length();j++)
        {   
                c=sprice[j];
                if(!(((c>=48) && (c<=57)) || (c==46)))
                {
                        flag1=1;
                        break;
                }
		
	
        }	
        if(flag1==1)
		{
                cout<<red<<"\n\n\t\tInvalid price"<<white;
		
		}
		
        }while(flag1==1); 
        string branchid=cs.getBranchID();
	sdate=enterDate();
	string delimiter="/";
	spdate=sdate.substr(0,sdate.find(delimiter));
	sedate=sdate.substr((sdate.find(delimiter))+1,sdate.length());
	string id;	
	cs.setBloodGroup(sbgroup);
	cs.setBloodQuantity(sQty);
	cs.setPrice(sprice);
	cs.setDate(spdate);
	cs.setBranchID(branchid);
	cs.setExDate(sedate);
	id=a.genStockID();
	cs.setBloodStockID(id);
//	cin.ignore(255,'\n');
	do
	{
	cout<<yellow<<"\n\n\t\tDo you really want to add this stock of blood? (Press y or n) :"<<white;
	cin.getline(ich1,10);
	int icount1=strlen(ich1);
	if(icount1==1)
	{
	if((ich1[0] == 121) || (ich1[0] == 89))
	{
		iflag=1;
		system("clear");
		a.dbInsertStock(cs);
		
   cout<<yellow<<"\n\t\t           ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t                   O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t           ========================================="<<white<<endl;
		cout<<dgreen<<"\n\n\n"; 
 		 displayString("\t\tBlood Stock details added successfully");
		 cout<<white;
		cout<<"\n\n\n\t\tBlood Stock ID is : "<<yellow<<id<<white<<"\n\n";
		getpass("\n\t\tPress <Enter> to go to Main menu");
			

	}
	else if((ich1[0] == 110) || (ich1[0] == 78))
        {
                iflag=1;
		system("clear");
	cout<<yellow<<"\n\t\t           ========================================="<<white<<endl;
  cout<<magenta<<"\n\t\t                   O.P   D E P A R T M E N T        "<<white<<endl;
   cout<<yellow<<"\n\t\t           ========================================="<<white<<endl;

                cout<<red<<"\n\n\n\t\tBlood stock details not added"<<white<<endl<<endl;
                cout<<"\n\n\n";
                getpass("\t\tPress <Enter> To continue");
	}
	}
	else 
	{
		iflag=0;
		cout<<red<<"\n\n\t\tInvalid Choice";
	}
      	}while(iflag!=1);
}
void CStockUI::displayError()
{
cout<<red<<"\n\n\t\tError takes place"<<endl<<white;
}
	

//////////////////////////////////////////////////////////////////////////////////////////
//Author			Vyankatrao Sawant                                       //
//Date				17-08-2013                                              //
//Name				View Blood Stock                                        //
//Description			It Displays all the blood stock details                 //
//Arguments			Database class of stockdb                               //
//Returns			string                                                  //
//Notes				                                                        //
//Change History			                                                //
//////////////////////////////////////////////////////////////////////////////////////////


void CStockUI::viewstock(CStockdb &a)
{
	
	/*cout<<cyan<<"\n---------------------------------------------------------------------------------------------";
	cout<<"\n			******Welcome to view stock details*******";
	cout<<"\n\n-------------------------------------------------------------------------------------------------\n"<<white;*/
	/*cout<<yellow<<"\t\t===================================================================\n"<<white;
       cout<<magenta<<"\t\t          S W A S T I K   S U P E R   S P E C I A L I T Y          \n"<<white; 
		cout<<"\t\t===================================================================\n"<<white;
         cout<<cyan<<"\t\t||                                                               ||"<<endl;
                   <<"\t\t||                         WELCOME TO                            ||"<<endl
	            <<"\t\t||							            ||"<<endl
	            <<"\t\t||                   OUT PATIENT DEPARTMENT                      || \n"
	            <<"\t\t||							       	    || \n"
	            <<"\t\t||                    BLOOD STOCK MANAGEMENT                     || \n"
	            <<"\t\t||								    || \n"<<white;
	cout<<yellow<<"\t\t===================================================================\n\n";
                
		cout<<"\t\t===================================================================\n\n"<<white;*/


	vector <CStock> blood_records;
	blood_records=a.dbSelectStock();
	if(blood_records.size()!=0)
		display(blood_records);
	else
		displayString("\n\n\t\tBlood Stock record Found");
}
void CStockUI::display(vector<CStock> blood_records)
{
	system("clear");
	vector<CStock>::iterator stockiter;
   cout<<yellow<<"\n\t\t              ======================================="<<white<<endl;
  cout<<magenta<<"\n\t\t                     O.P   D E P A R T M E N T       "<<white<<endl;
   cout<<yellow<<"\n\t\t              ======================================="<<white<<endl;
  cout<<magenta<<"\n\t\t               B L O O D   S T O C K   D E T A I L S "<<white<<endl;
   cout<<yellow<<"\n\t\t              ======================================="<<white<<endl;

	cout<<"\n"<<cyan<<"___________________________________________________________________________________________"<<white;
	cout<<"\n\n"<<magenta<<"Blood Group"<<"\t"<<"Stock Id"<<"\t"<<"Stock Quantity"<<"\t"<<"Price/packet"<<"  "<<"Packaging Date"<<"\t"<<"Expiry Date"<<white;
	cout<<"\n"<<cyan<<"___________________________________________________________________________________________\n"<<white;
	for(stockiter=blood_records.begin();stockiter!=blood_records.end();stockiter++)
		cout<<"\n"<<(*stockiter).getBloodGroup()<<"\t\t"<<(*stockiter).getBloodStockID()<<"\t"<<(*stockiter).getBloodQuantity()<<"\t\t"<<"Rs."<<(*stockiter).getPrice()<<"\t\t"<<(*stockiter).getDate()<<"       "<<(*stockiter).getExDate()<<endl;
cout<<endl<<endl;
getpass("\t\tPress <Enter> to continue");
}


//////////////////////////////////////////////////////////////////////////////////////////
//Author			Naznin Malek,Vyankatrao Sawant                          //
//Date				18-08-2013                                              //
//Name				Display Menu                                            //
//Description			It displays the main menu                               //
//Arguments			                                                        //
//Returns			int                                                     //
//Notes				                                                 //
//Change History			                                                 //
//////////////////////////////////////////////////////////////////////////////////////////


int CStockUI::displayMenu()
{
	cin.ignore(255,'\n');
	system("clear");
	int ichoice;
	CStockUI ui;
	CMainUI mui;
	CDatabase mdb;
	CStockdb data;
	
   	cout<<yellow<<"\n\t\t===================================================================\n"<<white;
       cout<<magenta<<"\t\t          S W A S T I K   S U P E R   S P E C I A L I T Y          \n"<<white; 
		cout<<yellow<<"\t\t===================================================================\n"<<white;
         cout<<cyan<<"\t\t||                                                               ||"<<endl
                   <<"\t\t||                         WELCOME TO                            ||"<<endl
	            <<"\t\t||							         ||"<<endl
	            <<"\t\t||                   OUR PATIENT DEPARTMENT                      || \n"
	            <<"\t\t||							       	 || \n"
	            <<"\t\t||                    BLOOD STOCK MANAGEMENT                     || \n"
	            <<"\t\t||								 || \n"<<white;
	cout<<yellow<<"\t\t===================================================================\n\n";
                
		cout<<"\t\t===================================================================\n\n"<<white;



	cout<<"\n\n\t\t 1. Add Blood Stock Details.";
   	cout<<"\n\n\t\t 2. Display Blood Stock Details.";
   	cout<<"\n\n\t\t 3. Logout.";
	cout<<"\n\n\t\t 4. Exit the System.";

	do
	{
		ichoice=ui.getOption();
                switch(ichoice)
                        {
                                case 1:
                                        {
                                                system("clear");
                                                ui.addstock(data);
                                                break;
                                        }

                                case 2:
                                {
                                                system("clear");
                                                ui.viewstock(data);
                                                break;
                                }
					case 3:{mui.login(mdb);break;}
                                case 4:
                                                exit(0);
                                default:
                                         ui.displayString("You have given a invalid option ");
          }

         ui.displayMenu();
        
        }while(ichoice!=4);

}



int CStockUI::getOption()
{
	char ichoice[10];
    	cout<<white<<"\n\n\t\tEnter your Choice (1-4) : ";
label:	cin.getline(ichoice,10);
	while(!((strlen(ichoice)==1) && (ichoice[0]>48) && (ichoice[0]<=52)))
	{
	cout<<red<<"\n\n\t\tInvalid choice"<<white<<"\n\n\t\tEnter your choice (1-4) : ";
	goto label;
	}
	int ch1=ichoice[0]-48;
    	return ch1;
}

void CStockUI::displayString(char* mesg)
{
	cout<<mesg<<"\n";
}

