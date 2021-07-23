#define _CRT_SECURE_NO_WARNINGS
#include "CuserMgr.h"
#include <iostream>
Cuser::Cuser() {
	memset(pszName, 0, sizeof(pszName));
	memset(pszTel, 0, sizeof(pszTel));
	memset(pszAddress, 0, sizeof(pszAddress));
}
Cuser::Cuser(const char* TemPszName, const char* TemPszTel, const char* TemPszAdress) {
	strcpy(pszName, TemPszName);
	strcpy(pszTel, TemPszTel);
	strcpy(pszAddress, TemPszAdress);
}
Cuser::~Cuser() {}
CuserMgr::CuserMgr() {
	VecByTel.clear();
	readInfoFromFile();
}
bool CuserMgr::checkTel(char* _inputTel) {
	//用于检查手机号是否规范，并且判断是否存在重复手机号
	size_t nLen = strlen(_inputTel);
	if (nLen != 11) {
		cout << "手机号位数不正确，请重新输入" << endl;
		return false;
	}
	else {
		for (char* c = _inputTel; *c != 0; c++) {
			if (*c <= '9' && *c >= '0')continue;
			else {
				cout << "手机号内存在非数字，请重新输入" << endl;
				return false;
			}
		}
	}
	return true;

}
Cuser CuserMgr::GetUser() {
	//用于生成随机数据
	Cuser TemUser = Cuser();
	return TemUser;
}
bool CuserMgr::AddUser(Cuser _input) {
	//用于将数据添加到VecByTel数组内
	VecByTel.push_back(_input);
	return true;
}
bool CuserMgr::saveInfoToFile() {
	//文件写操作
	FILE* fp = fopen(filename, "w");
	for (vector<Cuser>::iterator it = VecByTel.begin(); it != VecByTel.end(); ++it) {
		fprintf(fp, "%s\t%s\t%s\n", it->getName(), it->getTel(), it->getAddress());
	}
	fclose(fp);
	return true;
}
bool CuserMgr::readInfoFromFile() {
	//文件读操作
	char* TemPszAddress = new char[50];//创建临时的数据存储位
	char* TemPszName = new char[20];
	char* TemPszTel = new char[20];
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w+");
	}
	while (fscanf(fp, "%s\t%s\t%s\n", TemPszName, TemPszTel, TemPszAddress) != EOF) {
		Cuser TemUser(TemPszName, TemPszTel, TemPszAddress);
		AddUser(TemUser);
		memset(TemPszName, 0, sizeof(TemPszName));
		memset(TemPszTel, 0, sizeof(TemPszTel));
		memset(TemPszAddress, 0, sizeof(TemPszAddress));
	}
	fclose(fp);
	delete[]TemPszAddress;//及时销毁释放内存
	delete[]TemPszName;
	delete[]TemPszTel;
	return true;
}
void CuserMgr::showName() {
	if (VecByTel.empty()) {
		cout << "当前无数据" << endl;
		return;
	}
	cout << "通讯录数据如下" << endl;
	//打印输出所有的现存的名字
	for (vector<Cuser>::iterator it = VecByTel.begin(); it != VecByTel.end(); ++it) {
		cout << it->getName() << "\t" << endl;
	}
	cout << "数据输出完毕" << endl;
}
void CuserMgr::showDetailByName(const char* _searchName) {
	//输入用户的名字查询对应的信息
	bool _findByName = false;
	for (vector<Cuser>::iterator it = VecByTel.begin(); it != VecByTel.end(); ++it) {
		if (strcmp(it->getName(), _searchName) == 0) {
			cout << "name:" << it->getName() << endl;
			cout << "Tel:" << it->getTel() << endl;
			cout << "Address:" << it->getAddress() << endl;
		}
	}
	if (_findByName) {
		cout << "数据输出完毕" << endl;
	}
	else {
		cout << "未找到此人的信息" << endl;
	}
}