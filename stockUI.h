#ifndef _stockUI_H
#define _stockUI_H
#include <vector>
#include"login.h"
#include "stock.h"
#include"stockdb.h"
using namespace std;
class CStockUI
{

public:
	void login(CStockdb &a);
	void addstock(CStockdb &a);
	void viewstock(CStockdb &a);
	int getOption();
	string enterDate();
	string calculateExpDate(int curday,int curmonth,int curyear);
	void displayError();
	void display(vector<CStock>);
	void displayString(char*);
	void setBrId(string);
	int displayMenu();	
};
#endif
