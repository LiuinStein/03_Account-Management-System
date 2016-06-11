#include "stdafx.h"
#include "AccBook.h"
#include "FilePath.h"
#include <fstream>
#include <sstream>

//���ַ����л�ȡ���
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

//�����˱�����������˱�,��д�����
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

//ͨ����Ϣ����CLine(�ʽ��Լ�����)
void CAccBook::LineByMon(std::string & __desc, 
	EIMODE __eim, double __mon, bool __nece,
	std::string& __n)
{
	CBill tmp(__eim, __mon, m_lastBal,
		__nece, __n);
	m_line = new CLine(__desc, tmp);
}

//ͨ������CLine
void CAccBook::LineByBal(std::string& __desc, 
	double __bal, bool __nece, std::string& __n)
{
	CBill tmp(__bal, m_lastBal, __nece, __n);
	m_line = new CLine(__desc, tmp);
}

//д���˱�
void CAccBook::writeBook()const
{
	std::ofstream out;
	out.open(AccountBooks[m_operBook]);
	out << *m_line << std::endl;
	out.close();
}
