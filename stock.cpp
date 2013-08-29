#include"stock.h"
CStock::CStock(){}
string CStock::getBloodGroup()
{
	return m_sBloodGroup;
}

void  CStock::setBloodGroup(string sbloodgroup)
{
	m_sBloodGroup=sbloodgroup;
}
string  CStock::getBloodQuantity()
{
	return m_sQuantity;
}
void CStock::setBloodQuantity(string quantity)
{
	m_sQuantity=quantity;
}
string CStock::getPrice()
{
	return m_sPrice;
}
void CStock::setPrice(string price)
{
	m_sPrice=price;
}
string CStock::getDate()
{
	return m_sDate;
}


void CStock::setDate(string date)
{
	m_sDate=date;
}
string CStock::getExDate()
{
        return m_sExDate;
}


void CStock::setExDate(string date)
{
        m_sExDate=date;
}
string CStock::getBranchID()
{
	return m_iBranchID;
}
void CStock::setBranchID(string branch)
{
	m_iBranchID=branch;
}
string CStock::getBloodStockID()
{
	return m_sStockID;
}
void CStock::setBloodStockID(string id)
{
	m_sStockID=id;	
}

