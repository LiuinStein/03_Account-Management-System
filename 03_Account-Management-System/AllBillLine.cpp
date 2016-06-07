#include "stdafx.h"
#include "AllBillLine.h"

CAllBillLine::CAllBillLine(std::string & __desc,
	CBill & __b, std::string __s1, std::string __s2) :
	CLine(__desc, __b), m_sheet1(__s1), m_sheet2(__s2) {}

std::ofstream& operator<<(std::ofstream& __ofs,
	CAllBillLine& __w)
{
	__ofs << __w.m_now << '\t' << __w.m_desc << '\t';
	__ofs << __w.m_bill << '\t' << __w.m_sheet1 << '\t'
		<< __w.m_sheet2 << std::endl;
	return __ofs;
}
