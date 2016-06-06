#pragma once
#include <fstream>

class CDateTime
{
private:
	int m_year;
	int m_mon;
	int m_day;
	int m_hour;
	int m_min;
	int m_sec;
public:
	CDateTime();

	friend std::ofstream& operator<<(std::ofstream & __ofs,
		CDateTime & __t);

};
