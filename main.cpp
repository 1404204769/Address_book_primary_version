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
void productData(int num) {
	clock_t start, finish; //声明start和finish是两个时间
	double time; //定义运行时间
	start = clock(); //获取开始时间
	cout << "随机生成"<<num<<"人的数据" << endl;
	for (int i = 0; i < num; i++) {
		gUser = gcusermgr.GetUser();
		cout << i+1 << ".\tname:" << gUser.getName() << "\tTel:" << gUser.getTel() << "\tAddress:" << gUser.getAddress() << endl;
		gcusermgr.AddUser(gUser);
	}
	finish = clock();
	printf("\n");
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("RunningTime:\n%f 秒\n", time);//显示
}
int choice() {
	cout << "请输入要执行的功能" << endl;
	cout << "0.退出程序" << endl;
	cout << "1.显示所有人的姓名" << endl;
	cout << "2.查询指定姓名" << endl;
	cout << "3.输入新的数据" << endl;
	cout << "4.随机产生数据" << endl;
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
	case 4: {
		cout << "请输入要产生多少条数据" << endl;
		cin >> choice;
		productData(choice);
	}break;
	default:
		return 0;
		break;
	}
	return choice;
}
int main() {
	while (1) {
		system("cls");
		cout << "欢迎使用李志诚的通讯录" << endl;
		if (choice() == 0)
			break;
		system("pause");
	}
	return 0;
}