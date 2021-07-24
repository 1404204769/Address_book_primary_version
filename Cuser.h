#pragma once
#ifndef _CUSER_H_
#define _CUSER_H_
#include <string.h>
class Cuser {
	char pszName[20];//��������
	char pszTel[20];//�����ֻ���
	char pszAddress[50];//�����ַ
public:
	Cuser();
	Cuser(const char* TemPszName, const char* TemPszTel, const char* TemPszAdress);//��������
	~Cuser();
	char* getName() { return pszName; }
	char* getTel() { return pszTel; }
	char* getAddress() { return pszAddress; }
	void setName(const char* _input) { strcpy_s(pszName, _input); }
	void setTel(const char* _input) { strcpy_s(pszTel, _input); }
	void setAddress(const char* _input) { strcpy_s(pszAddress, _input); }
};
#endif //!_CUSER_H_