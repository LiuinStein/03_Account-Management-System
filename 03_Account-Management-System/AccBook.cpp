#include "stdafx.h"
#include "AccBook.h"
#include "FilePath.h"
#include <fstream>
#include <sstream>

//从字符串中获取余额
double CAccBook::getBalFromStr(std::string& __f)
{
	std::stringstream ss(__f);
	std::string tmp;
	for (int i = 0; i < 7; i++)
		ss >> tmp;
	double res{};
	ss >> std::fixed >> res;
	return res;
}

//根据账本操作代码打开账本,并写入余额
CAccBook::CAccBook(short __num) :
	m_operBook(__num), m_line(nullptr)
{
	std::ifstream load;
	load.open(AccountBooks[__num]);
	std::string tmp;
	while (load.good())
	{
		std::getline(load, tmp);
		load.get();
		if (load.peek() == '\n')
			break;
	}
	m_lastBal = getBalFromStr(tmp);
	load.close();
}

//通过信息创建CLine(资金以及流向)
void CAccBook::LineByMon(std::string & __desc, 
	EIMODE __eim, double __mon, bool __nece,
	std::string& __n)
{
	CBill tmp(__eim, __mon, m_lastBal,
		__nece, __n);
	m_line = new CLine(__desc, tmp);
}

//通过余额创建CLine
void CAccBook::LineByBal(std::string& __desc, 
	double __bal, bool __nece, std::string& __n)
{
	CBill tmp(__bal, m_lastBal, __nece, __n);
	m_line = new CLine(__desc, tmp);
}

//写入账本
void CAccBook::writeBook()const
{
	std::ofstream out;
	out.open(AccountBooks[m_operBook]);
	out << *m_line << std::endl;
	out.close();
}
