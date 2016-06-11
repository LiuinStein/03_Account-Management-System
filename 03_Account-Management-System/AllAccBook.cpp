#include "stdafx.h"
#include "AllAccBook.h"
#include "FilePath.h"


CAllAccBook::CAllAccBook() :CAccBook(0) {}

void CAllAccBook::setSheet(std::string& __s1, std::string& __s2)
{
	sheet_1 = __s1;
	sheet_2 = __s2;
}

void CAllAccBook::writeBook() const
{
	std::ofstream out;
	out.open(AccountBooks[m_operBook]);
	out << *m_line << sheet_1 << '\t' << sheet_2 << std::endl;
	out.close();
}
