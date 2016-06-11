#include "stdafx.h"
#include "Line.h"


CLine::CLine(std::string& __desc, CBill& __b) :
	m_now(), m_desc(__desc), m_bill(__b) {}

std::ofstream& operator<<(std::ofstream& __ofs,
	CLine& __w)
{
	__ofs << __w.m_now << '\t' << __w.m_desc << '\t';
	__ofs << __w.m_bill;
	return __ofs;
}
