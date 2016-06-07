#pragma once
#include "CDateTime.h"
#include "CBill.h"

class CLine
{
protected:
	CDateTime m_now;
	std::string m_desc;
	CBill m_bill;
public:
	CLine(std::string & __desc, CBill & __b);

	//重载流运算符,以便将其直接写入文件
	friend std::ofstream & operator<<(std::ofstream& __ofs,
		CLine & __w);

};

