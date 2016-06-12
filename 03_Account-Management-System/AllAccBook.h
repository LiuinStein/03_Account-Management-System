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

	void setSheet(const char * __s1,
		const char * __s2 = "��");

	//д���˱�
	void writeBook()const;

	//�õ���һ�ε����
	double getLastBal()const;

};

