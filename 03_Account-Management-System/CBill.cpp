#include "stdafx.h"
#include "CBill.h"
#include <fstream>
#include <sstream>

//知道上一次的余额和这一次的余额推测其他信息
CBill::CBill(double __bal, double __lastBal,
	bool __isN, std::string __n) :
	m_EIM(__lastBal - __bal > 0 ? Expense : Income),
	m_money(std::fabs(__lastBal - __bal)),
	m_isN(__isN), m_note(__n),
	m_balance(__bal),
	m_allCost(m_EIM == Expense ? m_money : 0),
	m_allIncome(m_EIM == Income ? m_money : 0) {}

//知道流通金额和收支模式推断其他信息
CBill::CBill(EIMODE __EIM, double __mon, 
	double __lastBal, bool __isN, std::string __n):
	m_EIM(__EIM),m_money(__mon),m_isN(__isN),m_note(__n)
{
	if (__EIM == Expense)
		m_balance = __lastBal - __mon,
		m_allCost = __mon, m_allIncome = 0;
	else if (__EIM == Income)
		m_balance = __lastBal + __mon,
		m_allCost = 0, m_allIncome = __mon;
	else
		m_balance = __lastBal,
		m_allCost = m_allIncome = 0;
}

//得到余额
double CBill::getBalance() const
{
	return m_balance;
}

//重载流运算符,使其可以直接写入文件
std::ofstream& operator<<(std::ofstream& __ofs, 
	CBill& __w)
{
	std::string EIMToStr;
	if (__w.m_EIM == Expense)
		EIMToStr = "支出";
	else if (__w.m_EIM == Income)
		EIMToStr = "收入";
	else
		EIMToStr = "-";
	std::string Necessary = __w.m_isN ? "必需" : "非必需";
	
	__ofs << std::fixed << EIMToStr << '\t'
		<< __w.m_money << '\t' << Necessary << '\t'
		<< __w.m_note << '\t' << __w.m_balance << '\t'
		<< __w.m_allCost << '\t' << __w.m_allIncome;

	return __ofs;
}

