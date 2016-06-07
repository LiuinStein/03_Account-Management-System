#pragma once
#include <string>

//收支模式
enum EIMODE
{
	Expense, Income, Flow
};

class CBill
{
private:
	EIMODE m_EIM;
	double m_money;
	bool m_isN;
	std::string m_note;
	double m_balance;
	double m_allCost;
	double m_allIncome;
public:

	//知道上一次的余额和这一次的余额推测其他信息
	CBill(double __bal, double __lastBal,
		bool __isN = true, std::string __n = "无");

	//知道流通金额和收支模式推断其他信息
	CBill(EIMODE __EIM, double __mon, double __lastBal,
		bool __isN = true, std::string __n = "无");
	
	//得到余额
	double getBalance()const;	

	//重载流运算符,使其可以直接写入文件
	friend std::ofstream& operator<<(std::ofstream& __ofs, CBill & __w);

};
