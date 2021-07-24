#pragma once
#ifndef _CUSERMGR_H_
#define _CUSERMGR_H_
#include<vector>
#include "Cuser.h"
using namespace std;
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

