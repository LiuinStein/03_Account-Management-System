#pragma once
#include "Line.h"

class CAccBook
{
protected:
	short m_operBook;
	double m_lastBal;

	double getBalFromStr(std::string & __f);	//���ַ����л�ȡ���
	
	CLine * m_line;

public:
	explicit CAccBook(short __num);	//�����˱�����������˱�,��д�����

	//ͨ����Ϣ����CLine(�ʽ��Լ�����),���������Ľ��
	void LineByMon(std::string & __desc, EIMODE __eim,
		double __mon, bool __nece,
		std::string & __n);

	//ͨ������CLine,���������Ľ��
	double LineByBal(std::string & __desc, double __bal,
		bool __nece, std::string & __n);

	//д���˱�
	void writeBook()const;

};

