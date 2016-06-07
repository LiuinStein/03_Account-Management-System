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

	//�����������,�Ա㽫��ֱ��д���ļ�
	friend std::ofstream & operator<<(std::ofstream& __ofs,
		CLine & __w);

};

