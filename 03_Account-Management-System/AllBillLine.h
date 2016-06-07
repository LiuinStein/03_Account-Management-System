#pragma once
#include "Line.h"
class CAllBillLine :
	public CLine
{
private:
	std::string m_sheet1;
	std::string m_sheet2;
public:
	CAllBillLine(std::string & __desc, CBill & __b,
		std::string __s1, std::string __s2 = "нч");

	friend std::ofstream & operator<<(std::ofstream& __ofs,
		CAllBillLine & __w);

};

