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
	cout << "������������" << endl;
	cin >> temc;
	temUser.setName(temc);
	cout << "������绰��" << endl;
	cin >> temc;
	while (!gcusermgr.checkTel(temc)) {
		cout << "����������绰��" << endl;
		cin >> temc;
	}
	temUser.setTel(temc);
	cout << "�������ַ��" << endl;
	cin >> temc;
	temUser.setAddress(temc);
	return temUser;
}
int choice() {
	cout << "������Ҫִ�еĹ���" << endl;
	cout << "1.��ʾ�����˵�����" << endl;
	cout << "2.��ѯָ������" << endl;
	cout << "3.����µ�����" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		gcusermgr.showName();
		break;
	case 2: {
		cout << "������Ҫ��ѯ�Ķ��������" << endl;
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
		cout << "��ӭʹ����־�ϵ�ͨѶ¼" << endl;
		if (choice() == 0)
			break;
		system("pause");
	}
	return 0;
}