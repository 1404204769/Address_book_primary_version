#define _CRT_SECURE_NO_WARNINGS
#include "CuserMgr.h"
#include<iostream>
using namespace std;
CuserMgr gcusermgr;
Cuser gUser;
char gc[50];
Cuser input() {
	char temc[50];
	Cuser temUser;
	cout << "请输入姓名：" << endl;
	cin >> temc;
	temUser.setName(temc);
	cout << "请输入电话：" << endl;
	cin >> temc;
	while (!gcusermgr.checkTel(temc)) {
		cout << "请重新输入电话：" << endl;
		cin >> temc;
	}
	temUser.setTel(temc);
	cout << "请输入地址：" << endl;
	cin >> temc;
	temUser.setAddress(temc);
	return temUser;
}
int choice() {
	cout << "请输入要执行的功能" << endl;
	cout << "1.显示所有人的姓名" << endl;
	cout << "2.查询指定姓名" << endl;
	cout << "3.添加新的数据" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		gcusermgr.showName();
		break;
	case 2: {
		cout << "请输入要查询的对象的名字" << endl;
		cin >> gc;
		gcusermgr.showDetailByName(gc);
	}break;
	case 3: {
		gUser = input();
		gcusermgr.AddUser(gUser);
		//gcusermgr.showName();
	}break;
	default:
		return 0;
		break;
	}
	return choice;
}
int main1() {
	while (1) {
		system("cls");
		cout << "欢迎使用李志诚的通讯录" << endl;
		if (choice() == 0)
			break;
		system("pause");
	}
	return 0;
}