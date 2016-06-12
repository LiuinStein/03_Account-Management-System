#include "stdafx.h"
#include "AllAccBook.h"
#include "FilePath.h"


CAllAccBook::CAllAccBook() :CAccBook(0) {}

void CAllAccBook::setSheet(const char * __s1, const char * __s2)
{
	sheet_1 = __s1;
	sheet_2 = __s2;
}

void CAllAccBook::writeBook() const
{
	std::ofstream out;
	out.open(AccountBooks[0],std::ios::app);
	out << *m_line << '\t'
		<< sheet_1 << '\t' << sheet_2 << std::endl;
	out.close();
}

//得到上一次的余额
double CAllAccBook::getLastBal() const
{
	return m_lastBal;
}
