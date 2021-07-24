#pragma once
#ifndef _CUSER_H_
#define _CUSER_H_
#include <string.h>
class Cuser {
	char pszName[20];//保存名字
	char pszTel[20];//保存手机号
	char pszAddress[50];//保存地址
public:
	Cuser();
	Cuser(const char* TemPszName, const char* TemPszTel, const char* TemPszAdress);//拷贝函数
	~Cuser();
	char* getName() { return pszName; }
	char* getTel() { return pszTel; }
	char* getAddress() { return pszAddress; }
	void setName(const char* _input) { strcpy_s(pszName, _input); }
	void setTel(const char* _input) { strcpy_s(pszTel, _input); }
	void setAddress(const char* _input) { strcpy_s(pszAddress, _input); }
};
#endif //!_CUSER_H_