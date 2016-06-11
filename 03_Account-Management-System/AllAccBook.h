#pragma once
#include "AccBook.h"
#include "AllBillLine.h"

class CAllAccBook :
	public CAccBook
{
private:
	std::string sheet_1;
	std::string sheet_2;
public:
	CAllAccBook();

	void setSheet(std::string & __s1, std::string & __s2);

	//–¥»Î’À±æ
	void writeBook()const;

};

