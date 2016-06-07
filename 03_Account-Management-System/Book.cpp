#include "stdafx.h"
#include "Book.h"
#include <fstream>
#include <sstream>
#include "FilePath.h"
#include <iostream>

//ֱ�Ӵ����ж������
double CBook::getBalFromStr(std::string& __f)
{
	std::string tmp;
	std::stringstream ss(__f);
	for (int i = 0; i < 7; i++)
		ss >> tmp;
	double res{};
	ss >> res;
	return res;
}

//����ͨ����
void CBook::createByMon()
{

}

//������
void CBook::createByBal()
{
}

//�ڲ��ʽ���ͨ
void CBook::createByFlow()
{
}

//����������
short CBook::inputNumber(int __s, int __e, const char* InputError)
{
	int result{};
	do
	{
		std::cin >> result;
		if (result < __s || result > __e)
			if (InputError == nullptr)
				std::cout << "Type error! You must type a number range of ["
				<< __s << "," << __e << "]" << std::endl
				<< "Type again: ";
			else
				std::cout << *InputError << std::endl
				<< "Type again: ";
	} while (result < __s || result > __e);
	return result;
}

//¼���˱�˵��
std::string CBook::inputDesc()
{
	std::string res;
	std::cout << "Choose a Income/Expense description in this option:" << std::endl;
	std::cout << "Default option: 1. �� 2. �ڲ��ʽ���ͨ 3. ��ĸ�� 4. New description" << std::endl;
	std::cout << "Enter a option number: ";
	short inp = inputNumber(1, 4, "Option number error!");
	if (inp == 4)	//DIY
	{
		short chs{};
		do
		{
			std::cin >> res;
			std::cout << "Confirm your description?" << std::endl;
			std::cout << "Type 1 to apply,0 to cancel: ";
			chs = inputNumber(0, 1);
		} while (chs == 0);
		return res;
	}
	else if (inp == 1)
		res = "��";
	else if (inp == 2)
		res = "�ڲ��ʽ���ͨ";
	else if (inp == 3)
		res = "��ĸ��";
	return res;
}

//�����˱���ź��˱������������˱�
CBook::CBook(short __bn, short __om) :
	m_isAllBill(__bn == 0), m_operMode(__om),
	m_wLine(nullptr),m_wABLine(nullptr)
{
	std::ifstream load;
	load.open(AccountBooks[__bn]);
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
