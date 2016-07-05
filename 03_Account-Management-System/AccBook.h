#pragma once
#include "Line.h"

class CAccBook
{
protected:
	short m_operBook;
	double m_lastBal;

	double getBalFromStr(std::string & __f);	//从字符串中获取余额
	
	CLine * m_line;

public:
	explicit CAccBook(short __num);	//根据账本操作代码打开账本,并写入余额

	//通过信息创建CLine(资金以及流向),返回流动的金额
	void LineByMon(std::string & __desc, EIMODE __eim,
		double __mon, bool __nece,
		std::string & __n);

	//通过余额创建CLine,返回流动的金额
	double LineByBal(std::string & __desc, double __bal,
		bool __nece, std::string & __n);

	//写入账本
	void writeBook()const;

};

