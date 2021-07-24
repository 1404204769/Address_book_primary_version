#pragma once
#ifndef _CUSERMGR_H_
#define _CUSERMGR_H_
#include<vector>
using namespace std;
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
	void setName(const char* _input) { strcpy(pszName, _input); }
	void setTel(const char* _input) { strcpy(pszTel, _input); }
	void setAddress(const char* _input) { strcpy(pszAddress, _input); }
};
class CuserMgr {
	const char* const filename = "UserDatabase.txt";//用于保存数据的文件，不可以更改
	vector<Cuser>VecByTel;//使用手机号作为索引，因为名字可能一样但是手机号不可能一样
public://内部的逻辑函数
	CuserMgr(); 
	~CuserMgr();
	bool checkTel(const char* _inputTel);//用于检查手机号是否规范，并且判断是否存在重复手机号
	Cuser GetUser();//用于生成随机数据
	bool AddUser(Cuser _input);//用于将数据添加到VecByTel数组内
	bool saveInfoToFile();//文件写操作
	bool readInfoFromFile();//文件读操作
	void showName();//打印输出所有的现存的名字
	void showDetailByName(const char* _searchName);//输入用户的名字查询对应的信息
};
#endif // !_CUSERMGR_H_

