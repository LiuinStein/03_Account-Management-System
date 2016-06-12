#include "stdafx.h"
#include "CDateTime.h"
#include <ctime>

//默认构造函数,用于获取当前时间
CDateTime::CDateTime()
{
	time_t NowTimeLong = time(NULL);
	tm * NowTime = localtime(&NowTimeLong);
	m_year = NowTime->tm_year + 1900;
	m_mon = NowTime->tm_mon + 1;
	m_day = NowTime->tm_mday;
	m_hour = NowTime->tm_hour;
	m_min = NowTime->tm_min;
	m_sec = NowTime->tm_sec;
}

//重载流运算符,实现直接写入文件
std::ofstream& operator<<(std::ofstream& __ofs, 
	CDateTime& __t)
{
	__ofs << __t.m_year << "年" << __t.m_mon << "月" << __t.m_day << "日"
		<< '\t' << __t.m_hour << ':';
	//
	if (__t.m_min < 10)
		__ofs << '0' << __t.m_min << ':';
	else
		__ofs << __t.m_min << ':';

	if (__t.m_sec < 10)
		__ofs << '0' << __t.m_sec;
	else
		__ofs << __t.m_sec;

	return __ofs;
}
