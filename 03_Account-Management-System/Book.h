#pragma once
#include "CBill.h"
#include "Line.h"
#include "AllBillLine.h"

class CBook
{
private:
	CLine * m_wLine;			//д����
	CAllBillLine * m_wABLine;	//Ϊ����׼����
	bool m_isAllBill;			//�ǲ�������
	double m_lastBal;			//��һ�ε����
	short m_operMode;			//�˱�������
	std::string m_log;			//��־
	
	//ֱ�Ӵ����ж������
	double getBalFromStr(std::string & __f);

	//����ͨ����
	void createByMon();

	//������
	void createByBal();

	//�ڲ��ʽ���ͨ
	void createByFlow();

	//����������
	static short inputNumber(int __s, int __e,
		const char * InputError = nullptr);

	//¼���˱�˵��
	std::string inputDesc();
	
public:
	//�����˱���ź��˱������������˱�
	CBook(short __bn, short __om);

	

};

