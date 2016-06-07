#include "stdafx.h"
#include "Main.h"
#include <iostream>
#include <string>
#include <sstream>
#include "CBill.h"
#include "FilePath.h"

//输出账本清单
void Main::printAccBook()
{
	std::cout << "There are 8 Account books:" << std::endl;
	std::cout << "1. 现金日记账.xls" << std::endl
		<< "2. 京东金融投资.xls" << std::endl
		<< "3. 余额宝.xls" << std::endl
		<< "4. 建行尾号4852.xls" << std::endl
		<< "5. 工行尾号9776.xls" << std::endl
		<< "6. 工行尾号8261.xls" << std::endl
		<< "7. 工行尾号6525.xls" << std::endl
		<< "8. 校园卡日记账.xls" << std::endl;
}

//输出账本操作模式
void Main::printOperMode()
{
	std::cout << "There are three operate mode:" << std::endl
		<< "1. Manual entry" << std::endl
		<< "2. Create by balance" << std::endl
		<< "3. Flow of fund" << std::endl;
}

//获取账本说明
std::string Main::inputDesc()
{
	std::string res;
	std::cout << "Choose a Income/Expense description in this option:" << std::endl;
	std::cout << "Default option: 1. 饭 2. 内部资金流通 3. 父母给 4. New description" << std::endl;
	std::cout << "Enter a option number: ";
	int descNum{ inputNum(1, 4) };
	if (descNum == 1)
		res = "饭";
	else if (descNum == 2)
		res = "内部资金流通";
	else if (descNum == 3)
		res = "父母给";
	else if (descNum == 4)
	{
		int tmp{};
		std::cout << "Enter a new description: ";
		do
		{
			std::cin >> res;
			std::cout << "Confirm your type: " << res << std::endl;
			std::cout << "Type 1 to apply,type 0 to rewrite: ";
			tmp = inputNum(0, 1);
		} while (tmp == 0);
	}
	return res;
}

//是否使用默认模板(必需和备注)
bool Main::useDefTemp()
{
	std::cout << "Do you want to use the default note and necessary template?" << std::endl;
	std::cout << "If you want type 1 else type 2: ";
	return inputNum(1, 2) == 1;
}

//使用自定义必需和备注模板
void Main::useDIYTemp(std::string* __nec, 
	std::string* __note)
{
	std::cout << "Is it necessary to use the money?" << std::endl;
	std::cout << "Type 1 is necessary,0 is unnecessary: ";
	*__nec = inputNum(0, 1) == 1 ? "必需" : "非必需";
	std::cout << "Type your note: ";
	do
	{
		std::cin >> *__note;
		std::cout << "Your new note is " << *__note << std::endl;
		std::cout << "Type 1 to apply,0 to rewrite: ";
	} while (inputNum(0, 1) == 0);
}

//向用户的最终确认
bool Main::finallyConfirm()
{
	std::cout << "!!!FINALLY INFORMATION CONFIRM!!!" << std::endl;
	std::cout << "You has changed the following account book(s): " << std::endl;
	std::cout << "1: " << AccountBooks[m_operBillNum] << std::endl;
	if (m_operMode == 3)	//针对内部资金流通情况的第二账本
		std::cout << "2: " << AccountBooks[m_operBillNum] << std::endl;
	std::cout << "You has made these changes:" << std::endl;
	std::cout << log << std::endl;
	std::cout << "Are you ABSOLUTELY sure?" << std::endl;
	std::cout << "Type 1 to apply this changes,type 0 to cancel" << std::endl;
	std::cout << "Now, type your choose: ";
	return inputNum(0, 1) == 1;
}

//干点别的
void Main::doSomethingElse()
{
	std::cout << "Do you want to do something else?" << std::endl;
	std::cout << "Type 1 to do something else, type 0 to exit" << std::endl;
	std::cout << "Type a option: ";
	inputNum(0, 1) == 1 ? main() : exit(0);
}

//通过资金以及流向创建
void Main::createdByMon()
{
	std::string desc = inputDesc();	//账本说明
	//收支情况
	std::cout << "Expense or Income(1 or 2): ";
	EIMODE eim = inputNum(1, 2) == 1 ?
		Expense : Income;
	//输入计算金额数量
	double mon{};
	std::cout << "Enter the money: ";
	std::cin >> mon;	
	//模板的使用(备注和必需)
	std::string necessary;
	std::string note;
	if (useDefTemp())
		necessary = "必需",
		note = "无";
	else
		useDIYTemp(&necessary, &note);
	//记录日志
	std::stringstream ss;
	ss << std::fixed
		<< (eim == Expense ? "Expense ￥" : "Income ￥")
		<< mon << "in " << AccountBooks[m_operBillNum];
	log = ss.str();
	//用户确认
	if (finallyConfirm())
		//TODO: 通过确认的情况
		;
	//是否干点别的
	doSomethingElse();
}

//通过余额创建
void Main::createdByBal()
{
	std::string desc = inputDesc();
	double bal{};
	std::cout << "Enter new balance: ";
	std::cin >> bal;
	//是否使用默认模板
	std::string necessary;
	std::string note;
	if (useDefTemp())
		necessary = "必需",
		note = "无";
	else
		useDIYTemp(&necessary, &note);
	//记录日志
	std::stringstream ss;
	ss << std::fixed
		<< "Refresh the balance.New balance is " << bal;
	log = ss.str();
	//用户确认
	if (finallyConfirm())
		//TODO: 通过确认的情况
		;
	//是否干点别的
	doSomethingElse();
}

//通过内部资金流通创建
void Main::createdByFlow()
{
	std::cout << "Enter receipt account book: ";
	m_operBill2Num = inputNum(1, 8, "Receipt account book number error!");
	//录入流通的资金数
	std::cout << "Enter the flow money: ";
	double mon{};
	std::cin >> mon;
	//是否使用默认模板
	std::string necessary;
	std::string note;
	if (useDefTemp())
		necessary = "必需",
		note = "无";
	else
		useDIYTemp(&necessary, &note);
	//记录日志
	std::stringstream ss;
	ss << std::fixed
		<< "Total of ￥" << mon << "is flowing from \""
		<< AccountBooks[m_operBillNum] << "\" to \""
		<< AccountBooks[m_operBill2Num] << "\"";
	log = ss.str();
	//用户确认
	if (finallyConfirm())
		//TODO: 通过确认的情况
		;
	//是否干点别的
	doSomethingElse();

}

//映射操作模式(分流)
void Main::mappingOperMode()
{
	if (m_operMode == 1)
		createdByMon();
	else if (m_operMode == 2)
		createdByBal();
	else
		createdByFlow();
}

//用来干点别的
void Main::main()
{
	//主程序界面
	system("cls");
	std::cout << "Welcome to lyst Account book management system" << std::endl;

	printAccBook();		//输出可以操作的账本
	//输入要操作的账本
	std::cout << "Choose one to operate: ";
	m_operBillNum = inputNum(1, 8, "Account book number error! ");

	printOperMode();	//输出账本操作模式
	//输入账本操作模式
	std::cout << "Enter an operate mode: ";
	m_operMode = inputNum(1, 3, "Operate mode error!");
	//分流
	mappingOperMode();
}

Main::Main()
{
	//欢迎界面:
	std::cout << "Welcome to lyst Account book management system" << std::endl;
	std::cout << "Enter Password: ";

	//密码验证部分
	char key[21]{};
	bool keyCorrect;
	do
	{
		for (int i = 0; i < 21; i++)
		{
			std::cin >> key[i];
			std::cout << '\b' << '*';
			if (key[i] == char(13))
			{
				key[i] = '\0';
				break;
			}
		}
		keyCorrect = std::strcmp(key, "1021") == 0;
		if (!keyCorrect)
		{
			std::cout << "Password Error!" << std::endl;
			std::cout << "Enter Password again: ";
		}
	} while (!keyCorrect);

	main();
}

//得到区间数[__s,__e]
short Main::inputNum(short __s, short __e, const char * InputError)
{
	short result{};
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

