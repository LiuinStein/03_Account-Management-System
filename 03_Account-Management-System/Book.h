#pragma once
#include "CBill.h"
#include "Line.h"
#include "AllBillLine.h"

class CBook
{
private:
	CLine * m_wLine;			//写入行
	CAllBillLine * m_wABLine;	//为总账准备的
	bool m_isAllBill;			//是不是总账
	double m_lastBal;			//上一次的余额
	short m_operMode;			//账本操作码
	std::string m_log;			//日志
	
	//直接从行中读入余额
	double getBalFromStr(std::string & __f);

	//由流通金额创建
	void createByMon();

	//由余额创建
	void createByBal();

	//内部资金流通
	void createByFlow();

	//输入区间数
	static short inputNumber(int __s, int __e,
		const char * InputError = nullptr);

	//录入账本说明
	std::string inputDesc();
	
public:
	//根据账本编号和账本操作码来打开账本
	CBook(short __bn, short __om);

	

};

