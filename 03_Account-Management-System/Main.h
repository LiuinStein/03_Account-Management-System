#pragma once
#include <string>

//主启动操作类
class Main
{
private:
	short m_operBillNum;	//操作账本编号[1,8]
	short m_operBill2Num;	//为内部资金流通设置的第二账本编号
	short m_operMode;		//账本操作码
	std::string log;		//日志

	void printAccBook();	//输出账本清单

	void printOperMode();	//输出账本操作模式

	std::string inputDesc();	//获取账本说明

	bool useDefTemp();		//是否使用默认模板(必需和备注)

	void useDIYTemp(std::string * __nec,
		std::string * __note);	//使用自定义必需和备注模板

	bool finallyConfirm();	//向用户的最终确认

	void doSomethingElse();	//干点别的

	void createdByMon();	//通过资金以及流向创建

	void createdByBal();	//通过余额创建

	void createdByFlow();	//内部资金流通模式

	void mappingOperMode();	//映射操作模式

	void main();	//用来干点别的

public:

	Main();

	//得到区间数[__s,__e]
	static short inputNum(short __s, short __e,
		const char * InputError = nullptr);

};
